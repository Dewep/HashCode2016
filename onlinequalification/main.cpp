#include "RoundIO.hpp"
#include <iostream>

int main() {
    // Usage: ./hashcode2016 < data/file.in > data/file.out
    std::ios::sync_with_stdio(false);
    RoundIO round_io = RoundIO();

    std::cerr << "getRows: " << round_io.rows << std::endl;
    std::cerr << "getColumns: " << round_io.columns << std::endl;
    std::cerr << "Second row: " << round_io.cells[1] << std::endl;
    std::cerr << "Cell [3;3]: " << round_io.cells[3][3] << std::endl;

    //round_io.addXXXXXXXXXX(1, 2, 3);

    return round_io.writeOutput();
}
