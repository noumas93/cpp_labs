#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "time.h"


TEST_CASE("    "){
  Time validtime1 {15,14,13};
  Time validtime2 {11,00,00};
  Time invalidtime1 {42,99,70};
  Time invalidtime2 {-1,-1,-1};
  Time operatorTime1 {};
  Time operatorTime2 {};
  Time operatorTime3 {};
  SECTION("Testing valid time"){
  CHECK(is_valid(validtime1));
  CHECK(is_valid(validtime2));
  }

  SECTION("Testing invalid time"){
  CHECK_FALSE(is_valid(invalidtime1));
  CHECK_FALSE(is_valid(invalidtime2));
  }

  SECTION("Testing to_string"){
  CHECK(to_string(validtime1,true)== "15:14:13 pm");
  CHECK_FALSE(to_string(validtime1,false)== "15:14:12");
  CHECK(to_string(validtime2,true)== "11:00:00 am");

  SECTION("Testing is_am") {
  CHECK_FALSE(is_am(validtime1));
  CHECK(is_am(validtime2));
  }

  SECTION ("Testing operators: +, -, ++, --") {

  //Testing +
  operatorTime1 = {23,59,59};
  operatorTime1 = operatorTime1 + 1;
  CHECK(to_string(operatorTime1,false) == "00:00:00");
  operatorTime1 = operatorTime1 + 259200;
  CHECK(to_string(operatorTime1,false) == "00:00:00");
  //Testing -
  operatorTime2 = {0,0,0};
  operatorTime2 = operatorTime2 - 1;
  CHECK(to_string(operatorTime2,false) == "23:59:59");
  operatorTime2 = operatorTime2 - 259200;
  CHECK(to_string(operatorTime2,false) == "23:59:59");

  //Testing ++

  operatorTime1 = {0,0,0};
  ++operatorTime1;
  CHECK(to_string(operatorTime1,false) == "00:00:01");
  operatorTime1++;
  CHECK(to_string(operatorTime1,false) == "00:00:02");

  //Testing --

  operatorTime1 = {0,0,0};
  --operatorTime1;
  CHECK(to_string(operatorTime1,false) == "23:59:59");
  operatorTime1--;
  CHECK(to_string(operatorTime1,false) == "23:59:58");
  }

  
  SECTION ("Testing comparison: <, >, =<, >=, ==, !=") {
  operatorTime1 = {12,12,12};
  operatorTime2 = {12,10,00};
  CHECK(operatorTime1 > operatorTime2);
  CHECK(operatorTime1 >= operatorTime2);
  CHECK_FALSE(operatorTime1 < operatorTime2);
  CHECK_FALSE(operatorTime1 <= operatorTime2);
  CHECK(operatorTime1 != operatorTime2);
  CHECK_FALSE(operatorTime1 == operatorTime2); // new test
  operatorTime3 = {12,12,12};
  CHECK(operatorTime1 <= operatorTime3);
  CHECK(operatorTime1 >= operatorTime3);
  CHECK(operatorTime1 == operatorTime3);
  CHECK_FALSE(operatorTime3 != operatorTime1); // new test
  CHECK_FALSE(operatorTime1 > operatorTime3); // new test
  CHECK_FALSE(operatorTime3 > operatorTime1); // new test



  }

  SECTION("Input Output stream tests") {
  Time streamTime{10,10,10};
  ostringstream outStream;
  outStream << to_string(streamTime,false);
  CHECK(outStream.str() == "10:10:10");
  CHECK_FALSE(outStream.str() == "25:10:10"); // new test
  istringstream inStream{"11:11:11"};
  inStream >> streamTime;
  CHECK(to_string(streamTime,false) == "11:11:11");
  CHECK(to_string(streamTime,true) == "11:11:11 am"); // new test
  CHECK_FALSE(to_string(streamTime,true) == "12:11:11 am"); // new test
  CHECK_FALSE(to_string(streamTime,true) == "11:11:11"); // new test

  }
  }
}
