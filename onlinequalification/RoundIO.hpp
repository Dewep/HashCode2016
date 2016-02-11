#ifndef ROUND_IO_HPP_
# define ROUND_IO_HPP_

#include <iostream>
#include <list>
#include <string>
#include <sstream>

struct RoundIO {
    int rows;
    int columns;
    char **cells;

    RoundIO() {
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
    void addXXXXXXXXXX(int a, int b, int c) {
        std::ostringstream os;
        os << "PAINT_SQUARE " << a << " " << b << " " << c;
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

#endif /* !ROUND_IO_HPP_ */
