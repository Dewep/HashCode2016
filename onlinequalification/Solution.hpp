#ifndef SOLUTION_HPP_
# define SOLUTION_HPP_

#include <iostream>
#include <list>
#include <string>
#include <sstream>

struct Solution {
    std::list<std::string> commands;

    Solution() {
    }

    void load(int drone_id, int warehouse, int product_id, int nb_items) {
        std::ostringstream os;
        os << drone_id << " L " << warehouse << " " << product_id << " " << nb_items;
        commands.push_back(os.str());
    }
    void unload(int drone_id, int warehouse, int product_id, int nb_items) {
        std::ostringstream os;
        os << drone_id << " L " << warehouse << " " << product_id << " " << nb_items;
        commands.push_back(os.str());
    }
    int writeOutput() {
        /*std::cout << commands.size() << std::endl;
        for (auto it = commands.begin(); it != commands.end(); ++it) {
            std::cout << *it << std::endl;
        }*/
        return 0;
    }
};

#endif /* !SOLUTION_HPP_ */
