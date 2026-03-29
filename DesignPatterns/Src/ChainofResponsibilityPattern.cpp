#include <iostream>
#include "../Inc/ChainofResponsibilityPattern.hpp"

void BasicHandler::AssignRequesttoNextHandler(SupportHandle *nexthandler)
{
    this->nextHandler = nexthandler;
}

void BasicHandler::HandleRequest(Request request)
{
    if (request == BASIC)
    {
        std::cout << "Request Handled by Basic Handler" << std::endl;
    }
    else if (nextHandler != nullptr)
    {
        nextHandler->HandleRequest(request);
    }
}
void MediumHandler::AssignRequesttoNextHandler(SupportHandle *nexthandler)
{
    this->nextHandler = nexthandler;
}

void MediumHandler::HandleRequest(Request request)
{
    if (request == MEDIUM)
    {
        std::cout << "Request Handled by Medium Handler" << std::endl;
    }
    else if (nextHandler != nullptr)
    {
        nextHandler->HandleRequest(request);
    }
}

void CriticalHandler::HandleRequest(Request request)
{
    if (request == CRITICAL)
    {
        std::cout << "Request Handled by Critical Handler" << std::endl;
    }
    else if (nextHandler != nullptr)
    {
        std::cout << "Request Cannot be Handled" << std::endl;
    }
}

void CriticalHandler::AssignRequesttoNextHandler(SupportHandle *nexthandler)
{
    this->nextHandler = nexthandler;
}

void testChainofResponsibilityPattern()
{
    BasicHandler *l1 = new BasicHandler(nullptr);
    MediumHandler *l2 = new MediumHandler(nullptr);
    CriticalHandler *l3 = new CriticalHandler(nullptr);
    l1->AssignRequesttoNextHandler(l2);
    l2->AssignRequesttoNextHandler(l3);
    l1->HandleRequest(MEDIUM);
    l2->HandleRequest(MEDIUM);
    l1->HandleRequest(CRITICAL);
    l3->HandleRequest(IMPOSSIBLE);
}