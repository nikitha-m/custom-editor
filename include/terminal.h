#include <string>

class Terminal {
 public:
  Terminal();
  ~Terminal();
  void runInRawMode();
  void endRawMode();
  void getInput(std::string filename);
};
