#include "PaintingIO.hpp"
#include <iostream>

int main() {
    // Usage: ./hashcode2016 < data/file.in > data/file.out
    std::ios::sync_with_stdio(false);
    PaintingIO painting = PaintingIO();

    std::cerr << "getRows: " << painting.rows << std::endl;
    std::cerr << "getColumns: " << painting.columns << std::endl;
    std::cerr << "Second row: " << painting.cells[1] << std::endl;
    std::cerr << "Cell [3;3]: " << painting.cells[3][3] << std::endl;

    painting.addPaintSquare(2, 3, 1);
    painting.addEraseCell(2, 3);
    painting.addPaintSquare(0, 4, 0);
    painting.addPaintSquare(4, 2, 0);

    return painting.writeOutput();
}
