#ifndef WAREHOUSE_HPP_
# define WAREHOUSE_HPP_

#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <list>
#include "Product.hpp"

struct Warehouse {
    int id;
    int row;
    int column;
    int *nb_products;
    int *nb_products_tmp;

    void add_product(int product_id, int quantity) {
        nb_products[product_id] += quantity;
    }

    void remove_product(int product_id, int quantity) {
        nb_products[product_id] -= quantity;
        if (nb_products[product_id] < 0) {
            throw std::runtime_error("QUANTITY CANNOT BE NEGATIVE");
        }
    }

    int search_items(std::list<int> &items, int nb_max_payload, Product *products) {
        int nb_load = 0;
        std::map<int, int> packets;
        for (auto i = items.begin(); i != items.end(); ++i) {
            if (packets.find(*i) == packets.end()) {
                packets[*i] = 1;
            } else {
                packets[*i] += 1;
            }
        }
        for (auto it = packets.begin(); it != packets.end(); ++it) {
            int nb_products_possible = nb_products[it->first];
            int weight_product = products[it->first].weight;
            int max_per_packet = nb_max_payload / weight_product;
            while (nb_products_possible > 0 && it->second > 0) {
                if (nb_products_possible < max_per_packet) {
                    max_per_packet = nb_products_possible;
                }
                nb_load++;
                it->second -= max_per_packet;
                nb_products_possible -= max_per_packet;
                for (int nb = 0; nb < max_per_packet; nb++) {
                    for (auto it2 = items.begin(); it2 != items.end(); ++it2) {
                        if (*it2 == it->first) {
                            items.erase(it2);
                            break;
                        }
                    }
                }
            }
        }
        return nb_load;
    }
};

#endif /* !WAREHOUSE_HPP_ */
