#include "../Inc/OperatorOverloading.hpp"
#include <iostream>

// Overloading + operator
Vector Vector::operator+(Vector obj)
{
    Vector temp;
    temp.x = x + obj.x;
    temp.y = y + obj.y;
    return temp;
}

void testOperatorOverloading()
{
    Vector v1(3, 5);
    Vector v2(10, 9);
    Vector val;
    val = v1 + v2;
    std::cout << "val : " << val.x << "," << val.y << std::endl;
}