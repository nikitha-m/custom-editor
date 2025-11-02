#include "../include/editor.h"

#include <cstring>
#include <fstream>
#include <iostream>

#include "../include/file_operations.h"

Editor::Editor() {}

Editor::~Editor() {}

void Editor::run(std::string filename) {
  std::cout << "Welcome to my \"VIM\" text editor" << std::endl;

  FileOperations fileOperations;
  std::string path = "../src/" + filename;
  int lineNumber = 1;

  std::vector<std::string> buffer;

  std::string input;

  // check if file exists
  std::ifstream infile(path);
  if (!infile.good()) {
    // create file
    fileOperations.createFile(path);
  } else {
    lineNumber = fileOperations.readFromFile(path);
  }
  infile.close();

  while (true) {
    std::cout << lineNumber << ": ";
    std::getline(std::cin, input);
    if (input == "q") {
      break;
    }
    buffer.push_back(input);
    lineNumber++;
  }

  std::ofstream myfile(path, std::ios::app);
  for (size_t j = 0; j < buffer.size(); j++) {
    myfile << buffer[j] << std::endl;
  }
  myfile.close();
}
