#ifndef TEMPLATEMETHODDESIGNPATTERN_HPP
#define TEMPLATEMETHODDESIGNPATTERN_HPP

#include <iostream>

class BeverageMaker
{
public:
    void makeBeverage();

private:
    virtual void brew() = 0;
    void boilWater();
    virtual void addCondiments() = 0;

protected:
    void pourInCup();
};

class TeaMaker : public BeverageMaker
{
public:
    void brew() override;
    void addCondiments() override;
};

class CoffeeMaker : public BeverageMaker
{
public:
    void brew() override;
    void addCondiments() override;
};

void testTemplateMethodDesignPattern();
#endif