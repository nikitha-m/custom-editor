// run in raw mode
#include "../include/terminal.h"

#include <termios.h>
#include <unistd.h>

#include <iostream>
#include <map>
#include <ostream>

#include "../include/file_operations.h"

Terminal::Terminal() {}
Terminal::~Terminal() {}

void Terminal::runInRawMode() {
  termios raw;
  tcgetattr(STDIN_FILENO, &raw);
  raw.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void Terminal::endRawMode() {
  termios raw;
  tcgetattr(STDIN_FILENO, &raw);
  raw.c_lflag |= (ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}
void Terminal::getInput(std::string filename) {
  FileOperations fileOperations;
  int lineNumber = fileOperations.readFromFile(filename);

  std::map<int, std::string> buffer;

  if (lineNumber == 0) {
    fileOperations.createFile(filename);
  }
  char c = '\0';
  std::string input = "";
  std::cout << lineNumber << ": " << std::flush;
  lineNumber++;
  while (true) {
    read(STDIN_FILENO, &c, 1);
    if (c == 'q') {
      std::cout << c << std::flush;
      if (input.length() > 0) {
        buffer[lineNumber] = input;
        fileOperations.writeToFile(filename, buffer[lineNumber]);
        input.clear();
      }
      break;
    } else if (c == 'd') {
      std::cout << "\b \b" << std::flush;
      input.erase(input.begin() + input.length() - 1);
    } else if (c == '\n') {
      std::cout << std::endl;
      std::cout << lineNumber << ": " << std::flush;
      lineNumber++;
      buffer[lineNumber] = input;
      fileOperations.writeToFile(filename, buffer[lineNumber]);
      input.clear();
    } else if (c == 'j') {
      const char* back = "\033[1A";
      lineNumber--;
      input = buffer[lineNumber];
      write(STDOUT_FILENO, back, strlen(back));

    } else if (c == 'k') {
      std::cout << "down arrow" << std::flush;
    } else {
      std::cout << c << std::flush;
      input += c;
      buffer[lineNumber] = input;
    }
  }
}
