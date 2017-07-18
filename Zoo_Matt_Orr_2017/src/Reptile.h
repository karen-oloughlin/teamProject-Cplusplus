#pragma once

#include <string>

#include "Animal.h"

class Reptile : public Animal
{
public:
   Reptile(std::string name, double weight, double temp);
   ~Reptile();

   virtual void getInfo();
   void changeTemperature(double);

   ANIMAL_TYPE getAnimalType();

private:
   double _temperature;
   ANIMAL_TYPE _animalType;
};

