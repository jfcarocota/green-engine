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
    std::cout << "Creating a script type GameObject: " << scriptName << ".hh" << std::endl;

    writer->open("include/" + scriptName + ".hh");
    std::string currentLine{};
    while(std::getline(*reader, currentLine))
    {
      size_t pos = currentLine.find(REPLACE_WORD);
      if (pos != std::string::npos)
      {
        currentLine.replace(pos, REPLACE_WORD.length(), scriptName);
      }
      *writer << currentLine << '\n';
    }
    //std::filebuf* fileBuffer = reader->rdbuf();
    //std::string fileData{std::string((std::istreambuf_iterator<char>(*reader)), std::istreambuf_iterator<char>())};
    //std::replace(fileData.begin(), fileData.end(),REPLACE_WORD, scriptName);

    //*writer << reader->rdbuf();

    writer->close();
    reader->close();

    //reader->open("include/" + scriptName + ".hh");

    delete writer;
    delete reader;
  }
}
