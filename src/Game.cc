#include "CommonHeaders.hh"
#include "TileGroup.hh"
#include "Components/EntityManager.hh"
#include "Components/TransformComponent.hh"
#include "Components/SpriteComponent.hh"
#include "Components/RigidBodyComponent.hh"
#include "Components/AnimatorComponent.hh"
#include "Movement.hh"
#include "FlipSprite.hh"
#include "Components/Entity.hh"

EntityManager entityManager;

TextObject* textObj1{new TextObject(ASSETS_FONT_ARCADECLASSIC, 14, sf::Color::White, sf::Text::Bold)};

sf::Clock* gameClock{new sf::Clock()};
float deltaTime{};

std::vector<Entity*> activeEntities = std::vector<Entity*>();
std::vector<Entity*> inactiveEntities = std::vector<Entity*>();

TileGroup* tileGroup{};
Tile* tile1{};

uint32 flags{};
    //flags += b2Draw::e_aabbBit;
    //flags += b2Draw::e_shapeBit;
    //flags += b2Draw::e_centerOfMassBit;
    //flags += b2Draw::e_pairBit;
    //flags += b2Draw::e_jointBit;

Animation* lightIdle{};

Game::Game()
{
  window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_NAME);
  event = new sf::Event();
  gravity = new b2Vec2(0.f, 0.f);
  world = new b2World(*gravity);
  drawPhysics = new DrawPhysics(window);

  tileGroup = new TileGroup(window, 12, 12, ASSETS_MAPS, 4.f, 16, 16, ASSETS_TILES);

  Entity& hero{entityManager.AddEntity("hero")};
  Entity& candle1{entityManager.AddEntity("candle")};
  Entity& chest1{entityManager.AddEntity("chest")};
  Entity& chest2{entityManager.AddEntity("chest")};

  hero.AddComponent<TransformComponent>(500.f, 300.f, 16.f, 16.f, 4.f);
  hero.AddComponent<SpriteComponent>(ASSETS_SPRITES, 0, 5);
  hero.AddComponent<RigidBodyComponent>(world, b2BodyType::b2_dynamicBody, 1, 0, 0, 0.f, true, (void*) &hero);
  hero.AddComponent<AnimatorComponent>();
  hero.AddComponent<Movement>(200.f);
  hero.AddComponent<FlipSprite>();

  candle1.AddComponent<TransformComponent>(500.f, 500.f, 16.f, 16.f, 4.f);
  candle1.AddComponent<SpriteComponent>(ASSETS_SPRITES, 0, 5);
  candle1.AddComponent<RigidBodyComponent>(world, b2BodyType::b2_staticBody, 1, 0, 0, 0.f, true, (void*) &candle1);
  AnimatorComponent& candle1Animator = candle1.AddComponent<AnimatorComponent>();
  candle1Animator.AddAnimation("idle", AnimationClip("assets/animations/candle/idle.json"));

  chest1.AddComponent<TransformComponent>(300.f, 500.f, 16.f, 16.f, 4.f);
  chest1.AddComponent<SpriteComponent>(ASSETS_SPRITES, 6, 1);
  chest1.AddComponent<RigidBodyComponent>(world, b2BodyType::b2_staticBody, 1, 0, 0, 0.f, true, (void*) &chest1);

  chest2.AddComponent<TransformComponent>(300.f, 300.f, 16.f, 16.f, 4.f);
  chest2.AddComponent<SpriteComponent>(ASSETS_SPRITES, 6, 1);
  chest2.AddComponent<RigidBodyComponent>(world, b2BodyType::b2_staticBody, 1, 0, 0, 0.f, true, (void*) &chest2);

  contactEventManager = new ContactEventManager();
}

Game::~Game()
{
}

void Game::Initialize()
{
  flags += b2Draw::e_shapeBit;
  world->SetDebugDraw(drawPhysics);
  drawPhysics->SetFlags(flags);
  world->SetContactListener(contactEventManager);

  textObj1->SetTextStr("Hello game engine");
  MainLoop();
}

void Game::UpdatePhysics()
{
  world->ClearForces();
  world->Step(deltaTime, 8, 8);
}

void Game::Update()
{
  deltaTime = gameClock->getElapsedTime().asSeconds();
  gameClock->restart();

  entityManager.Update(deltaTime);
}

void Game::MainLoop()
{
  while (window->isOpen())
  {
    while(window->pollEvent(*event))
    {
      if(event->type == sf::Event::Closed)
      {
        window->close();
      }
    }

    UpdatePhysics();
    Input();
    Update();
    Render();
  }
  Destroy();
}

void Game::Render()
{
  window->clear(sf::Color::Black);

  window->draw(*textObj1->GetText());
  tileGroup->Draw();
  entityManager.Render(*window);
  world->DebugDraw();
  window->display();
}

//Keyboard, joysticks, etc.
void Game::Input()
{

}

void Game::Destroy()
{
  delete window;
  delete event;
}