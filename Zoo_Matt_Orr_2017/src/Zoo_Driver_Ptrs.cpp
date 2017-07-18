#include <iomanip>
#include <iostream>
#include <string> 
#include <string> 
#include <vector>

#include "Animal.h"
#include "Mammal.h"
#include "Reptile.h"

using namespace std;

typedef vector<Animal*> Zoo;

void zooReport(Zoo&);
void feedAnimal(Zoo&, int);

int main()
{
 	Zoo myZoo;
	double zooFoodTotal = 0;
	int choice;
   
   /*
    * By using pointers to Animal for the new Mammal and Reptile objects, we
    * avoid object slicing.  In other words, we don't lose the functionality/properties
    * if the derived class.
    */
   Animal* ptrCat = new Mammal("enigma", 7);
   Animal* ptrSnake = new Reptile("slither", 12, 82);
   myZoo.push_back(ptrCat);
   myZoo.push_back(ptrSnake);
	
	for (int i = 0; i < myZoo.size(); i++)
	{
		cout << i+ 1 << "." << myZoo[i]->getName() << endl;
	}

	cout << "Which Animal would you like to feed?";
	cin >> choice; 
	
	feedAnimal(myZoo, choice);
	zooReport(myZoo);
	
	cout << "Process zoo Food Order .... " << endl;
	for (int i = 0; i < myZoo.size(); i++)
	{	
      // cout << "Animal type is :" << myZoo[i]->getAnimalType() << endl;
		zooFoodTotal += myZoo[i]->getFood();
	}
		
	cout << "Zoo Total Food " << zooFoodTotal << endl << endl;

   /*
    * Since we've allocated resources on the heap using the "new" operator,
    * we release them now to avoid resource/memory leaks.
    */
   for (int i = 0; i < myZoo.size(); i++)
   {
      delete myZoo[i];
   }

	return 0; 
}

void zooReport(Zoo& aZoo)
{
	cout << "Animals Report" << endl;
   cout << "--------------" << endl;

	for (int i = 0; i < aZoo.size(); i++)
	{
      /* 
       * This is polymorphism at work.  The pointer object behaves like the objects
       * data type.  So, if aZoo[i] points to a Mammal object, the methods for Mammal
       * are called and, if aZoo[i] points to a Reptile object, the methods for Reptile
       * are called.  It is important to note, though, that this only applied if the 
       * methods in Animal are virtual.
       */
		aZoo[i]->getInfo();
	}
   cout << "--------------" << endl;
}

void feedAnimal(Zoo& aZoo , int choice)
{
	double amount;

	switch (choice)
	{
	case 1:  cout << "How much food is needed: " << endl;
		cin >> amount;
		aZoo[choice - 1]->feed(amount);
		break;

	case 2: cout << "How much food is needed: " << endl;
		cin >> amount;
		aZoo[choice - 1]->feed(amount);
		break;
	default:
		cout << "invalid data. Cannot process. " << endl;
	}
   cout << endl;
}
