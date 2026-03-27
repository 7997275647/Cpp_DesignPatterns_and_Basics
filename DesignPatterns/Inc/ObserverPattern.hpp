#ifndef OBSERVERPATTERN_HPP
#define OBSERVERPATTERN_HPP

#include <vector>
#include <string>
#include <iostream>

class Observer
{
public:
    virtual void update(std::string &weathernews) = 0;
};

class Subject
{
public:
    virtual void addObserver(Observer *observer) = 0;
    virtual void notifyObserver() = 0;

    // virtual void update() = 0;
};

class WeatherStation : public ::Subject
{
private:
    std::vector<Observer *> observers;
    std::string weathernews;

public:
    void addObserver(Observer *observer) override;
    void notifyObserver() override;
    void setWeather(const std::string &weathernews);
};

class ObserverTV : public ::Observer
{
private:
    std::string weathernews;
    void display();

public:
    void update(std::string &weathernews) override;
};

class ObserverMobile : public ::Observer
{
private:
    std::string weathernews;
    void display();

public:
    void update(std::string &weathernews) override;
};

void testObserverPattern();

#endif