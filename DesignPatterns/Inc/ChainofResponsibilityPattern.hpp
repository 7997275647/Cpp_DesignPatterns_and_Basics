#ifndef CHAINOFRESPONSIBILITY_HPP
#define CHAINOFRESPONSIBILITY_HPP

/**
 * @brief Pattern Implementation: Chain of Responsibility Pattern
 *
 * This implementation demonstrates the Chain of Responsibility Pattern, a behavioral
 * design pattern that passes requests along a chain of handlers. Each handler decides
 * either to process the request or to pass it to the next handler in the chain.
 *
 * Key Components:
 * - Handler (Abstract): Defines the interface for handling requests and passing to next handler.
 * - Concrete Handlers: BasicHandler, MediumHandler, CriticalHandler implement specific handling logic.
 * - Client: Initiates the request and passes it to the first handler in the chain.
 */

/**
 * @brief Enumeration of request types.
 */
enum Request
{
    BASIC,     ///< Basic level request
    MEDIUM,    ///< Medium level request
    CRITICAL,  ///< Critical level request
    IMPOSSIBLE ///< Impossible/unknown request type
};

/**
 * @brief Abstract base class for support handlers.
 *
 * Defines the interface for handling requests and managing the chain.
 */
class SupportHandle
{
public:
    /**
     * @brief Handles a support request.
     *
     * @param request The Request object to be handled.
     * @return void
     */
    virtual void HandleRequest(Request request) = 0;

    /**
     * @brief Assigns the next handler in the chain.
     *
     * @param nexthandler Pointer to the next handler in the chain.
     * @return void
     */
    virtual void AssignRequesttoNextHandler(SupportHandle *nexthandler) = 0;
};

/**
 * @brief Concrete handler for basic-level support requests.
 *
 * Handles basic-level requests and passes others to the next handler.
 */
class BasicHandler : public SupportHandle
{
private:
    SupportHandle *nextHandler;

public:
    explicit BasicHandler(SupportHandle *nexthandler) : nextHandler(nexthandler) {}

    /**
     * @brief Assigns the next handler in the chain for BasicHandler.
     *
     * This function sets up the chain by linking the BasicHandler to the next handler
     * in the responsibility chain. If this handler cannot process the request, it will
     * be passed to the next handler.
     *
     * @param nexthandler Pointer to the next handler in the chain.
     * @return void
     */
    void AssignRequesttoNextHandler(SupportHandle *nexthandler) override;

    /**
     * @brief Handles requests appropriate for basic support.
     *
     * This function processes basic-level support requests. If the request is of BASIC type,
     * it handles it directly. Otherwise, it passes the request to the next handler in the chain.
     *
     * @param request The Request object to be handled.
     * @return void
     */
    void HandleRequest(Request request) override;
};

/**
 * @brief Concrete handler for medium-level support requests.
 *
 * Handles medium-level requests and passes others to the next handler.
 */
class MediumHandler : public SupportHandle
{
private:
    SupportHandle *nextHandler;

public:
    explicit MediumHandler(SupportHandle *nexthandler = nullptr) : nextHandler(nexthandler) {}

    /**
     * @brief Assigns the next handler in the chain for MediumHandler.
     *
     * This function sets up the chain by linking the MediumHandler to the next handler
     * in the responsibility chain. Unhandled medium requests will be passed to the next handler.
     *
     * @param nexthandler Pointer to the next handler in the chain.
     * @return void
     */
    void AssignRequesttoNextHandler(SupportHandle *nexthandler) override;

    /**
     * @brief Handles requests appropriate for medium support.
     *
     * This function processes medium-level support requests. If the request is of MEDIUM type,
     * it handles it directly. Otherwise, it passes the request to the next handler in the chain.
     *
     * @param request The Request object to be handled.
     * @return void
     */
    void HandleRequest(Request request) override;
};

/**
 * @brief Concrete handler for critical-level support requests.
 *
 * Handles critical-level requests and is typically the last handler in the chain.
 */
class CriticalHandler : public SupportHandle
{
private:
    SupportHandle *nextHandler;

public:
    explicit CriticalHandler(SupportHandle *nexthandler = nullptr) : nextHandler(nexthandler) {}

    /**
     * @brief Handles requests appropriate for critical support.
     *
     * This function processes critical-level support requests. If the request is of CRITICAL type,
     * it handles it directly. If it cannot be handled, a message is displayed indicating that
     * the request cannot be processed.
     *
     * @param request The Request object to be handled.
     * @return void
     */
    void HandleRequest(Request request) override;

    /**
     * @brief Assigns the next handler in the chain for CriticalHandler.
     *
     * This function sets up the chain by linking the CriticalHandler to the next handler
     * in the responsibility chain. CriticalHandler is typically the last handler in the chain.
     *
     * @param nexthandler Pointer to the next handler in the chain.
     * @return void
     */
    void AssignRequesttoNextHandler(SupportHandle *nexthandler) override;
};

/**
 * @brief Tests the Chain of Responsibility Pattern implementation.
 *
 * This function demonstrates the Chain of Responsibility Pattern by:
 * - Creating three handler objects: BasicHandler, MediumHandler, and CriticalHandler
 * - Linking them together to form a chain
 * - Passing various requests through the chain
 * - Each handler processes requests appropriate to its level or forwards them to the next handler
 *
 * This showcases how requests are passed along the chain until a suitable handler
 * processes it or the chain ends.
 *
 * @return void
 */
void testChainofResponsibilityPattern();

#endif