#include "RoundIO.hpp"
#include <iostream>

int main() {
    // Usage: ./hashcode2016 < data/file.in > data/file.out
    std::ios::sync_with_stdio(false);
    RoundIO round_io = RoundIO();

    std::cerr << "nb_rows: " << round_io.nb_rows << std::endl;

    //round_io.addXXXXXXXXXX(1, 2, 3);

    return round_io.writeOutput();
}
