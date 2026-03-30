#include <iostream>
#include "../../DesignPatterns/Inc/TemplateMethodDesignPattern.hpp"

void BeverageMaker::makeBeverage()
{
    boilWater();
    brew();
    pourInCup();
    addCondiments();
}

void BeverageMaker::pourInCup()
{
    std::cout << "Beverage poured in cup!" << std::endl;
}

void BeverageMaker::boilWater()
{
    std::cout << "Water Boiled successfully!" << std::endl;
}

void TeaMaker::brew()
{
    std::cout << "Tea Brewed Successfully!" << std::endl;
}
void CoffeeMaker::brew()
{
    std::cout << "Coffee Brewed Successfully!" << std::endl;
}

void TeaMaker::addCondiments()
{
    std::cout << "Condiments of Tea added" << std::endl;
}

void CoffeeMaker::addCondiments()
{
    std::cout << "Condiments of Coffee added" << std::endl;
}

void testTemplateMethodDesignPattern()
{
    TeaMaker *t1 = new TeaMaker;
    CoffeeMaker *c1 = new CoffeeMaker;

    t1->makeBeverage();
    c1->makeBeverage();
}