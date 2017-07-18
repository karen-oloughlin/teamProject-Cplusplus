#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Mammal.h"

Mammal::Mammal(std::string name, double weight) : Animal(name, weight), _animalType(Animal::MAMMAL)
{
}

void Mammal::getInfo()
{
   std::cout << "Animal Type: " << _animalType << std::endl;
   Animal::getInfo();
   std::cout << std::endl;
}

Animal::ANIMAL_TYPE Mammal::getAnimalType()
{
   return _animalType;
}

Mammal::~Mammal()
{
   std::cout << "Destructing Mammal object." << std::endl;
}
