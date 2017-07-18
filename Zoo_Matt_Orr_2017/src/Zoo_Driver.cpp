#include <iomanip>
#include <iostream>
#include <string>
#include <string>
#include <vector>
#include <stdio.h>

#include "Animal.h"
#include "Mammal.h"
#include "Reptile.h"

using namespace std;

typedef vector<Animal> Zoo;

void zooReport(Zoo&);
void feedAnimal(Zoo&, int);

int main()
{
   Zoo myZoo;
   double zooFoodTotal = 0;
   int choice;

   // The following will lead to object slicing if the myZoo vector contains Animal objects
   // rather than pointers to Animal objects.
   Mammal cat("enigma", 7);
   Reptile snake("slither", 12, 82);
   myZoo.push_back(cat);
   myZoo.push_back(snake);

   for (int i = 0; i < myZoo.size(); i++)
   {
     cout << i+ 1 << "." << myZoo[i].getName() << endl;
   }

   cout << "Which Animal would you like to feed?";
   cin >> choice;

   feedAnimal(myZoo, choice);
   zooReport(myZoo);

   cout << "Process zoo Food Order .... " << endl;
   for (int i = 0; i < myZoo.size(); i++)
   {
     zooFoodTotal += myZoo[i].getFood();
   }

   cout << "Zoo Total Food " << zooFoodTotal << endl << endl;

   return 0;
}

void zooReport(Zoo& aZoo)
{
   cout << "Animals Report" << endl;
   cout << "--------------" << endl;

   for (int i = 0; i < aZoo.size(); i++)
   {
     /*
      * This does not behave polymorphically, even when Animal's methods are virtual,
      * because the Zoo vector contains Animal objects rather than Animal pointers.
      * If Mammal and Reptile objects are added to the vector, they will be "sliced"
      * and treated like Animal objects.
      */
     aZoo[i].getInfo();
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
     aZoo[choice - 1].feed(amount);
     break;

   case 2: cout << "How much food is needed: " << endl;
     cin >> amount;
     aZoo[choice - 1].feed(amount);
     break;
   default:
     cout << "invalid data. Cannot process. " << endl;
   }
    cout << endl;
}
