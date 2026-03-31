#ifndef OPERATOROVERLOADING_HPP
#define OPERATOROVERLOADING_HPP

class Vector
{
public:
    int x, y;
    Vector() {};
    Vector(int x, int y) : x(x), y(y) {};

    /**
     * @brief Overloads the addition operator for Vector objects.
     *
     * This function allows two Vector objects to be added together using the + operator.
     * The result is a new Vector whose x and y components are the sums of the
     * corresponding components of the two input vectors.
     *
     * @param obj The Vector object to add to the current object.
     * @return Vector A new Vector object containing the sum of the two vectors.
     *
     * Example:
     * @code
     * Vector v1(3, 5);
     * Vector v2(10, 9);
     * Vector result = v1 + v2; // result contains (13, 14)
     * @endcode
     */
    Vector operator+(Vector);
};

/**
 * @brief Tests the overloaded addition operator for Vector objects.
 *
 * This function demonstrates the usage of the overloaded + operator by creating
 * two Vector objects, adding them together, and displaying the result.
 *
 * @return void
 *
 * Example Output:
 * @code
 * val : 13,14
 * @endcode
 */
void testOperatorOverloading();

#endif