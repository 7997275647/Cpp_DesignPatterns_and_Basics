#ifndef COMMANDPATTERN_HPP
#define COMMANDPATTERN_HPP

#include <vector>

/**
 * @brief Pattern Implementation: Command Pattern
 *
 * This implementation demonstrates the Command Pattern, a behavioral design pattern
 * that encapsulates a request as an object, allowing parameterization of clients with
 * different requests, queuing of requests, and logging of requests.
 *
 * Key Components:
 * - Command Interface: Defines the contract for all concrete commands.
 * - Move Command: Concrete command that executes and undoes move operations.
 * - Jump Command: Concrete command that executes and undoes jump operations.
 * - Command Invoker: Manages and executes commands.
 */

/**
 * @brief Abstract base class for all commands.
 *
 * Defines the interface that all concrete command classes must implement.
 */
class Command
{
public:
    virtual ~Command() = default;

    /**
     * @brief Executes the command.
     * @return void
     */
    virtual void execute() = 0;

    /**
     * @brief Undoes the command.
     * @return void
     */
    virtual void undo() = 0;

    /**
     * @brief Clears the command state.
     * @return void
     */
    virtual void clear() = 0;
};

/**
 * @brief Concrete command for move operations.
 *
 * Implements the Command interface to handle move command execution, undo, and cleanup.
 */
class Move : public Command
{
public:
    /**
     * @brief Executes a move command.
     *
     * This function handles the execution of a move command by simulating the movement
     * of an object. The actual movement logic would be implemented here.
     *
     * @return void
     */
    void execute() override;

    /**
     * @brief Undoes a previously executed move command.
     *
     * This function reverses the effects of a move command, simulating an undo operation.
     * It resets the object to its previous state.
     *
     * @return void
     */
    void undo() override;

    /**
     * @brief Clears the move command state.
     *
     * This function clears any internal state associated with the move command.
     *
     * @return void
     */
    void clear() override;
};

/**
 * @brief Concrete command for jump operations.
 *
 * Implements the Command interface to handle jump command execution, undo, and cleanup.
 */
class Jump : public Command
{
public:
    /**
     * @brief Executes a jump command.
     *
     * This function handles the execution of a jump command by simulating a jump action.
     *
     * @return void
     */
    void execute() override;

    /**
     * @brief Undoes a previously executed jump command.
     *
     * This function reverses the effects of a jump command by restoring the object
     * to its state before the jump was executed.
     *
     * @return void
     */
    void undo() override;

    /**
     * @brief Clears the jump command state.
     *
     * This function clears any internal state or resources associated with the jump command.
     *
     * @return void
     */
    void clear() override;
};

/**
 * @brief Tests the Command Pattern implementation.
 *
 * This function demonstrates the practical application of the Command Pattern by:
 * - Creating multiple Move command objects
 * - Storing them in a command queue
 * - Executing all commands in sequence
 * - Undoing all commands to demonstrate the undo functionality
 *
 * This showcases how commands can be queued, executed, and reversed in a controlled manner.
 *
 * @return void
 */
void testCommandPattern();

#endif // COMMANDPATTERN_HPP