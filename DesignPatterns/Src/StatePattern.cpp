#include "../Inc/StatePattern.hpp"

void Context::setState(State *state)
{
    this->state = state;
}

void Context::request()
{
    state->stateHandle();
}

void StateItemSelected::stateHandle()
{
    std::cout << "state Item selected Handled" << std::endl;
}

void StateItemDispense::stateHandle()
{
    std::cout << "state Item sucecssfully dispensed" << std::endl;
}

void testStatePattern()
{
    Context context1(new StateItemSelected);
    context1.setState(new StateItemSelected());
    context1.request();
    context1.setState(new StateItemDispense());
    context1.request();
}