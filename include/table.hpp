#ifndef __TABLE_H__
#define __TABLE_H__

#include <iostream>
#include <stdexcept>

#include "position.hpp"

class Table {
    int dim_x;

    int dim_y;

public:
    Table(int dim_x, int dim_y) : dim_x(dim_x), dim_y(dim_y) {
        if (dim_x <= 0 || dim_y <= 0) {
            throw std::invalid_argument("Table dimensions must be positive!");
        }
    }

    bool is_on_table(Position p) {
        return p.x >= 0 && p.x < dim_x&& p.y >= 0 && p.y < dim_y;
    }
};

#endif // __TABLE_H__
