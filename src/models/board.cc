/*  Project name    : A2BF
 *  File name       : models/board.cc
 *
 *  2024 Keitaro Kamo (nekoyade)
 *
 */

#include <string>

#include <models/board.h>

namespace a2bf {

std::string Board::ToString() const {
    std::string repr;
    for (int i = 0; i < kBoardHeight; ++i) {
        for (int j = 0; j < kBoardWidth; ++j) {
            repr.append(cells_[i][j].ToString());
        }
        repr.append("\n");
    }
    return repr;
}

}  // namespace a2bf
