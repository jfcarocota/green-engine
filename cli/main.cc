#include<iostream>
#include<string>
#include<fstream>


void ErrorCommand();
void ValidateCommand(std::string& command, char* argv[]);

int main(int argc, char* argv[])
{
  std::string command{argv[1]};

  switch (argc)
  {
  case 3:
    ValidateCommand(command, argv);
    break;

  default:
    ErrorCommand();
    break;
  }
  return 0;
}

void ErrorCommand()
{
  std::cout << "command not recognized" << std::endl;
}

void ValidateCommand(std::string& command, char* argv[])
{
  std::string REPLACE_WORD{"EntityTemplate"};

  if(command.compare("gameobject"))
  {
    std::ofstream* writer{new std::ofstream()};
    std::ifstream* reader{new std::ifstream()};
    reader->open("cli/templates/gameobject.template");

    std::string scriptName{argv[2]};
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
}
