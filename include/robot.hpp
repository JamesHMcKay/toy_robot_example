
#ifndef __UTILS_H__
#define __UTILS_H__

class Robot {
    int x;
    int y;
    int direction;
    bool initialised;

public:
    Robot() {
        x = 0;
        y = 0;
        direction = 0;
        initialised = false;
    }

    void turn_left() {
        direction = (direction + 3) % 4;
    }

    void turn_right() {
        direction = (direction + 1) % 4;
    }

    void move() {
        switch (direction) {
        case 0:
            y++;
            break;
        case 1:
            x++;
            break;
        case 2:
            y--;
            break;
        case 3:
            x--;
            break;
        }
    }

    int x;
    int y;
    int direction;
};

#endif
