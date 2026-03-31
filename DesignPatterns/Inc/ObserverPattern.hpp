#ifndef OBSERVERPATTERN_HPP
#define OBSERVERPATTERN_HPP

#include <vector>
#include <string>
#include <iostream>

/**
 * @brief Pattern Implementation: Observer Pattern
 *
 * This implementation demonstrates the Observer Pattern, a behavioral design pattern
 * that defines a one-to-many dependency between objects such that when one object changes state,
 * all its dependents are notified and updated automatically.
 *
 * Key Components:
 * - WeatherStation (Subject): Maintains a list of observers and notifies them of state changes.
 * - Observer (Abstract Observer): Defines the interface for objects that should be notified.
 * - ObserverTV and ObserverMobile (Concrete Observers): Concrete implementations that update when notified.
 */

/**
 * @brief Abstract observer interface.
 *
 * Defines the interface for objects that should receive updates from the subject.
 */
class Observer
{
public:
    /**
     * @brief Updates the observer with new information.
     *
     * @param weathernews Reference to a string containing the updated weather information.
     * @return void
     */
    virtual void update(std::string &weathernews) = 0;
};

/**
 * @brief Abstract subject interface.
 *
 * Defines the interface for maintaining a list of observers and notifying them.
 */
class Subject
{
public:
    /**
     * @brief Adds an observer to the notification list.
     *
     * @param observer Pointer to the Observer object to be added.
     * @return void
     */
    virtual void addObserver(Observer *observer) = 0;

    /**
     * @brief Notifies all registered observers of state changes.
     *
     * @return void
     */
    virtual void notifyObserver() = 0;
};

/**
 * @brief Concrete subject that represents a weather station.
 *
 * Maintains a list of observers and notifies them when weather information changes.
 */
class WeatherStation : public ::Subject
{
private:
    std::vector<Observer *> observers;
    std::string weathernews;

public:
    /**
     * @brief Adds an observer to the weather station's notification list.
     *
     * This function registers an observer object that will be notified whenever
     * the weather station's state changes.
     *
     * @param observer Pointer to the Observer object to be added.
     * @return void
     */
    void addObserver(Observer *observer) override;

    /**
     * @brief Notifies all registered observers of state changes.
     *
     * This function iterates through all registered observer objects and calls
     * their update method with the current weather information, ensuring all observers
     * are synchronized with the subject's state.
     *
     * @return void
     */
    void notifyObserver() override;

    /**
     * @brief Sets the weather information and notifies all observers.
     *
     * This function updates the current weather information and triggers a notification
     * to all registered observers so they can display or process the updated weather data.
     *
     * @param weathernews Reference to a string containing the current weather information.
     * @return void
     */
    void setWeather(const std::string &weathernews);
};

/**
 * @brief Concrete observer for television.
 *
 * The ObserverTV class represents a television observer that receives weather updates
 * from a weather station and displays them to the user.
 */
class ObserverTV : public ::Observer
{
private:
    std::string weathernews;

    /**
     * @brief Displays the current weather information on the TV.
     *
     * This function outputs the current weather news to the console as if it were
     * being displayed on a television screen.
     *
     * @return void
     */
    void display();

public:
    /**
     * @brief Updates the observer with new weather information.
     *
     * This function is called by the subject when its state changes. It stores
     * the new weather information and displays it.
     *
     * @param weathernews Reference to a string containing the updated weather information.
     * @return void
     */
    void update(std::string &weathernews) override;
};

/**
 * @brief Concrete observer for mobile device.
 *
 * The ObserverMobile class represents a mobile device observer that receives weather updates
 * from a weather station and displays them to the user.
 */
class ObserverMobile : public ::Observer
{
private:
    std::string weathernews;

    /**
     * @brief Displays the current weather information on the mobile device.
     *
     * This function outputs the current weather news to the console as if it were
     * being displayed on a mobile screen.
     *
     * @return void
     */
    void display();

public:
    /**
     * @brief Updates the mobile observer with new weather information.
     *
     * This function is called by the subject when its state changes. It stores
     * the new weather information and displays it on the mobile device.
     *
     * @param weathernews Reference to a string containing the updated weather information.
     * @return void
     */
    void update(std::string &weathernews) override;
};

/**
 * @brief Tests the Observer Pattern implementation.
 *
 * This function demonstrates the Observer Pattern by:
 * - Creating a weather station (subject)
 * - Creating a mobile observer
 * - Registering the observer with the weather station
 * - Setting weather information, which triggers notifications to all observers
 *
 * When the weather is set, the registered mobile observer is automatically
 * notified and displays the updated weather information.
 *
 * @return void
 */
void testObserverPattern();

#endif