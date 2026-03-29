#ifndef CHAINOFRESPONSIBILITY_HPP
#define CHAINOFRESPONSIBILITY_HPP

enum Request
{
    BASIC,
    MEDIUM,
    CRITICAL,
    IMPOSSIBLE
};

class SupportHandle
{
public:
    virtual void HandleRequest(Request request) = 0;
    virtual void AssignRequesttoNextHandler(SupportHandle *nexthandler) = 0;
};

class BasicHandler : public SupportHandle
{
private:
    SupportHandle *nextHandler;

public:
    explicit BasicHandler(SupportHandle *nexthandler) : nextHandler(nexthandler) {}
    void HandleRequest(Request request) override;
    void AssignRequesttoNextHandler(SupportHandle *nexthandler) override;
};

class MediumHandler : public SupportHandle
{
private:
    SupportHandle *nextHandler;

public:
    explicit MediumHandler(SupportHandle *nexthandler = nullptr) : nextHandler(nexthandler) {}
    void HandleRequest(Request request) override;
    void AssignRequesttoNextHandler(SupportHandle *nexthandler) override;
};

class CriticalHandler : public SupportHandle
{
private:
    SupportHandle *nextHandler;

public:
    explicit CriticalHandler(SupportHandle *nexthandler = nullptr) : nextHandler(nexthandler) {}
    void HandleRequest(Request request) override;
    void AssignRequesttoNextHandler(SupportHandle *nexthandler) override;
};

// class Customer
// {
// private:
//     Request request;
//     SupportHandle *supportHandler;

// public:
//     explicit Customer(Request request) : request(request) {}
//     void setHandler(SupportHandle *supportHandler);
//     SupportHandle *getHandler();
// };

void testChainofResponsibilityPattern();

#endif