#include "RoundIO.hpp"
#include <iostream>

int main() {
    // Usage: ./hashcode2016 < data/file.in > data/file.out
    std::ios::sync_with_stdio(false);
    RoundIO round_io = RoundIO();

    std::cerr << "nb_rows: " << round_io.nb_rows << std::endl;
    std::cerr << "nb_columns: " << round_io.nb_columns << std::endl;
    std::cerr << "nb_drones: " << round_io.nb_drones << std::endl;
    std::cerr << "nb_turns: " << round_io.nb_turns << std::endl;
    std::cerr << "nb_max_payload: " << round_io.nb_max_payload << std::endl;
    std::cerr << "nb_products: " << round_io.nb_products << std::endl;
    std::cerr << "nb_warehouses: " << round_io.nb_warehouses << std::endl;
    std::cerr << "nb_orders: " << round_io.nb_orders << std::endl;
    for (int p = 0; p < round_io.nb_products; p++) {
        std::cerr << "product: " << round_io.products[p].id << " " << round_io.products[p].weight << std::endl;
    }
    for (int w = 0; w < round_io.nb_warehouses; w++) {
        std::cerr << "warehouse: " << round_io.warehouses[w].row << " " << round_io.warehouses[w].column << std::endl;
        for (int wp = 0; wp < round_io.nb_products; wp++) {
            std::cerr << "warehouse_product: " << round_io.warehouses[w].nb_products[wp] << std::endl;
        }
    }
    for (int o = 0; o < round_io.nb_orders; o++) {
        std::cerr << "order: " << round_io.orders[o].row << " " << round_io.orders[o].column << " " << round_io.orders[o].nb_items << std::endl;
        for (int oi = 0; oi < round_io.orders[o].nb_items; oi++) {
            std::cerr << "order_product: " << round_io.orders[o].items[oi] << std::endl;
        }
    }

    //round_io.addXXXXXXXXXX(1, 2, 3);

    return 0;
}
