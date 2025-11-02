#include <stdio.h>

#include <iostream>
#include <string>

#include "../include/editor.h"
#include "../include/terminal.h"

int main(int argc, char* argv[]) {
  if (argc > 1) {
    std::string filename = argv[1];
    Terminal terminal;
    terminal.runInRawMode();
    terminal.getInput(filename);
    terminal.endRawMode();
  } else {
    std::cout << "No filename provided" << std::endl;
  }
  return 0;
}
