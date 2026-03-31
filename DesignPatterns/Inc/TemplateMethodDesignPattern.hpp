#ifndef TEMPLATEMETHODDESIGNPATTERN_HPP
#define TEMPLATEMETHODDESIGNPATTERN_HPP

#include <iostream>

/**
 * @brief Pattern Implementation: Template Method Design Pattern
 *
 * This implementation demonstrates the Template Method Pattern, a behavioral design pattern
 * that defines the skeleton of an algorithm in a method, deferring some steps to subclasses.
 * Template Method lets subclasses redefine certain steps of an algorithm without changing
 * the algorithm's structure.
 *
 * Key Components:
 * - BeverageMaker (Abstract Base Class): Defines the template method and common operations.
 * - TeaMaker and CoffeeMaker (Concrete Classes): Override specific steps of the algorithm.
 */

/**
 * @brief Abstract base class for beverage preparation.
 *
 * Defines the template method and common operations for making beverages.
 */
class BeverageMaker
{
public:
    /**
     * @brief Defines the template method for making a beverage.
     *
     * This function outlines the standard process for making any beverage:
     * 1. Boil water
     * 2. Brew the beverage
     * 3. Pour into a cup
     * 4. Add condiments
     *
     * Subclasses override the brew() and addCondiments() methods to create
     * different types of beverages while maintaining the overall algorithm structure.
     *
     * @return void
     */
    void makeBeverage();

private:
    /**
     * @brief Abstract method for brewing the beverage.
     *
     * Must be implemented by subclasses to provide beverage-specific brewing logic.
     *
     * @return void
     */
    virtual void brew() = 0;

    /**
     * @brief Boils water for the beverage.
     *
     * This is a common operation shared by all beverage makers.
     * It is not overridden by subclasses as water is boiled the same way
     * regardless of the type of beverage being prepared.
     *
     * @return void
     */
    void boilWater();

    /**
     * @brief Abstract method for adding condiments.
     *
     * Must be implemented by subclasses to provide beverage-specific condiments.
     *
     * @return void
     */
    virtual void addCondiments() = 0;

protected:
    /**
     * @brief Pours the brewed beverage into a cup.
     *
     * This is a common operation shared by all beverage makers.
     * It is not overridden by subclasses as the pouring step is identical
     * for all types of beverages.
     *
     * @return void
     */
    void pourInCup();
};

/**
 * @brief Concrete class for making tea.
 *
 * Implements the abstract methods from BeverageMaker to create tea.
 */
class TeaMaker : public BeverageMaker
{
public:
    /**
     * @brief Brews tea as part of the tea-making process.
     *
     * This method overrides the abstract brew() method from BeverageMaker
     * to implement tea-specific brewing logic.
     *
     * @return void
     */
    void brew() override;

    /**
     * @brief Adds tea-specific condiments to the brewed tea.
     *
     * This method overrides the abstract addCondiments() method from BeverageMaker
     * to implement tea-specific condiment logic.
     *
     * @return void
     */
    void addCondiments() override;
};

/**
 * @brief Concrete class for making coffee.
 *
 * Implements the abstract methods from BeverageMaker to create coffee.
 */
class CoffeeMaker : public BeverageMaker
{
public:
    /**
     * @brief Brews coffee as part of the coffee-making process.
     *
     * This method overrides the abstract brew() method from BeverageMaker
     * to implement coffee-specific brewing logic.
     *
     * @return void
     */
    void brew() override;

    /**
     * @brief Adds coffee-specific condiments to the brewed coffee.
     *
     * This method overrides the abstract addCondiments() method from BeverageMaker
     * to implement coffee-specific condiment logic.
     *
     * @return void
     */
    void addCondiments() override;
};

/**
 * @brief Tests the Template Method Pattern implementation.
 *
 * This function demonstrates the Template Method Pattern by:
 * - Creating instances of TeaMaker and CoffeeMaker
 * - Calling makeBeverage() on each, which executes the same algorithm structure
 * - Each subclass implements its own brew() and addCondiments() methods
 * - The core algorithm structure (boilWater -> brew -> pourInCup -> addCondiments) remains unchanged
 *
 * This showcases how the Template Method Pattern allows code reuse and maintains
 * a consistent algorithm structure while allowing customization at specific steps.
 *
 * @return void
 */
void testTemplateMethodDesignPattern();
#endif