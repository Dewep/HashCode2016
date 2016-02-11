#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "order.hpp"

int distance(int r1, int c1, int r2, int c2);
int calc_nb_turn(int distance_to_go);

struct Drone {
    int id;
    int row;
    int column;
    int status;
    int flying_start_turn;
    int flying_end_turn;
    int nb_items;
    int *items;
    Order *order;

    Drone() {

    }

    Drone(int r, int c) {
        row = r;
        column = c;
        order = nullptr;
        status = 0;
        flying_start_turn = 0;
        flying_end_turn = 0;
    }

    int is_empty() {
        return (nb_items == 0 ? true : false);
    }

    int is_available() {
        return (status == 0 ? true : false);
    }

    int has_order() {
        if (order != nullptr)
            return true;
        return false;
    }

    void set_order(Order *order) {
        order = order;
    }

    std::string execute(int turn) {
        std::string command = "";
        std::ostringstream os;
        //int time = 0;
        if (status == 0) { //empty drone available
            //Fly to warehouse and load it until the fullest

            //get the closest wh
            //Warehouse *wh = gotoClosestWarehouse(warehouses, nb_warehouses, row, column, &time);
            //get the max product type within the drone capacity for this order in this warehouse TODO
            //os << id << " L " << wh.id << " " << 0 << " " << 0;
            //set item and nb_items TODO
            command = os.str();
            //if the drone still has empty space load other products (stay at the same warehouse) otherwise the drone is ready to go
            status = 1; //ready to fly
        }
        else if (status == 1) { //ready to fly
            os << id << " D " << order->id << " " << 0 << " " << 0;
            //remove item and nb_items TODO
            command = os.str();
            flying_start_turn = turn;
            int dist= distance(row, column, order->row, order->column);
            flying_end_turn = calc_nb_turn(dist);
            status = 2; //flying;
        }
        else if (status == 2) { //Flying
            if (turn < flying_end_turn) //Keep flying if not arrived at destination
                status = 2;
            else { //deliver the remaining payload or drone is available
                if (is_empty())
                    status = 0;
                else {
                    os << id << " D " << order->id << " " << 0 << " " << 0;
                    //remove item and nb_items TODO
                    command = os.str();
                }
            }
        }
        return command;
    }
};
