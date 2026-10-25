#include <iostream>
#include "../Inc/main.hpp"
#include "../../Basics/Inc/Vector.hpp"
#include "../../Basics/Inc/OperatorOverloading.hpp"
#include "../../DesignPatterns/Inc/ObserverPattern.hpp"
#include "../../DesignPatterns/Inc/StatePattern.hpp"
#include "../../DesignPatterns/Inc/ChainofResponsibilityPattern.hpp"
#include "../../DesignPatterns/Inc/TemplateMethodDesignPattern.hpp"

int main()
{
    volatile uint32_t ledPort = 0;
    volatile uint32_t ledPortModeReg = 0;
    uint8_t ledPinNum = 5;
    GPIO_PIN led(&ledPort, &ledPortModeReg, ledPinNum);
    led.setHigh();
    std::cout << "LED State: " << led.getState() << std::endl;
    led.toggle();
    std::cout << "LED State after toggle: " << led.getState() << std::endl;
    led.setLow();
    std::cout << "LED State after setting low: " << led.getState() << std::endl;
    std::cout << "Hello World!" << std::endl;
    std::cout << "Hello World!" << std::endl;
    testOperatorOverloading();
    // testTemplateMethodDesignPattern();
    //  testChainofResponsibilityPattern();
    //   testStatePattern();
    //    testObserverPattern();
    //     testCommandPattern();
    //     vectorDataTypePractice();
    getchar();
    return 0;
}
