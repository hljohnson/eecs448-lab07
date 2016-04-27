/**
*	@file main.cpp
*	@author Hannah Johnson
*	@date 4/25/2016
*	@brief Main function that will call the test function on the linked list class
*/


#include <iostream>
#include <vector>

#include "Test.h"

int main() {
  Test<int> myTester;
  // Run test suite
  myTester.runTestSuite();

}
