#ifndef PAINTING_IO_HPP_
# define PAINTING_IO_HPP_

#include <iostream>
#include <list>
#include <string>
#include <sstream>

struct PaintingIO {
    int rows;
    int columns;
    char **cells;

    PaintingIO() {
        std::cin >> rows;
        std::cin >> columns;
        cells = new char*[rows];
        for (int r = 0; r < rows; r++) {
            cells[r] = new char[columns];
            for (int c = 0; c < columns; c++) {
                std::cin >> cells[r][c];
            }
        }
    }

    std::list<std::string> commands;
    void addPaintSquare(int a, int b, int c) {
        std::ostringstream os;
        os << "PAINT_SQUARE " << a << " " << b << " " << c;
        commands.push_back(os.str());
    }
    void addEraseCell(int a, int b) {
        std::ostringstream os;
        os << "ERASE_CELL " << a << " " << b;
        commands.push_back(os.str());
    }
    int writeOutput() {
        std::cout << commands.size() << std::endl;
        for (auto it = commands.begin(); it != commands.end(); ++it) {
            std::cout << *it << std::endl;
        }
        return 0;
    }
};

#endif /* !PAINTING_IO_HPP_ */
