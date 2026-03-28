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
    virtual ~State() {}
};

class Context
{
private:
    State *state;

public:
    Context(State *state) { state = state; }
    void setState(State *state);
    void request();
    ~Context() {}
};

class StateItemSelected : public ::State
{
public:
    void stateHandle() override;
    ~StateItemSelected() {}
};

class StateItemDispense : public ::State
{
public:
    void stateHandle() override;
    ~StateItemDispense() {}
};

void testStatePattern();

#endif