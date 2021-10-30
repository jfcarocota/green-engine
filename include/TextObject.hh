#pragma once
#include<SFML/Graphics.hpp>

#include<iostream>
#include<string>

class TextObject
{
private:
  sf::Font* font{new sf::Font()};
  sf::Text* text{};
  std::string fontUrl;
  int size{};
  sf::Color color;
  std::string textStr{};
public:
  TextObject(std::string fontUrl, int size, sf::Color color, sf::Uint32 style);
  TextObject(std::string fontUrl, int size, sf::Color color, sf::Uint32 style, std::string textStr);
  ~TextObject();
  void SetTextStr(std::string textStr);
  sf::Text* GetText() const;
};