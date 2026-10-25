#include "Gpio.hpp"

GPIO_PIN::GPIO_PIN(volatile uint32_t *port, volatile uint32_t *modeRegister, uint8_t pinNumber)
    : port(port), modeRegister(modeRegister), pinNumber(pinNumber) {}

void GPIO_PIN::setHigh()
{
    *port |= (1 << pinNumber);
}

void GPIO_PIN::setLow()
{
    *port &= ~(1 << pinNumber);
}

void GPIO_PIN::toggle()
{
    *port ^= (1 << pinNumber);
}

bool GPIO_PIN::getState()
{
    return (*port & (1 << pinNumber)) != 0;
}
static void gpioDeinit()
{
    // Implementation for deinitializing the GPIO pin
}

GPIO_PIN::~GPIO_PIN()
{
    gpioDeinit();
}