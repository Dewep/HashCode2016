#ifndef SOLUTION_HPP_
# define SOLUTION_HPP_

#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <fstream>

struct Solution {
    std::list<std::string> commands;
    int score;

    Solution() {
        score = 0;
    }

    void load(int drone_id, int warehouse, int product_id, int nb_items) {
        std::ostringstream os;
        os << drone_id << " L " << warehouse << " " << product_id << " " << nb_items;
        commands.push_back(os.str());
    }
    void unload(int drone_id, int warehouse, int product_id, int nb_items) {
        std::ostringstream os;
        os << drone_id << " U " << warehouse << " " << product_id << " " << nb_items;
        commands.push_back(os.str());
    }
    void deliver(int drone_id, int order_id, int product_id, int nb_items) {
        std::ostringstream os;
        os << drone_id << " D " << order_id << " " << product_id << " " << nb_items;
        commands.push_back(os.str());
    }
    void wait(int drone_id, int nb_turns) {
        std::ostringstream os;
        os << drone_id << " W " << nb_turns;
        commands.push_back(os.str());
    }

    int save(int argc, char **argv) {
        if (argc > 1) {
            return save(argv[1]);
        }
        return save((char *) "res");
    }

    int save(char *basename) {
        std::ostringstream os;
        os << "output/" << basename << "_" << score << ".out";
        std::ofstream file;
        file.open(os.str());
        file << commands.size() << std::endl;
        for (auto it = commands.begin(); it != commands.end(); ++it) {
            file << *it << std::endl;
        }
        file.close();
        return 0;
    }
};

#endif /* !SOLUTION_HPP_ */
