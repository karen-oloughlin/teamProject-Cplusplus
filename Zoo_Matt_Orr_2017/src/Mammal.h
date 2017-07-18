#pragma once  //replace #infndef and #define

#include <string>
#include <cstdlib>

#include "Animal.h"

class Mammal : public Animal
{
public:
   Mammal(std::string name, double weight);
   ~Mammal();

   void getInfo();

   ANIMAL_TYPE getAnimalType();

private:
   ANIMAL_TYPE _animalType;
};

