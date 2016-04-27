/**
*	@author Hannah Johnson
*	@date 4/25/2016
*	@file Test.hpp
* @brief Implements unit tests for Linked List
*/

template <typename T>
void Test<T>::runTestSuite() {
  std::cout << "Running test suite...\n";

  isEmpty_emptyList();
  std::cout << "---------------------------------------------------------\n";
  size_emptyList();
  std::cout << "---------------------------------------------------------\n";
  addBack_addOneToEmpty();
  std::cout << "---------------------------------------------------------\n";
  addFront_addOneToEmpty();
  std::cout << "---------------------------------------------------------\n";
  isEmpty_nonEmptyList();
  std::cout << "---------------------------------------------------------\n";
  size_nonEmptyList();
  std::cout << "---------------------------------------------------------\n";
  addBack_multipleAdds();
  std::cout << "---------------------------------------------------------\n";
  addFront_multipleAdds();
  std::cout << "---------------------------------------------------------\n";
  removeBack_removeOnlyElement();
  std::cout << "---------------------------------------------------------\n";
  removeFront_removeOnlyElement();
  std::cout << "---------------------------------------------------------\n";
  removeBack_removeFromNonEmpty();
  std::cout << "---------------------------------------------------------\n";
  removeFront_removeFromNonEmpty();
  std::cout << "---------------------------------------------------------\n";
  search_valueNotPresent();
  std::cout << "---------------------------------------------------------\n";
  search_valuePresent();
  std::cout << "---------------------------------------------------------\n";
  search_emptyList();
  std::cout << "---------------------------------------------------------\n";
  addBack_compare();
}

template <typename T>
void Test<T>::isEmpty_emptyList(){
  // Create a list, size should be 0
  LinkedList<T> myList;

  // If an isEmpty method call on empty list returns false, then test failed
  if(myList.isEmpty() == false) { std::cout << "Test 1 Failed: isEmpty method called on empty list returns false.\n"; }
  else { std::cout << "Test 1 Passed: isEmpty method called on empty list returns true.\n"; }
}

template <typename T>
void Test<T>::isEmpty_nonEmptyList(){
  // Create a list, add a value to that list, size should now be 1
  LinkedList<T> myList;
  myList.addFront(1);

  // If an isEmpty method call on a non-empty list returns true, then test failed
  if(myList.isEmpty() == true) { std::cout << "Test 2 Failed: isEmpty method called on non-empty list returns true.\n"; }
  else { std::cout << "Test 2 Passed: isEmpty method called on non-empty list returns false.\n"; }

}

template <typename T>
void Test<T>::addBack_addOneToEmpty() {
  // Create empty list, add one element to it using addBack,then convert to vector using working function
  LinkedList<T> myList;
  myList.addBack(1);
  std::vector<int> testVector = myList.toVector();

  // Create a vector, add one element to it using push_back
  std::vector<int> correctVector;
  correctVector.push_back(1);

  // Correct vector will be vector of size 1 containing 1, if test vector equals this, test passes because
  // addBack worked for adding 1 element to empty list
//  if(testVector != correctVector) { std::cout << "Test 3 Failed: expected results after addBack call on empty list: " << correctVector << "yielded results: " << testVector << "\n"; }
   if(testVector != correctVector) { std::cout << "Test 3 Failed\n";}
   else { std::cout << "Test 3 Passed: addBack call on empty list produced desired results \n";}
}

template <typename T>
void Test<T>::addFront_addOneToEmpty() {
  // Create empty list, add one element to it using addBack, then convert to vector using working function
  LinkedList<T> myList;
  myList.addFront(1);
  std::vector<int> testVector = myList.toVector();

  // Create a vector, add one element to it using push_back
  std::vector<int> correctVector;
  correctVector.push_back(1);

  // Correct vector will be vector of size 1 containing 1, if test vector equals this, test passes because
  // addFront worked for adding 1 element to empty list
//  if(testVector != correctVector) { std::cout << "Test 4 Failed: expected results after addFront call on empty list: " << correctVector << " yielded results: " << testVector << "\n";  }
  if(testVector != correctVector) { std::cout << "Test 4 Failed\n";}
  else { std::cout << "Test 4 Passed: addFront call on empty list produced desired results \n"; }
}

template <typename T>
void Test<T>::size_emptyList() {
  // Create a list, size will be 0
  LinkedList<T> myList;

  // If size method call on empty list returns with non-zero num, test fails
  if(myList.size() != 0) { std::cout << "Test 5 Failed: expected results for size call on empty list: 0 yielded results: " << myList.size() << "\n"; }
  else { std::cout << "Test 5 Passed: size method call on empty list returns 0 \n";}
}

template <typename T>
void Test<T>::size_nonEmptyList() {
  // Create empty list, add one element to it using addBack
  LinkedList<T> myList;
  myList.addBack(1);

  // Create test vector with one element
  std::vector<int> testVector;
  testVector.push_back(1);

  // If size method call on list size 1 does not equal the size of a 1 element vector, test fails
  if(myList.size() != testVector.size()) { std::cout << "Test 6 Failed: expected results for size call on list of size 1: " << testVector.size() << " yielded results: " << myList.size() << "\n"; }
  else { std::cout << "Test 6 Passed: size method call on list of size 1 returns 1\n"; }
}

template <typename T>
void Test<T>::addBack_multipleAdds() {
  // Create a list, add 100 elements, then convert to vector
  LinkedList<int> myList;
  for(int idx = 0; idx < 100; idx++) {
    myList.addBack(idx);
  }
  std::vector<int> testVector = myList.toVector();

  // Create a vector with 100 elements
  std::vector<int> correctVector;
  for(int idx = 0; idx < 100; idx++) {
    correctVector.push_back(idx);
  }

  if(testVector != correctVector) {
    std::cout << "Test 7 Failed: Multiple addBack calls on an empty list gave not desired results\n";
    std::cout << "Expected Results: ";
    for(int idx = 0; idx < 100; idx++) { std::cout << correctVector[idx] << ", "; }
    std::cout << "\n";
    std::cout << "Yielded Results: ";
    for(int idx = 0; idx < 100; idx++) { std::cout << testVector[idx] << ", "; }
    std::cout << "\n";
  }
  else { std::cout << "Test 7 Passed: Multiple addBack calls on an empty list gave desired results \n";}

}

template <typename T>
void Test<T>::addFront_multipleAdds() {
  // Create a list, add 100 elements, then convert to vector
  LinkedList<int> myList;
  for(int idx = 0; idx < 100; idx++) {
    myList.addFront(idx);
  }
  std::vector<int> testVector = myList.toVector();

  // Create a vector with 100 elements
  std::vector<int> correctVector;
  for(int idx = 0; idx < 100; idx ++) {
    correctVector.push_back(99-idx);
  }

  if(testVector != correctVector) {
    std::cout << "Test 8 Failed: Multiple addFront calls on an empty list gave not desired results\n";
    std::cout << "Expected Results: ";
    for(int idx = 0; idx < 100; idx++) { std::cout << correctVector[idx] << ", "; }
    std::cout << "\n";
    std::cout << "Yielded Results: ";
    for(int idx = 0; idx < 100; idx++) { std::cout << testVector[idx] << ", "; }
    std::cout << "\n";
  }
  else { std::cout << "Test 8 Passed: Multiple addFront calls on an empty list gave desired results\n";}
}

template <typename T>
void Test<T>::removeBack_removeOnlyElement() {
  // Create a list, add one element, remove one element using removeBack, then convert to vector
  LinkedList<int> myList;
  myList.addBack(1);
  myList.removeBack();
  std::vector<int> testVector = myList.toVector();

  // Create an empty vector
  std::vector<int> correctVector;

  if(testVector != correctVector) { std::cout << "Test 9 Failed: removeBack from list of 1 did not produce desired results\n"; }
  else { std::cout << "Test 9 Passed: removeBack from list of 1 produced desired results\n";}
}

template <typename T>
void Test<T>::removeFront_removeOnlyElement() {
  // Create a list, add one element, remove one element using removeFront, the nconvert to vector
  LinkedList<int> myList;
  myList.addFront(1);
  myList.removeBack();
  std::vector<int> testVector = myList.toVector();

  // Create an empty vector
  std::vector<int> correctVector;

  if(testVector != correctVector) { std::cout << "Test 10 Failed: removeFront from list of 1 did not produced desired results \n"; }
  else { std::cout << "Test 10 Passed: removeFront from list of 1 produced desired results \n"; }
}

template <typename T>
void Test<T>::removeBack_removeFromNonEmpty() {
  // Create a list, add multiple elements, remove on element using removeBack, then convert to vector
  LinkedList<int> myList;
  for(int idx = 0; idx < 10; idx++) {
    myList.addFront(idx);
  }
  myList.removeBack();
  std::vector<int> testVector = myList.toVector();

  // Create a vector, add elements except one less than was added to list to simulate removal
  std::vector<int> correctVector;
  for(int idx = 0; idx < 9; idx++) {
    correctVector.push_back(9-idx);
  }

  if(testVector != correctVector) {
    std::cout << "Test 11 Failed: removeBack call from list of multiple elements did not produce desired results \n";
    std::cout << "Expected results: ";
    for(int idx = 0; idx < correctVector.size(); idx++) {
     std::cout << correctVector[idx] << ", ";
    }
    std::cout << "\n";
    std::cout << "Yielded results: ";
    for(int idx = 0; idx < testVector.size(); idx++) {
      std::cout << testVector[idx] << ", ";
    }
    std::cout << "\n";
  }
  else { std::cout << "Test 11 Passed: removeBack call from list of multiple elements produced desired results \n"; }
}

template <typename T>
void Test<T>::removeFront_removeFromNonEmpty() {
  // Create a list, add multiple elements, remove one element using removeFront, then convert to vector
  LinkedList<int> myList;
  for(int idx = 0; idx < 10; idx++) {
    myList.addFront(idx);
  }
  myList.removeFront();
  std::vector<int> testVector = myList.toVector();

  // Create a vector, add elements except one less than was added to list to simulate removal
  std::vector<int> correctVector;
  for(int idx = 0; idx < 9; idx++) {
    correctVector.push_back(8-idx);
  }

  if(testVector != correctVector) {
    std::cout << "Test 12 Failed: removeFront call from list of multiple elements didn't produce desired results \n";
    std::cout << "Expected Results: ";
    for(int idx = 0; idx < correctVector.size(); idx++) {
      std::cout << correctVector[idx] << ", ";
    }
    std::cout << "\n";
    std::cout << "Yielded Results: ";
    for(int idx = 0; idx < testVector.size(); idx++) {
      std::cout << testVector[idx] << ", ";
    }
    std::cout << "\n";
  }
  else { std::cout << "Test 12 Passed: removeFront call from list of multiple elements produced desired results \n"; }
}

template <typename T>
void Test<T>::search_emptyList() {
  // Create empty list
  LinkedList<int> myList;

  if(myList.search(1) == true) { std::cout << "Test 13 Failed: search method call on empty list returned true \n"; }
  else { std::cout << "Test 13 Passed: search method call on empty list returned false \n"; }

}

template <typename T>
void Test<T>::search_valuePresent() {
  // Create list with several values, search for value present in list
  LinkedList<int> myList;
  for(int idx = 0; idx < 10; idx++) {
    myList.addFront(idx);
  }

  if(myList.search(5) == false) { std::cout << "Test 14 Failed: search method call on list containing specified value returned false \n"; }
  else { std::cout << "Test 14 Passed: search method call on list containing specified value returned true \n"; }
}

template <typename T>
void Test<T>::search_valueNotPresent() {
  // Create list with several values, search for value not present in list
  LinkedList<int> myList;
  for(int idx = 0; idx < 10; idx++) {
    myList.addFront(idx);
  }

  if(myList.search(100) == true) { std::cout << "Test 15 Failed: search method call on list not containing specified value returned true \n"; }
  else { std::cout << "Test 15 Passed: search method call on list not containing specified value returned false \n"; }
}

template <typename T>
void Test<T>::addBack_compare() {
  // Create list with several values then turn into vector
  LinkedList<int> myList;
  for(int idx = 0; idx < 5; idx++) { myList.addBack(idx); }
  std::vector<int> myVector = myList.toVector();

  // Create another list with several values then turn into vector
  LinkedList<int> mySecondList;
  for(int idx = 0; idx < 5; idx++) { mySecondList.addBack(5-idx); }
  std::vector<int> mySecondVector = mySecondList.toVector();

  std::cout << "Test 16: addBack comparison: \n";
  std::cout << "On first list, expected results: 0,1,2,3,4\n";
  std::cout << "Yielded results: ";
  for(int idx = 0; idx < 5; idx++) { std::cout << myVector[idx] << ", "; }
  std::cout << "\n";
  std::cout << "On the second list, expected results: 5,4,3,2,1\n";
  std::cout << "Yielded results: ";
  for(int idx = 0; idx < 5; idx++) { std::cout << mySecondVector[idx] << ", "; }
  std::cout << "\n";

}
