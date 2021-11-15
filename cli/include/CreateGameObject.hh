#pragma once
#include<iostream>
#include<string>
#include<fstream>

void CreateGameObject(std::string assetName)
{
  std::string REPLACE_WORD{"EntityTemplate"};

    std::ofstream* writer{new std::ofstream()};
    std::ifstream* reader{new std::ifstream()};
    reader->open("cli/templates/gameobject.template");

    std::string scriptName{assetName};
    std::string script{};
    std::string currentLine{};


    writer->open("include/" + scriptName + ".hh");
    while(std::getline(*reader, currentLine))
    {
      size_t pos = currentLine.find(REPLACE_WORD);
      if (pos != std::string::npos)
      {
        currentLine.replace(pos, REPLACE_WORD.length(), scriptName);
      }

      *writer << currentLine << '\n';
    }

    writer->close();
    reader->close();

    reader->open("cli/templates/gameobject.implement");

    writer->open("src/" + scriptName + ".temp");
    while(std::getline(*reader, currentLine))
    {
      size_t pos = currentLine.find(REPLACE_WORD);
      if (pos != std::string::npos)
      {
        currentLine.replace(pos, REPLACE_WORD.length(), scriptName);
      }

      *writer << currentLine << '\n';
    }

    reader->close();
    writer->close();

    reader->open("src/" + scriptName + ".temp");
    writer->open("src/" + scriptName + ".cc");

    while(std::getline(*reader, currentLine))
    {
      size_t pos = currentLine.find(REPLACE_WORD);
      if (pos != std::string::npos)
      {
        currentLine.replace(pos, REPLACE_WORD.length(), scriptName);
      }

      *writer << currentLine << '\n';
    }

    reader->close();
    writer->close();

    std::string removeFile{"src/" + scriptName + ".temp"};
    std::remove(removeFile.c_str());

    delete writer;
    delete reader;
}