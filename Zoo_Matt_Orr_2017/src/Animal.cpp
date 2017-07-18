#include <string>
#include <iostream>

#include "Animal.h"

Animal::Animal( std::string name, double weight)
{
   _name = name;
   _weight = weight;
   _foodTotal = 0;
}

std::string Animal::getName()
{
   return _name;
}

double Animal::getWeight()
{
   return _weight;
}

double Animal::getFood()
{
   return _foodTotal;
}

void Animal::setName(std::string name)
{
   _name = name;
}
void Animal::setWeight(double weight)
{
   _weight = weight;
}

void Animal::feed(double amount)
{
   _weight += amount;
   _foodTotal += amount;
}

void Animal::getInfo()
{
   std::cout << "Animal: " << _name << std::endl;
   std::cout << "Weight: " << _weight << " lbs." << std::endl;
   std::cout << "Food eaten this week " << _foodTotal << std::endl;
}

Animal::~Animal()
{
   std::cout << "Destructing Animal object." << std::endl;
}
