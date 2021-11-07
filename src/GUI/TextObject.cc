#include "GUI/TextObject.hh"

TextObject::TextObject(std::string fontUrl, int size, sf::Color color, sf::Uint32 style)
{
  this->fontUrl = fontUrl;
  this->size = size;
  this->color = color;

  font->loadFromFile(fontUrl);
  text = new sf::Text(fontUrl, *font, size);
  text->setFillColor(color);
  text->setStyle(style);
}

TextObject::TextObject(std::string fontUrl, int size, sf::Color color, sf::Uint32 style, std::string textStr)
{
  this->fontUrl = fontUrl;
  this->size = size;
  this->color = color;
  this->textStr = textStr;

  font->loadFromFile(fontUrl);
  text = new sf::Text(fontUrl, *font, size);
  text->setFillColor(color);
  text->setStyle(style);
  text->setString(textStr);
}

TextObject::~TextObject()
{
}

void TextObject::SetTextStr(std::string textStr)
{
  this->textStr = textStr;
  text->setString(textStr);
}

sf::Text* TextObject::GetText() const
{
  return text;
}