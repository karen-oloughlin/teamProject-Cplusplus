#include <iostream>

#include "Reptile.h"

Reptile::Reptile(std::string name, double weight, double temp) : Animal(name, weight),
                                                                 _animalType(Animal::REPTILE), _temperature(temp)
{
}

void Reptile::getInfo()
{
   std::cout << "Animal Type: " << _animalType << std::endl;
   Animal::getInfo();
   std::cout << "Reptile: Temperature: " << _temperature << std::endl << std::endl;
}

void Reptile::changeTemperature(double amount)
{
   _temperature = _temperature + amount;
}

Animal::ANIMAL_TYPE Reptile::getAnimalType()
{
   return _animalType;
}

Reptile::~Reptile()
{
   std::cout << "Destructing Reptile object." << std::endl;
}
