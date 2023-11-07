[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://github.com/jfcarocota/sfml-gameengine/blob/main/LICENSE) 
[![Made With - SFML](https://img.shields.io/badge/Made_With-SFML-2ea44f?logo=%238CC445)](https://www.sfml-dev.org/index.php)
[![Made With - Box2D](https://img.shields.io/static/v1?label=Made+With&message=Box2D&color=%23a72e2f)](https://box2d.org/documentation/md__d_1__git_hub_box2d_docs__f_a_q.html)
[![Made With - Json-cpp](https://img.shields.io/static/v1?label=Made+With&message=Json-cpp&color=blue)](https://github.com/open-source-parsers/jsoncpp)

# Green Engine

# Description

This is an opensource project that I use to teach my students C++ and game development. All the purposes are for education. The technology used are totally opensource.

# Setup and download the project

The first step is get all de stuffs needed for running the project. The core of this is [SFML](https://www.sfml-dev.org/download/sfml/2.5.1/) , a computer graphics library base on OpenGL API. Also is not necessary download it beacause is in included the engine, but if you want to test SFML, we recommend [GCC 7.3.0 MinGW (SEH) - 64-bit](https://www.sfml-dev.org/files/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit.zip) version because the project use the compiler g++ by GNU how is included with MinGW.

Depending of your OS you are going to need download a version of the compiler g++ by [MinGW](https://www.mingw-w64.org/downloads/). This project was created on windows so we recommend donwload directly the project of MinGW or use MSYS2 who contains MinGW inside. Next step is config you Enviroment Variable for g++ inside de binaries directory of your MinGW Install folder.

Once all this steps are done just downloads or clone the project and run it using visual studio code. Be sure of the a look at task.json file, who contains all the configs for build and run the project with g++ console commands.

`git clone https://github.com/jfcarocota/green-engine.git`

# Run the project

Just open the root project with vscode and press F5. If this is not working first check your paths in task.json and then run again.

![image-20230314180649770](https://user-images.githubusercontent.com/6539267/225180512-2786fb37-387d-46e6-bc9d-95bdddcd1758.png)

![image-20230314180816329](https://user-images.githubusercontent.com/6539267/225180538-3bd709bc-fd06-4c0f-abdb-8e0f8e643ab1.png)

Task file

```json
{
	"version": "2.0.0",
	"tasks": [
		{
			"type": "shell",
			"label": "build",
			"command": "g++",
			"args": [
				"-std=c++17",
				"-Iinclude",
				"-Isrc/dynamics",
				"-Isrc/lib_json",
				"src/Components/*.cc",
				"src/*cc",
				"src/GUI/*.cc",
				"src/collision/*.cpp",
				"src/common/*.cpp",
				"src/dynamics/*.cpp",
				"src/rope/*.cpp",
				"src/lib_json/*.cpp",
				"-o",
				"bin/game.exe",
				"lib/*.a"
			],
			"options": {
				"cwd": "${workspaceFolder}"
			},
			"problemMatcher": [
				"$gcc"
			],
			"group": "build",
			"detail": "compilador: \"C:\\Program Files (x86)\\mingw-w64\\mingw32\\bin\\g++.exe\""
		}
	]
}
```

Compare with your paths on your pc. Then this execute the next command.

`g++ -std=c++17 -Iinclude -Isrc/dynamics -Isrc/lib_json src/Components/*.cc src/*cc src/GUI/*.cc src/collision/*.cpp src/common/*.cpp src/dynamics/*.cpp src/rope/*.cpp src/lib_json/*.cpp -o bin/game.exe lib/*.a `

Result

![image-20230314181646666](https://user-images.githubusercontent.com/6539267/225180566-bb00bfec-9af7-41f7-8c2e-d66294822fa3.png)

You can try collect chest, touch candles or click the empty button. This all the basic behaviors of the engine.

# Use the Engine

The entinre engine is based on Entity Component System Paradigm, so understand ECS is important for create your own Components and use it with your entities.

You will notice the project comes with some basic sample components and assets, this are the basic game project stuffs when you run the executable file.

![image](https://user-images.githubusercontent.com/6539267/226077642-8dea029c-6c46-403c-98e4-b6136c587074.png)

For all example we recommend open Game.cc file.

## Create entities

The most basic way is just call the Entity class and generate them from entity manager (similar to factory pattern).

```cc
Entity& hero{entityManager.AddEntity("hero")};
```

## Create components

The components are scripts who lives inside an entity and represents a Behaviour for that entity. A component has an owner who represents the entity owner of the componet.

Example for a Movement behaviour Component who is used by Hero entity.

Header File
```cc
#pragma once
#include "Components/Component.hh"
#include "Components/RigidBodyComponent.hh"
#include "Components/AnimatorComponent.hh"
#include "Components/TransformComponent.hh"
#include "Components/SpriteComponent.hh"
#include "Components/AudioListenerComponent.hh"
#include "AudioClip.hh"

class Movement: public Component
{
private:
  float moveSpeed;
  RigidBodyComponent* rigidbody;
  AnimatorComponent* animator;
  TransformComponent* transform;
  SpriteComponent* sprite;
  AudioListenerComponent* audioListener;

  AudioClip stepsAudio;

  float stepsTimer{};
  float stepsDelay{};
public:
  Movement(float moveSpeed, float stepsDelay, AudioClip stepsAudio);
  ~Movement();
  void Initialize() override;
  void Update(float& deltaTime) override;
};
```
C file

```cc
#include "Movement.hh"
#include "InputSystem.hh"
#include "AnimationClip.hh"
#include "Components/EntityManager.hh"

Movement::Movement(float moveSpeed, float stepsDelay, AudioClip stepsAudio)
{
  this->moveSpeed = moveSpeed;
  this->stepsDelay = stepsDelay;
  this->stepsAudio = stepsAudio;
  stepsTimer = stepsDelay;
}

Movement::~Movement()
{
}

void Movement::Initialize()
{
  animator = owner->GetComponent<AnimatorComponent>();
  sprite = owner->GetComponent<SpriteComponent>();
  transform = owner->GetComponent<TransformComponent>();
  rigidbody = owner->GetComponent<RigidBodyComponent>();
  audioListener = owner->GetComponent<AudioListenerComponent>();

  animator->AddAnimation("idle", AnimationClip("assets/animations/player/idle.json"));
  animator->AddAnimation("walk", AnimationClip("assets/animations/player/walk.json"));
}

void Movement::Update(float& deltaTime)
{
  sf::Vector2 direction = InputSystem::Axis() * moveSpeed;

  rigidbody->AddVelocity(b2Vec2(direction.x, direction.y));

  if(std::abs(direction.x) > 0 || std::abs(direction.y) > 0)
  {
    if(audioListener)
    {
      stepsTimer += deltaTime;
      if(stepsTimer >= stepsDelay)
      {
        audioListener->PlayOneShot(stepsAudio, 4.f);
        stepsTimer = 0.f;
      }
    }
    animator->Play("walk");
  }
  else
  {
    animator->Play("idle");
  }
}
```

## Add compoents to entities

Here is an example of all the components inside the entity Hero.
```cc
hero.AddComponent<TransformComponent>(500.f, 300.f, 16.f, 16.f, 4.f);
  hero.AddComponent<SpriteComponent>(ASSETS_SPRITES, 0, 5);
  hero.AddComponent<RigidBodyComponent>(world, b2BodyType::b2_dynamicBody, 1, 0, 0, 0.f, true, (void*) &hero);
  hero.AddComponent<AnimatorComponent>();
  hero.AddComponent<AudioListenerComponent>();
  hero.AddComponent<Movement>(200.f, 0.28f, AudioClip("assets/audio/steps.ogg"));
  hero.AddComponent<FlipSprite>();
```
## Life cycle

All components have 3 basic behaviours. Initialize, Update and Render. As their names say is similar to Unity, Unreal or Godot. Initialize starts once at the beginning. Update fires once per frame and Render is Similar to Update but it's created for drawing stuffs and clear the screen, Update is just for motion and refeshing data.

Caro. J. (2023) Create Your Own Game Engine With C++ and ECS pattern
