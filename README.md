[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://github.com/jfcarocota/sfml-gameengine/blob/main/LICENSE) 
[![Made With - SFML](https://img.shields.io/badge/Made_With-SFML-2ea44f?logo=%238CC445)](https://www.sfml-dev.org/index.php)
[![Made With - Box2D](https://img.shields.io/static/v1?label=Made+With&message=Box2D&color=%23a72e2f)](https://box2d.org/documentation/md__d_1__git_hub_box2d_docs__f_a_q.html)
[![Made With - Json-cpp](https://img.shields.io/static/v1?label=Made+With&message=Json-cpp&color=blue)](https://github.com/open-source-parsers/jsoncpp)

# Description

This is an opensource project that I use to teach my students C++ and game development. All the purposes are for education. The technology used are totally opensource.

# Set up and download the project

The first step is get all de stuffs needed for running the project. The core of this is [SFML](https://www.sfml-dev.org/download/sfml/2.5.1/) , a computer graphics library base on OpenGL API. Also is not necessary download it beacause is in included the engine, but if you want to test SFML, we recommend [GCC 7.3.0 MinGW (SEH) - 64-bit](https://www.sfml-dev.org/files/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit.zip) version because the project use the compiler g++ by GNU how is included with MinGW.

Depending of your OS you are going to need download a version of the compiler g++ by [MinGW](https://www.mingw-w64.org/downloads/). This project was created on windows so we recommend donwload directly the project of MinGW or use MSYS2 who contains MinGW inside. Next step is config you Enviroment Variable for g++ inside de binaries directory of your MinGW Install folder.

Once all this steps are done just downloads or clone the project and run it using visual studio code. Be sure of the a look at task.json file, who contains all the configs for build and run the project with g++ console commands.

`git clone https://github.com/jfcarocota/sfml-gameengine.git`

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
