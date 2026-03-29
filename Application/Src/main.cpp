#include <iostream>
#include "../Inc/main.hpp"
#include "../../Basics/Inc/Vector.hpp"
#include "../../DesignPatterns/Inc/ObserverPattern.hpp"
#include "../../DesignPatterns/Inc/StatePattern.hpp"
#include "../../DesignPatterns/Inc/ChainofResponsibilityPattern.hpp"

int main()
{
    std::cout << "Hello World!" << std::endl;
    testChainofResponsibilityPattern();
    // testStatePattern();
    //  testObserverPattern();
    //   testCommandPattern();
    //   vectorDataTypePractice();
    getchar();
    return 0;
}
