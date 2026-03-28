#ifndef STATEPATTERN_HPP
#define STATEPATTERN_HPP

#include <string>
#include <vector>
#include <iostream>
//  State Pattern

class State
{
public:
    virtual void stateHandle() = 0;
};

class Context
{
private:
    State *state;

public:
    void setState(State *state);
    void request();
};

class StateItemSelected : public ::State
{
public:
    void stateHandle();
};

class StateItemDispense : public ::State
{
public:
    void stateHandle();
};

void testStatePattern();

#endif