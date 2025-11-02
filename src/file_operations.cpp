#include "../include/file_operations.h"

#include <fstream>
#include <iostream>
#include <string>

FileOperations::FileOperations() {}

FileOperations::~FileOperations() {}
void FileOperations::createFile(std::string filename) {
  std::ofstream outfile(filename);
  outfile.close();
}
void FileOperations::writeToFile(std::string filename, std::string content) {
  std::ofstream outfile(filename, std::ios::app);
  outfile << content << std::endl;
  outfile.close();
}
int FileOperations::readFromFile(std::string filename) {
  std::ifstream infile(filename);
  std::string line;
  int lineNumber = 1;
  while (std::getline(infile, line)) {
    std::cout << lineNumber << ": " << line << std::endl;
    lineNumber++;
  }
  infile.close();
  return lineNumber;
}
