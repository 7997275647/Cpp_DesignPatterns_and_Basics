#ifndef GPIO_HPP
#define GPIO_HPP

#include <cstdint>

/**
 * @brief Class representing a GPIO pin.
 *
 * This class provides an interface to control a GPIO pin, allowing it to be set high,
 * set low, toggled, and queried for its current state. It also includes functionality
 * for deinitializing the GPIO pin.
 *
 * @verbatim
 * +----------------------------------+
 * |            GPIO_PIN              |
 * +----------------------------------+
 * | - port: volatile uint32_t*       |
 * | - modeRegister: volatile uint32_t*|
 * | - pinNumber: uint8_t             |
 * +----------------------------------+
 * | + GPIO_PIN(port, modeRegister,   |
 * |            pinNumber)            |
 * | + setHigh(): void                |
 * | + setLow(): void                 |
 * | + toggle(): void                 |
 * | + getState(): bool               |
 * | + ~GPIO_PIN()                    |
 * +----------------------------------+
 * @endverbatim
 */
class GPIO_PIN
{
private:
    volatile uint32_t *port;
    volatile uint32_t *modeRegister;
    uint8_t pinNumber;

public:
    /**
     * @brief Constructs a GPIO_PIN object.
     *
     * @param port Pointer to the GPIO port register.
     * @param modeRegister Pointer to the GPIO mode register.
     * @param pinNumber The pin number associated with this GPIO pin.
     */
    GPIO_PIN(volatile uint32_t *port, volatile uint32_t *modeRegister, uint8_t pinNumber);

    /**
     * @brief Sets the GPIO pin to a high state.
     *
     * This function sets the GPIO pin to a high state (logic level 1).
     */
    void setHigh();

    /**
     * @brief Sets the GPIO pin to a low state.
     *
     * This function sets the GPIO pin to a low state (logic level 0).
     */
    void setLow();

    /**
     * @brief Toggles the state of the GPIO pin.
     *
     * This function toggles the current state of the GPIO pin. If the pin is high, it will be set low,
     * and if it is low, it will be set high.
     */
    void toggle();

    /**
     * @brief Gets the current state of the GPIO pin.
     *
     * @return true if the pin is high, false if it is low.
     */
    bool getState();

    /**
     * @brief Destructor for the GPIO_PIN class.
     *
     * This destructor ensures that any necessary cleanup is performed when a GPIO_PIN object is destroyed.
     */
    ~GPIO_PIN();
};

/**
 * @brief Deinitializes the GPIO pin.
 *
 * This function performs any necessary cleanup or deinitialization for the GPIO pin.
 */
static void gpioDeinit();

#endif
