#include "Animal.h"
#include "TestAnimal.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TestAnimal);

void TestAnimal::testGetName()
{
}

void TestAnimal::testGetWeight()
{
   double animalWeight = 5.;
   Animal myAnimal( "animal", animalWeight );

   /*
    * These two assert statements accomplish the same thing, but the second will print
    * out the expected and actual values if the test fails.
    */
   CPPUNIT_ASSERT( animalWeight == myAnimal.getWeight() );
   CPPUNIT_ASSERT_EQUAL( animalWeight, myAnimal.getWeight() );
}

void TestAnimal::testGetFood()
{
   double animalWeight = 5.;
   double foodTotal    = 0.;
   Animal myAnimal( "animal", animalWeight );

   CPPUNIT_ASSERT_EQUAL( foodTotal, myAnimal.getFood() );

   double amountToFeed = 2.;
   animalWeight += amountToFeed;
   foodTotal    += amountToFeed;
   
   myAnimal.feed( amountToFeed );

   CPPUNIT_ASSERT_EQUAL( animalWeight, myAnimal.getWeight() );
   CPPUNIT_ASSERT_EQUAL( foodTotal+1.   , myAnimal.getFood() );
}

void TestAnimal::testGetInfo()
{
}

void TestAnimal::testSetName()
{
}

void TestAnimal::testSetWeight()
{
}

void TestAnimal::testFeed()
{
}