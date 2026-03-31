#ifndef STATEPATTERN_HPP
#define STATEPATTERN_HPP

#include <string>
#include <vector>
#include <iostream>

/**
 * @brief Pattern Implementation: State Pattern
 *
 * This implementation demonstrates the State Pattern, a behavioral design pattern
 * that allows an object to alter its behavior when its internal state changes.
 * The object will appear to change its class.
 *
 * Key Components:
 * - Context: Maintains the current state and delegates requests to the state object.
 * - State (Abstract): Defines the interface for state-specific behavior.
 * - Concrete States: Implement state-specific behavior.
 */

/**
 * @brief Abstract state interface.
 *
 * Defines the interface for state-specific behavior.
 */
class State
{
public:
    /**
     * @brief Handles behavior specific to the current state.
     *
     * @return void
     */
    virtual void stateHandle() = 0;
    virtual ~State() {}
};

/**
 * @brief Context that maintains and delegates to the current state.
 *
 * The Context class maintains a current state and delegates requests to it.
 * It allows changing the state to alter behavior.
 */
class Context
{
private:
    State *state;

public:
    explicit Context(State *state) : state(state) {}

    /**
     * @brief Sets the new state for the context.
     *
     * This function changes the current state of the context. The context will
     * use the new state's behavior for subsequent requests.
     *
     * @param state Pointer to the new State object.
     * @return void
     */
    void setState(State *state);

    /**
     * @brief Delegates a request to the current state.
     *
     * This function forwards the request to the current state's handler, which
     * determines the behavior based on the current state of the context.
     *
     * @return void
     */
    void request();
    ~Context() {}
};

/**
 * @brief Concrete state for "Item Selected" condition.
 *
 * Implements the behavior when an item has been selected.
 */
class StateItemSelected : public ::State
{
public:
    /**
     * @brief Handles the "Item Selected" state.
     *
     * This function implements the behavior when an item has been selected.
     * It outputs a confirmation message indicating the item selection state.
     *
     * @return void
     */
    void stateHandle() override;
    ~StateItemSelected() {}
};

/**
 * @brief Concrete state for "Item Dispensed" condition.
 *
 * Implements the behavior when an item has been successfully dispensed.
 */
class StateItemDispense : public ::State
{
public:
    /**
     * @brief Handles the "Item Dispensed" state.
     *
     * This function implements the behavior when an item has been successfully dispensed.
     * It outputs a confirmation message indicating the item dispensing state.
     *
     * @return void
     */
    void stateHandle() override;
    ~StateItemDispense() {}
};

/**
 * @brief Tests the State Pattern implementation.
 *
 * This function demonstrates the State Pattern by:
 * - Creating a context with an initial state (ItemSelected)
 * - Changing the context's state
 * - Requesting the context to handle requests based on different states
 *
 * This showcases how an object's behavior changes based on its internal state,
 * and how the state can be dynamically changed to alter the object's behavior.
 *
 * @return void
 */
void testStatePattern();

#endif