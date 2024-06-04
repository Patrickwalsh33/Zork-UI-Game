// movable.h
#ifndef MOVABLE_H
#define MOVABLE_H

class Movable {
public:
    // Move the object
    void move(int x, int y) {
        posX += x;
        posY += y;
    }

protected:
    int posX = 0;
    int posY = 0;
};

#endif // MOVABLE_H
