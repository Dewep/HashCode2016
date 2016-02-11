#include "RoundIO.hpp"
#include "Solution.hpp"
#include <iostream>
#include <vector>

std::vector<Warehouse> ClosestWarehouses(Warehouse *warehouses, int nb_warehouses, int *r, int *c);
std::vector<Warehouse> BestWarehouses(Order order, Warehouse *warehouses, int nb_warehouses, int *r, int *c);
//int calc_distance

RoundIO round_io;

//std::list<warehouse> find_warehouse()

int main(int argc, char **argv) {
    // Usage: ./hashcode2016 busy_day < data/file.in
    std::ios::sync_with_stdio(false);


    std::cerr << "nb_rows: " << round_io.nb_rows << std::endl;
    std::cerr << "nb_columns: " << round_io.nb_columns << std::endl;
    std::cerr << "nb_drones: " << round_io.nb_drones << std::endl;
    std::cerr << "nb_turns: " << round_io.nb_turns << std::endl;
    std::cerr << "nb_max_payload: " << round_io.nb_max_payload << std::endl;
    std::cerr << "nb_products: " << round_io.nb_products << std::endl;
    std::cerr << "nb_warehouses: " << round_io.nb_warehouses << std::endl;
    std::cerr << "nb_orders: " << round_io.nb_orders << std::endl;


    int r = round_io.warehouses[0].row;
    int c = round_io.warehouses[0].column;
    std::vector<Warehouse> whs = ClosestWarehouses(round_io.warehouses, round_io.nb_warehouses, &r, &c);
    for (auto w: whs)
    {
        std::cout << "wharehouse r(" << w.row << "), c(" << w.column << ")" << std::endl;
    }
    std::cout << "---------------" << std::endl;
    whs = BestWarehouses(round_io.orders[0], round_io.warehouses, round_io.nb_warehouses, &r, &c);
    for (auto w: whs)
    {
        std::cout << "wharehouse r(" << w.row << "), c(" << w.column << ")" << std::endl;
    }


    return 0;

    for (int turn = 0; turn < round_io.nb_turns; turn++)
    {
        // drone first ou order first ?
        for (int drone = 0; drone < round_io.nb_drones; drone++)
        {



            if (round_io.drones[drone].is_available())
            {
                // sort round_io.orders in order to get best score
                for (int order = 0; order < round_io.nb_orders; order++)
                {

                }
            }
            else
            {
                //round_io.drones[drone].execute(turn);
            }

            //round_io.drones[drone]

        }
    }


/*    for (int turn = 0; turn < round_io.nb_turns; turn++)
    {
        // drone first ou order first ?
        for (int drone = 0; drone < round_io.nb_drones; drone++)
        {
            if (round_io.drones[drone].is_available())
            {
                // sort round_io.orders in order to get best score
                for (int order = 0; order < round_io.nb_orders; order++)
                {

                }
            }
            else
            {
                round_io.drones[drone].execute(turn);
            }

            //round_io.drones[drone]
            
        }
    }
*/
    /*for (int p = 0; p < round_io.nb_products; p++) {
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
    }*/

    Solution solution;
    solution.load(0, 0, 0, 1);
    solution.load(0, 0, 1, 1);
    solution.deliver(0, 0, 0, 1);
    solution.load(0, 1, 2, 1);
    solution.deliver(0, 0, 2, 1);
    solution.load(1, 1, 2, 1);
    solution.deliver(1, 2, 2, 1);
    solution.load(1, 0, 0, 1);
    solution.deliver(1, 1, 0, 1);
    solution.score = 987;
    solution.save(argc, argv);

    return 0;
}
