struct Order {
    int id;
    int row;
    int column;
    int nb_items;
    int *items;
    int available;

    bool isStarted() const {
        for (int i = 0; i < nb_items; i++) {
            if (items[i] == -1) {
                return true;
            }
        }
        return false;
    }
};
