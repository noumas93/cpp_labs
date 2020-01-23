// This test program uses a test framework supporting TDD and BDD.
// You are not required to use the framework, but encouraged to.
// Code:
// https://github.com/philsquared/Catch.git
// Documentation:
// https://github.com/philsquared/Catch/blob/master/docs/tutorial.md

// You ARE however required to implement all test cases outlined here,
// even if you do it by way of your own function for each case.  You
// are recommended to solve the cases in order, and rerun all tests
// after you modify your code.

// This define lets Catch create the main test program
// (Must be in only one place!)
#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"
#include "Sorted_List.h"
#include <random>

//=======================================================================
// Test cases
//=======================================================================

TEST_CASE( "Tesing an empty list" ) {
  Sorted_List list{};
  REQUIRE(list.is_empty() == true );
  REQUIRE(list.size() == 0 );

}

TEST_CASE("Insert some values and remove it") {
  Sorted_List list{};
  list.insert(1);
  CHECK(list.size() == 1 );
  list.insert(9);
  CHECK(list.size() == 2 );
  list.insert(2);
  CHECK(list.size() == 3 );
  list.insert(3);
  CHECK(list.print() == "1239");
  CHECK(list.size() == 4 );
  list.remove(2);
  CHECK(list.print() == "139");
  list.remove(1);
  list.remove(9);
  list.remove(3);
  CHECK(list.size() == 0 );
  CHECK(list.print() == "");
  CHECK( list.is_empty() == true );
}


TEST_CASE("test deep copy constructor") {
  Sorted_List list{};
  list.insert(5);
  list.insert(2);
  list.insert(3);
  list.insert(1);
  list.insert(9);
CHECK(list.print() == "12359");
Sorted_List newList(list);
CHECK(newList.print() == "12359");
newList.insert(4);
CHECK(newList.print() == "123459");
CHECK(list.print() == "12359");
}



TEST_CASE("test '=' operator ") {
  Sorted_List list{};
  list.insert(5);
  list.insert(2);
  list.insert(3);
  list.insert(1);
  list.insert(9);
CHECK(list.print() == "12359");
Sorted_List newList = list;
CHECK(newList.print() == "12359");
newList.insert(4);
CHECK(newList.print() == "123459");
CHECK(list.print() == "12359");

}
 


TEST_CASE("test move function ") {
  Sorted_List list{};
  list.insert(5);
  list.insert(2);
  list.insert(3);
  list.insert(1);
  list.insert(9);
CHECK(list.print() == "12359");
Sorted_List newList{};
newList = std::move(list);
CHECK(newList.print() == "12359");
CHECK(list.print() == "");
}

TEST_CASE("Test move constructor") {
Sorted_List list{};
  list.insert(5);
  list.insert(2);
  list.insert(3);
  list.insert(1);
  list.insert(9);
  Sorted_List newList{std::move(list)};
  CHECK(newList.print() == "12359");
}

// It is your job to create new test cases and fully test your Sorted_List class
