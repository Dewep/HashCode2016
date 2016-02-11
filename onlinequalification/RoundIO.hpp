#ifndef ROUND_IO_HPP_
# define ROUND_IO_HPP_

#include <iostream>
#include <list>
#include <string>
#include <sstream>

struct Drone {
    int id;
    int row;
    int column;
};

struct Product {
    int id;
    int weight;
};

struct Warehouse {
    int row;
    int column;
    int *nb_products;
};

struct Order {
    int row;
    int column;
    int nb_items;
    int *items;
};

struct RoundIO {
    int nb_rows;
    int nb_columns;
    int nb_drones;
    int nb_turns;
    int nb_max_payload;
    int nb_products;
    int nb_warehouses;
    int nb_orders;
    Drone *drones;
    Product *products;
    Warehouse *warehouses;
    Order *orders;

    RoundIO() {
        std::cin >> nb_rows;
        std::cin >> nb_columns;
        std::cin >> nb_drones;
        drones = new Drone[nb_drones];
        for (int d = 0; d < nb_drones; d++) {
            drones[d].id = d;
            drones[d].row = 0;
            drones[d].column = 0;
        }
        std::cin >> nb_turns;
        std::cin >> nb_max_payload;
        std::cin >> nb_products;
        products = new Product[nb_products];
        for (int p = 0; p < nb_products; p++) {
            products[p].id = p;
            std::cin >> products[p].weight;
        }
        std::cin >> nb_warehouses;
        warehouses = new Warehouse[nb_warehouses];
        for (int w = 0; w < nb_warehouses; w++) {
            std::cin >> warehouses[w].row;
            std::cin >> warehouses[w].column;
            warehouses[w].nb_products = new int[nb_products];
            for (int wp = 0; wp < nb_products; wp++) {
                std::cin >> warehouses[w].nb_products[wp];
            }
        }
        std::cin >> nb_orders;
        orders = new Order[nb_orders];
        for (int o = 0; o < nb_orders; o++) {
            std::cin >> orders[o].row;
            std::cin >> orders[o].column;
            std::cin >> orders[o].nb_items;
            orders[o].items = new int[orders[o].nb_items];
            for (int oi = 0; oi < orders[o].nb_items; oi++) {
                std::cin >> orders[o].items[oi];
            }
        }
    }

    /*std::list<std::string> commands;
    void addXXXXXXXXXX(int a, int b, int c) {
        std::ostringstream os;
        os << "PAINT_SQUARE " << a << " " << b << " " << c;
        commands.push_back(os.str());
    }*/
    int writeOutput() {
        /*std::cout << commands.size() << std::endl;
        for (auto it = commands.begin(); it != commands.end(); ++it) {
            std::cout << *it << std::endl;
        }*/
        return 0;
    }
};

#endif /* !ROUND_IO_HPP_ */
