#include "order.hpp"

struct Drone {
    int id;
    int row;
    int column;
    int available;
    Order *order;

    Drone() {

    }

    Drone(int r, int c) {
        row = r;
        column = c;
        order = nullptr;
        available = 1;
    }

    int is_available() {
        if (available != 0)
            return true;
        return false;
    }

    void set_availability(int available) {
        available = available;
    };

    int has_order() {
        if (order != nullptr)
            return true;
        return false;
    }

    void set_order(Order *order) {
        order = order;
    }

};
