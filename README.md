This is an opensource project that I use to teach my students C++ and game development. All the purposes are for education. The thecnology used are totally opensource.

# Set up and download the project

The first step is get all de stuffs needed for running the project. The core of this is [SFML](https://www.sfml-dev.org/download/sfml/2.5.1/) , a computer graphics library base on OpenGL API. We recommend [GCC 7.3.0 MinGW (SEH) - 64-bit](https://www.sfml-dev.org/files/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit.zip) version because the project use the compiler g++ by GNU how is included with MinGW.

Depending of you OS your gonna need donwload a version of the compiler g++ by [MinGW](https://www.mingw-w64.org/downloads/). This project was created on windows so we recommend donwload directly the project of MinGW or use MSYS2 who contains MinGW inside. Next step is config you Enviroment Variable for g++ inside de binaries directory of your MinGW Install folder.

Once all this steps are done just downloads or clone the project and run it using visual studio code. Be sure of the a look at task.json file, who contains all the configs for build and run the project with g++ console commands.

`git clone https://github.com/jfcarocota/sfml-gameengine.git`

# Run the project

Just open the root project with vscode and press F5. If this is not working first check your paths in task.json and then run again.

![image-20230314180649770](C:\Users\Usuario\AppData\Roaming\Typora\typora-user-images\image-20230314180649770.png)

![image-20230314180816329](C:\Users\Usuario\AppData\Roaming\Typora\typora-user-images\image-20230314180816329.png)

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

![image-20230314181646666](C:\Users\Usuario\AppData\Roaming\Typora\typora-user-images\image-20230314181646666.png)

You can try collect chest, touch candles or click the empty button. This all the basic behaviors of the engine.