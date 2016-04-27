/**
*	@file Test.h
*	@author Hannah Johnson
*	@date 4/25/2016
*	@brief A header file for templated Test class which implements unit tests for the
* linked in class
*/

#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <vector>

#include "LinkedList.h"

template <typename T>
class Test
{
	public:
    void runTestSuite();

  private:
    // Methods for testing the Linked List Class
    void isEmpty_emptyList();
    void size_emptyList();
    void addBack_addOneToEmpty();
    void addFront_addOneToEmpty();
    void size_nonEmptyList();
    void isEmpty_nonEmptyList();
    void addBack_multipleAdds();
    void addFront_multipleAdds();
    void removeBack_removeOnlyElement();
    void removeFront_removeOnlyElement();
    void removeBack_removeFromNonEmpty();
    void removeFront_removeFromNonEmpty();
    void search_emptyList();
    void search_valuePresent();
    void search_valueNotPresent();
		void addBack_compare();

};

#include "Test.hpp"

#endif
