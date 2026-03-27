#include "../Inc/ObserverPattern.hpp"

// WeatherStation implementations
void WeatherStation::addObserver(Observer *observer)
{
    observers.push_back(observer);
}

void WeatherStation::notifyObserver()
{
    for (Observer *observer : observers)
    {
        observer->update(weathernews);
    }
}

void WeatherStation::setWeather(const std::string &weathernews)
{
    this->weathernews = weathernews;
    notifyObserver();
}

// ObserverTV implementations
void ObserverTV::display()
{
    std::cout << "weather is : " << weathernews << std::endl;
}

void ObserverTV::update(std::string &weathernews)
{
    this->weathernews = weathernews;
    display();
}

// ObserverMobile implementations
void ObserverMobile::display()
{
    std::cout << "weather is : " << weathernews << std::endl;
}

void ObserverMobile::update(std::string &weathernews)
{
    this->weathernews = weathernews;
    display();
}

void testObserverPattern()
{
    WeatherStation weatherStation;
    ObserverMobile observerMobile;

    weatherStation.addObserver(&observerMobile);
    weatherStation.setWeather("sunny");
}