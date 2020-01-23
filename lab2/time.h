#ifndef time_H
#define time_H
using namespace std;
#include <string>
 
struct Time {
  int Hours{};
  int Minutes{};
  int Seconds{};
 
};
bool is_valid(Time const& t);
string to_string(Time const& t,bool timeFormat);
bool is_am(Time const& t);
Time add_time(Time const& arg1,Time const& arg2);
Time int_to_time(int const& value);
Time operator+(Time const& t, int sec);
Time& operator++(Time& t);
Time operator++(Time& t,int);

Time operator-(Time const& t, int sec);
Time& operator--(Time& t);
Time operator--(Time& t,int);

bool operator<(Time const& left, Time const& right);
bool operator>(Time const& left, Time const& right);
bool operator==(Time const& left, Time const& right);
bool operator<=(Time const& left, Time const& right);
bool operator>=(Time const& left, Time const& right);
bool operator!=(Time const& left, Time const& right);

ostream& operator<<(ostream& stream, Time const& t);
istream& operator>>(istream& stream, Time& t);

#endif
