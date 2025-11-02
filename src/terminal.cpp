// run in raw mode
#include "../include/terminal.h"

#include <termios.h>
#include <unistd.h>

#include <iostream>
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
// end of raw mode

void Terminal::endRawMode() {
  termios raw;
  tcgetattr(STDIN_FILENO, &raw);
  raw.c_lflag |= (ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}
// end of raw mode
void Terminal::getInput(std::string filename) {
  std::cout << " Writing to file: " << filename << std::endl;
  FileOperations fileOperations;
  int lineNumber = fileOperations.readFromFile(filename);

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
        fileOperations.writeToFile(filename, input);
        input.clear();
      }
      break;
    } else if (c == 'd') {
      // remove it from console as well
      std::cout << "\b \b" << std::flush;
      input.erase(input.begin() + input.length() - 1);
    } else if (c == '\n') {
      std::cout << std::endl;
      std::cout << lineNumber << ": " << std::flush;
      lineNumber++;
      fileOperations.writeToFile(filename, input);
      input.clear();
    }
    // up arrow
    else if (c == 'j') {
      std::cout << "up arrow" << std::flush;
      // move the to the previous line'
      

    }
    // down arrow
    else if (c == 'k') {
      std::cout << "down arrow" << std::flush;
    }
    /*
      delete letter
      remove the letter and like move the cursor to the left
      case 1:
        *hello:
          then go to the prev line
        he*llo:
          then js move the cursor the the left and delete 'e'

      case 2:
        delete randmoly from anywhere in the file
        go to the line
          {case 1}
      */
    else {
      std::cout << c << std::flush;
      input += c;
      ;
    }
  }
}
