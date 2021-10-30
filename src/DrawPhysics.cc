#include "DrawPhysics.hh"

DrawPhysics::DrawPhysics(sf::RenderWindow*& window)
{
  this->window = window;
}

DrawPhysics::~DrawPhysics()
{
}

/// Draw a closed polygon provided in CCW order.
void DrawPhysics::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
  sf::ConvexShape convexShape{sf::ConvexShape(vertexCount)};
  for(int i{}; i < vertexCount; i++)
  {
    sf::Vector2f transformedVector{DrawPhysics::B2VecToSFVec(vertices[i])};
    convexShape.setPoint(i, sf::Vector2f(std::floor(transformedVector.x), std::floor(transformedVector.y)));
  }

  //draw polygon
  convexShape.setOutlineColor(DrawPhysics::GLColorToSFML(color));
  convexShape.setFillColor(sf::Color::Transparent);
  convexShape.setOutlineThickness(-2.f);
  window->draw(convexShape);
}

/// Draw a solid closed polygon provided in CCW order.
void DrawPhysics::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
  sf::ConvexShape convexShape{sf::ConvexShape(vertexCount)};
  for(int i{}; i < vertexCount; i++)
  {
    sf::Vector2f transformedVector{DrawPhysics::B2VecToSFVec(vertices[i])};
    convexShape.setPoint(i, sf::Vector2f(std::floor(transformedVector.x), std::floor(transformedVector.y)));
  }

  //draw polygon
  convexShape.setOutlineColor(DrawPhysics::GLColorToSFML(color));
  convexShape.setFillColor(DrawPhysics::GLColorToSFML(color, 60.f));
  convexShape.setOutlineThickness(-2.f);
  window->draw(convexShape);
}

/// Draw a circle.
void DrawPhysics::DrawCircle(const b2Vec2& center, float radius, const b2Color& color)
{
  
}

/// Draw a solid circle.
void DrawPhysics::DrawSolidCircle(const b2Vec2& center, float radius, const b2Vec2& axis, const b2Color& color)
{

}

/// Draw a line segment.
void DrawPhysics::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color)
{

}

/// Draw a transform. Choose your own length scale.
void DrawPhysics::DrawTransform(const b2Transform& xf)
{

}

//Draw a point
void DrawPhysics::DrawPoint (const b2Vec2 &p, float size, const b2Color &color)
{

}