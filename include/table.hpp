#ifndef __TABLE_H__
#define __TABLE_H__


class Table {
    int dim_x;
    int dim_y;

public:
    Table(int dim_x, int dim_y) : dim_x(dim_x), dim_y(dim_y) {}

    bool is_on_table(int x, int y) {
        return x >= 0 && x < dim_x&& y >= 0 && y < dim_y;
    }
};

#endif // __TABLE_H__