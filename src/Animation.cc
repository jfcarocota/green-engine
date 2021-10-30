#include "Animation.hh"

Animation::Animation(){}

Animation::Animation(sf::Sprite* sprite, int startFrame, int endFrame, float animationDelay, int currentAnimation)
{
  this->sprite = sprite;
  this->startFrame = startFrame;
  this->endFrame = endFrame;
  this->animationDelay = animationDelay;
  this->currentAnimation = currentAnimation;
  animationIndex = startFrame;
}

void Animation::Play(float& deltaTime)
{
  currentTime += deltaTime;

  sprite->setTextureRect(sf::IntRect(animationIndex * sprite->getTextureRect().width,
  currentAnimation * sprite->getTextureRect().height, sprite->getTextureRect().width, 
  sprite->getTextureRect().height));

  if(currentTime >= animationDelay)
  {
    if(animationIndex == endFrame)
    {
      animationIndex = startFrame;
    }
    else
    {
      animationIndex++;
    }
    currentTime = 0.f;
  }
}

Animation::~Animation()
{
}