#include "render.h"
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "piece.h"

const std::string ASSETS_DIR = "./assets/";
const std::unordered_map<Piece, std::string> SVG_PATHS = {
    {PAWN | WHITE, ASSETS_DIR + "Chess_plt45.svg"},
    {BISHOP | WHITE, ASSETS_DIR + "Chess_blt45.svg"},
    {KNIGHT | WHITE, ASSETS_DIR + "Chess_nlt45.svg"},
    {ROOK | WHITE, ASSETS_DIR + "Chess_rlt45.svg"},
    {QUEEN | WHITE, ASSETS_DIR + "Chess_qlt45.svg"},
    {KING | WHITE, ASSETS_DIR + "Chess_klt45.svg"},
    {PAWN | BLACK, ASSETS_DIR + "Chess_pdt45.svg"},
    {BISHOP | BLACK, ASSETS_DIR + "Chess_bdt45.svg"},
    {KNIGHT | BLACK, ASSETS_DIR + "Chess_ndt45.svg"},
    {ROOK | BLACK, ASSETS_DIR + "Chess_rdt45.svg"},
    {QUEEN | BLACK, ASSETS_DIR + "Chess_qdt45.svg"},
    {KING | BLACK, ASSETS_DIR + "Chess_kdt45.svg"},
};

std::string load_svg(std::string path) {
  std::ifstream file_stream(path);
  std::stringstream buffer;
  buffer << file_stream.rdbuf();
  return buffer.str();
}
