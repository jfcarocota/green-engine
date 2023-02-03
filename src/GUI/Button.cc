#include "GUI/Button.hh"

Button::Button(TransformComponent& transform, float borderSize,
sf::Color fillColor, sf::Color borderColor, std::function<void()> onClickAction):
transform(transform)
{
  this->borderSize = borderSize;
  this->fillColor = fillColor;
  this->borderColor = borderColor;
  this->onClickAction = onClickAction;
}

Button::~Button()
{
}

void Button::SetTexture(std::string texturePath)
{
  if(&rectangleShape)
  {
    texture = sf::Texture();
    texture.loadFromFile(texturePath);
    rectangleShape.setTexture(&texture);
  }
}

void Button::Initialize()
{
  float posX{transform.GetPosition().x};
  float posY{transform.GetPosition().y};
  float width{transform.GetWidth()};
  float height{transform.GetHeight()};

  rectangleShape = sf::RectangleShape();
  rectangleShape.setPosition(posX, posY);
  rectangleShape.setSize(sf::Vector2f(width, height));
  rectangleShape.setFillColor(fillColor);
  rectangleShape.setOutlineColor(borderColor);
  rectangleShape.setOutlineThickness(borderSize);
}

void Button::OnClick()
{
  if(!clicked)
  {
    clicked = true;
    onClickAction();
  }
}

void Button::Update(float& deltaTime)
{

}

void Button::Render(sf::RenderWindow& window)
{
  window.draw(rectangleShape);
  sf::Vector2i mousePos = sf::Mouse::getPosition(window);//captura si estamos en el area de la venta de nuestor juego
  sf::Vector2f mouseTranslate = window.mapPixelToCoords(mousePos); // este captura cuanto se ha movido el mouse dentro de la ventana
  if(rectangleShape.getGlobalBounds().contains(mouseTranslate)) // si esa traslación fue sobre la forma de nuestro rectangulo
  {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
      if(onClickAction)
      {
        OnClick();
      }
    }
    else
    {
      clicked = false;
    }
  }
  else
  {
    clicked = false;
  }
}
