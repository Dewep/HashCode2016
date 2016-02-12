#include "RoundIO.hpp"
#include "Solution.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

RoundIO round_io;

int distance(int r1, int c1, int r2, int c2) {
    return sqrt(pow(r1 - r2, 2) + pow(c1 - c2, 2));
}

int calc_nb_turn(int distance_to_go) {
    return ceil(distance_to_go);
}

int distance_in_turn(int r1, int c1, int r2, int c2) {
    return calc_nb_turn(distance(r1, c1, r2, c2));
}

struct Compare
{
    int r;
    int c;
    Compare(int row, int col) {
        r = row;
        c = col;
    }
    bool operator() (const Warehouse &a, const Warehouse &b) {
        return distance(r, c, a.row, a.column) < distance(r, c, b.row, b.column);
    }
    bool operator() (const Order &a, const Order &b) {
        if (a.isStarted() && !b.isStarted()) {
            return true;
        }
        if (!a.isStarted() && b.isStarted()) {
            return false;
        }
        //return compute_turns_necessary(a, r, c) < compute_turns_necessary(b, r, c);
        if (a.nb_items < b.nb_items) {
            return true;
        }
        if (a.nb_items > b.nb_items) {
            return false;
        }
        return distance(r, c, a.row, a.column) < distance(r, c, b.row, b.column);
    }
};

std::vector<Warehouse> BestWarehouses(int r, int c) {
    std::vector<Warehouse> whs;
    for (int i = 0; i < round_io.nb_warehouses; ++i) {
        whs.push_back(round_io.warehouses[i]);
    }
    Compare comp(r, c);
    std::sort(whs.begin(), whs.end(), comp);
    return whs;
}

std::vector<Order> BestOrders(int r, int c) {
    std::vector<Order> orders;
    for (int i = 0; i < round_io.nb_orders; ++i) {
        orders.push_back(round_io.orders[i]);
    }
    Compare comp(r, c);
    std::sort(orders.begin(), orders.end(), comp);
    return orders;
}

bool drone_execute(Solution &s, int d) {
    std::vector<Order> orders = BestOrders(round_io.drones[d].row, round_io.drones[d].column);
    for (auto ord: orders) {
        int o = ord.id;
        for (int io = 0; io < round_io.orders[o].nb_items; io++) {
            if (round_io.orders[o].items[io] != -1) {
                std::vector<Warehouse> whs = BestWarehouses(round_io.drones[d].row, round_io.drones[d].column);
                for (auto wh: whs) {
                    int w = wh.id;
                    if (round_io.warehouses[w].nb_products[round_io.orders[o].items[io]] > 0) {
                        int t_count = calc_nb_turn(distance(round_io.drones[d].row, round_io.drones[d].column, round_io.warehouses[w].row, round_io.warehouses[w].column));
                        t_count += calc_nb_turn(distance(round_io.warehouses[w].row, round_io.warehouses[w].column, round_io.orders[o].row, round_io.orders[o].column));
                        t_count += 5;
                        if (round_io.drones[d].turns > t_count) {
                            int number = 1;
                            bool more_possible = true;
                            while (more_possible) {
                                more_possible = false;
                                if (round_io.warehouses[w].nb_products[round_io.orders[o].items[io]] > number) {
                                    if (round_io.products[round_io.orders[o].items[io]].weight * (number + 1) < round_io.nb_max_payload) {
                                        for (int io2 = io + 1; io2 < round_io.orders[o].nb_items; io2++) {
                                            if (round_io.orders[o].items[io] == round_io.orders[o].items[io2]) {
                                                number++;
                                                round_io.orders[o].items[io2] = -1;
                                                more_possible = true;
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                            s.load(d, w, round_io.orders[o].items[io], number);
                            s.deliver(d, o, round_io.orders[o].items[io], number);
                            round_io.drones[d].row = round_io.orders[o].row;
                            round_io.drones[d].column = round_io.orders[o].column;
                            round_io.drones[d].turns -= t_count;
                            round_io.warehouses[w].nb_products[round_io.orders[o].items[io]] -= number;
                            round_io.orders[o].items[io] = -1;
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

int main(int argc, char **argv) {
    Solution s;
    bool finished = false;
    while (!finished) {
        finished = true;
        for (int d = 0; d < round_io.nb_drones; d++) {
            bool res = drone_execute(s, d);
            if (res) {
                finished = false;
            }
        }
    }
    s.save(argc, argv);
    return 0;
}
