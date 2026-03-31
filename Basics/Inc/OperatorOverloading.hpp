#ifndef OPERATOROVERLOADING_HPP
#define OPERATOROVERLOADING_HPP

class Vector
{
public:
    int x, y;
    Vector() {};
    Vector(int x, int y) : x(x), y(y) {};
    // Overload + operator
    Vector operator+(Vector);
};

void testOperatorOverloading();

#endif