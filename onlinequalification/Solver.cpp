#include <cmath>
#include <list>
#include <algorithm>
#include "RoundIO.hpp"

int distance(int r1, int c1, int r2, int c2) {
  return sqrt(pow(r1 - r2, 2) + pow(c1 - c2, 2));
}

int calc_nb_turn(distance_to_go) {
    return ceil(distance_to_go);
}

/*
class compare
{
public:

    int r;
    int c;

    bool operator () (wharehouse a, wharehouse b)
    {
      return distance()
    }

};

int compare_whs(wharehouse a, wharehouse b)
{
    return distance()
}

Warehouse *gotoBestWarehouse(Warehouse *warehouses, int nb_warehouses, int *r, int *c, int *time) {
  std::list<Warehouse> whs;

  for (int i = 1; i < nb_warehouses; ++i) {
    whs.push_back(wharehouses[i]);
  }

  std::sort(whs.begin(), whs.end(), )

    Warehouse *w = warehouses;

  int pdist = distance(*r, *c, w->row, w->column);

  for (int i = 1; i < nb_warehouses; ++i) {
    int dist = distance(*r, *c, warehouses[i].row, warehouses[i].column);
    if (dist < pdist) {
      w = &warehouses[i];
      pdist = dist;
    }
  }
  *time += pdist;
  *r = w->row;
  *c = w->column;
  return w;
}
*/

Warehouse *gotoClosestWarehouse(Warehouse *warehouses, int nb_warehouses, int *r, int *c, int *time) {
  Warehouse *w = warehouses;
  int pdist = distance(*r, *c, w->row, w->column);

  for (int i = 1; i < nb_warehouses; ++i) {
    int dist = distance(*r, *c, warehouses[i].row, warehouses[i].column);
    if (dist < pdist) {
      w = &warehouses[i];
      pdist = dist;
    }
  }
  *time += pdist;
  *r = w->row;
  *c = w->column;
  return w;
}

int getScore(Drone *drone, Order *order, Warehouse *warehouses, int nb_warehouses, Product *products, int nb_products) {
  int time = 0;
  int drone_r = drone->row;
  int drone_c = drone->column;
  Warehouse *hand;
  std::list<int> items;
  for (int i = 0; i < order->nb_items; ++i) {
    items.push_front(order->items[i]);
  }

  while (!items.empty()) {
    hand = gotoClosestWarehouse(warehouses, nb_warehouses, &drone_r, &drone_c, &time);
    // fill drone (items, hand, &time)
    time += distance(drone_r, drone_c, order->row, order->column);
    // empty drone
  }
  return time;
  // get closest warehouse
  // fill drone to max
  // deliver
  // loop
}
