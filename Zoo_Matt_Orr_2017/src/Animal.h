#pragma once // replaces #ifndef and #define....

#include <string>

class Animal
{
public:
   enum ANIMAL_TYPE
   {
      MAMMAL = 0,
      REPTILE = 1
   };

   Animal(std::string name, double weight);
   /*
    * Make base class destructors virtual.  This ensures that if a class of a derived type
    * is accessed using a pointer to the base class, when the object is destroyed both the
    * derived and base class destructors are called.
    */
   virtual ~Animal();

   std::string getName();
   double getWeight();
   double getFood();
   /*
    * If this method is virtual and called from a pointer to Animal, the implementation
    * used will be that of the object type pointed to (i.e., Animal, Mammal, or Reptile).
    * Without the virtual, if this method is called from a pointer to Animal, the implementation
    * from Animal will be used.
    */
   virtual void getInfo();

   void setName(std::string name);
   void setWeight(double weight);
   void feed(double amount);

   /*
    * This is a pure virtual method (that's what the "= 0" means).  If we uncomment it,
    * we will no longer be able to create objects of type Animal.  Animal will become
    * what is known as an abstract class. A pure virtual method is the logical choice here
    * because it doesn't make sense for the Animal class itself to have an animal type,
    * but we want to enforce that all classes inheriting Animal implement this method.
    */
   virtual ANIMAL_TYPE getAnimalType() = 0;

protected:
   std::string _name;
   double _weight;
   double _foodTotal;
};

/* www.cplusplus.com/doc/tutorial/polymorphism/
Essentially, what the virtual keyword does is to allow a member
of a derived class with the same name as one in the base class to be
appropriately called from a pointer, and more precisely when the type
of the pointer is a pointer to the base class that is pointing to
an object of the derived class.
*/
