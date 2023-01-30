#include "Components/SpriteComponent.hh"

SpriteComponent::SpriteComponent(const char* textureUrl, TransformComponent& transform, unsigned int col, unsigned int row):
transform(transform)
{
  this->textureUrl = textureUrl;
  this->col = col;
  this->row = row;

  texture = sf::Texture();
  texture.loadFromFile(textureUrl);
  sprite = sf::Sprite(texture, sf::IntRect(col * transform.GetWidth(), row * transform.GetHeight(), transform.GetWidth(), transform.GetHeight()));
  sprite.setPosition(transform.GetPosition());
  sprite.setScale(sf::Vector2f(transform.GetScale(), transform.GetScale()));
  sprite.setColor(sf::Color::White);
}

SpriteComponent::~SpriteComponent()
{
}

void SpriteComponent::Update(float& deltaTime)
{
  sprite.setPosition(transform.GetPosition());
}

void SpriteComponent::Render(sf::RenderWindow& window)
{
  window.draw(sprite);
}

void SpriteComponent::SetFlipTexture(bool flipTexture)
{
  this->flipTexture = flipTexture;
  sprite.setScale(flipTexture ? -transform.GetScale(): transform.GetScale(), transform.GetScale());
}

bool SpriteComponent::GetFliptexture() const
{
  return flipTexture;
}
