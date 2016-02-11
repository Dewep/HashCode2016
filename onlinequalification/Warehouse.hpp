#ifndef WAREHOUSE_HPP_
# define WAREHOUSE_HPP_

#include <iostream>
#include <string>
#include <stdexcept>

struct Warehouse {
    int row;
    int column;
    int *nb_products;

    void add_product(int product_id, int quantity) {
        nb_products[product_id] += quantity;
    }

    void remove_product(int product_id, int quantity) {
        nb_products[product_id] -= quantity;
        if (nb_products[product_id] < 0) {
            throw std::runtime_error("QUANTITY CANNOT BE NEGATIVE");
        }
    }
};

#endif /* !WAREHOUSE_HPP_ */
