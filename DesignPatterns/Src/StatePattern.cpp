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
    Context context;
    context.setState(new StateItemSelected());
    context.request();
    context.setState(new StateItemDispense());
    context.request();
}