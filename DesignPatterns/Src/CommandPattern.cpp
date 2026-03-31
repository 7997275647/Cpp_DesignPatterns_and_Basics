#include "../Inc/CommandPattern.hpp"
#include <iostream>
#include <random>

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
