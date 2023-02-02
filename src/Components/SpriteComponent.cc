#include "Components/SpriteComponent.hh"
#include "Components/EntityManager.hh"

SpriteComponent::SpriteComponent(const char* textureUrl, unsigned int col, unsigned int row)
{
  this->textureUrl = textureUrl;
  this->col = col;
  this->row = row;

  texture = sf::Texture();
  texture.loadFromFile(textureUrl);
}

void SpriteComponent::Initialize()
{
  transform = owner->GetComponent<TransformComponent>();

  sprite = sf::Sprite(texture, sf::IntRect(col * transform->GetWidth(), row * transform->GetHeight(),
  transform->GetWidth(), transform->GetHeight()));

  sprite.setPosition(transform->GetPosition());
  sprite.setScale(sf::Vector2f(transform->GetScale(), transform->GetScale()));
  sprite.setColor(sf::Color::White);
  sprite.setOrigin(transform->GetWidth() / 2, transform->GetHeight() / 2);
}

SpriteComponent::~SpriteComponent()
{
}

void SpriteComponent::Update(float& deltaTime)
{
  if(&transform)
  {
    sprite.setPosition(transform->GetPosition());
  }
}

void SpriteComponent::Render(sf::RenderWindow& window)
{
  window.draw(sprite);
}

void SpriteComponent::SetFlipTexture(bool flipTexture)
{
  this->flipTexture = flipTexture;
  sprite.setScale(flipTexture ? -transform->GetScale(): transform->GetScale(), transform->GetScale());
}

bool SpriteComponent::GetFliptexture() const
{
  return flipTexture;
}

sf::Vector2f SpriteComponent::GetOrigin() const
{
  return sprite.getOrigin();
}

void SpriteComponent::RebindRectTexture(int col, int row, float width, float height)
{
  sprite.setTextureRect(sf::IntRect(col, row, width, height));
}
