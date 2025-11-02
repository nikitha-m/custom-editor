#include <string>

class FileOperations {
 public:
  FileOperations();
  ~FileOperations();
  void createFile(std::string filename);
  void writeToFile(std::string filename, std::string content);
  int readFromFile(std::string filename);
};
