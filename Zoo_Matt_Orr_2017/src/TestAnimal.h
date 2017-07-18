// The macros in the HelperMacros.h header file are intended to make it easier to create/define test suites.
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestCase.h>

class TestAnimal : public CppUnit::TestCase
{
   CPPUNIT_TEST_SUITE(TestAnimal);
   CPPUNIT_TEST(testGetName);
   CPPUNIT_TEST(testGetWeight);
   CPPUNIT_TEST(testGetFood);
   CPPUNIT_TEST(testGetInfo);
   CPPUNIT_TEST(testSetName);
   CPPUNIT_TEST(testSetWeight);
   CPPUNIT_TEST(testFeed);
   CPPUNIT_TEST_SUITE_END();

   void testGetName();
   void testGetWeight();
   void testGetFood();
   void testGetInfo();

   void testSetName();
   void testSetWeight();
   void testFeed();
};