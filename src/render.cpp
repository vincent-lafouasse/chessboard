#include <fstream>
#include <sstream>
#include <string>

std::string load_svg(std::string path) {
  std::ifstream file_stream(path);
  std::stringstream buffer;
  buffer << file_stream.rdbuf();
  return buffer.str();
}
