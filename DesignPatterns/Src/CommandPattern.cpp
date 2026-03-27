#include "../Inc/CommandPattern.hpp"
#include <iostream>
#include <random>

// Command Pattern Implementation
// Move Command and Jump Command are concrete implementations of the Command interface.
// The Command interface defines the execute, undo, and clear methods that all concrete commands must implement.

// The Move command simulates moving an object to a random position (x, y) and can undo the move by resetting the position to (0, 0).
void Move::execute()
{
    std::cout << "Executing Move Command" << std::endl;
}

void Move::undo()
{
    std::cout << "Undoing Move Command" << std::endl;
}

void Move::clear()
{
}

// The Jump command simulates a jump action and can undo the jump by printing a message.
void Jump::execute()
{
    std::cout << "Executing Jump Command" << std::endl;
}

void Jump::undo()
{
    std::cout << "Undoing Jump Command" << std::endl;
}

void Jump::clear()
{
    std::cout << "Clearing Jump Command" << std::endl;
}

// The testCommandPattern function demonstrates the usage of the Command pattern by creating multiple Move commands, executing them, and then undoing them.
void testCommandPattern()
{
    Move *moveCommand1 = new Move();
    Move *moveCommand2 = new Move();
    Move *moveCommand3 = new Move();
    Move *moveCommand4 = new Move();
    Move *moveCommand5 = new Move();

    std::vector<Command *> CommandQueue[5];
    CommandQueue[0].push_back(moveCommand1);
    CommandQueue[1].push_back(moveCommand2);
    CommandQueue[2].push_back(moveCommand3);
    CommandQueue[3].push_back(moveCommand4);
    CommandQueue[4].push_back(moveCommand5);
    for (int i = 0; i < 5; i++)
    {
        CommandQueue[i].front()->execute();
    }
    std::cout << "Undoing commands..." << std::endl;
    for (int i = 0; i < 5; i++)
    {
        CommandQueue[i].front()->undo();
    }
}
