#include "time.h"
#include <string>
#include <iostream>
#include <iomanip>
#include "stdio.h"
using namespace std;


bool is_valid (Time const& t) {

  if (t.Hours < 0 || t.Hours > 24) {
    return false;
    }
  if (t.Minutes < 0 || t.Minutes > 60) {
     return false;
   }
  if (t.Seconds < 0 || t.Seconds > 60) {
    return false;
   }
return true;
};



string fill_With_Zero(int const& number) {
  string val;
  if(number < 10) {
    val = "0" + to_string(number);
    return val;
  } else {
    return to_string(number);
  }
}


string to_string(Time const& t,bool is_am_format) {

  string hourString{};
  hourString = to_string(t.Hours);
  if (t.Hours > 12 && is_am_format == true) {
    hourString = to_string(t.Hours-12);
  }

  
string timestring{};
timestring =  fill_With_Zero(t.Hours)+":"+fill_With_Zero(t.Minutes)+":"+fill_With_Zero(t.Seconds);
  if (is_am_format) {
      if (t.Hours >= 0 & t.Hours <= 12) {
        timestring.append(" am");
      }
      if (t.Hours > 12 & t.Hours <= 24) {
        timestring.append(" pm");
      }
  }
  return timestring;
}



bool is_am (Time const& t) {
  if (t.Hours >= 0 & t.Hours <= 12) {
        return true;
      }
      if (t.Hours > 12 & t.Hours <= 24) {
        return false;
      }
}

Time add_time(Time const& arg1,Time const& arg2) {
  Time finalTime{};
  int value{};
  int memory{};

  value = arg1.Seconds + arg2.Seconds;
  if (value > 59) {
    memory = 1;
    value -= 60;
  }
  finalTime.Seconds = value;

  value = arg1.Minutes + arg2.Minutes + memory;
  memory = 0;
  if (value > 59) {
    memory = 1;
    value-=60;
  }
  finalTime.Minutes = value;

  value = arg1.Hours + arg2.Hours + memory;
  memory = 0;

  if (value > 23) {
  memory = value / 24;
  value -= 24 * memory;
  }
  finalTime.Hours = value;
  return finalTime;
}


Time int_to_time(int const& value) {
  int hours{};
  int minutes{};
  int seconds{};
  int temp{};
  if (value < 60) {
    seconds = value;
  }
  else if (value >= 60 && value < 3600) {
    minutes = value/60;
    temp = value - (minutes*60);
    seconds = temp;
  }
  else if (value >= 3600) {
    hours = value/3600;
    temp = value - (hours*3600);
    if (temp > 60) {
    minutes = temp%60;
    temp = temp - (minutes*60);
    seconds = temp;
    }
    else {
      minutes = 0;
      seconds = temp;
    }

  }

  return Time{hours,minutes,seconds};
}


Time sub_time (Time const& arg1, Time const& arg2) {

Time finalTime{};
  int value{};
  int memory{};

  value = arg1.Seconds - arg2.Seconds;
  if (value < 0) {
    memory = 1;
    value += 60;
  }
  finalTime.Seconds = value;

  value = arg1.Minutes - arg2.Minutes - memory;
  memory = 0;
  if (value < 0) {
    memory = 1;
    value +=60;
  }
  finalTime.Minutes = value;

  value = arg1.Hours - arg2.Hours - memory;

  while (value < -24) {
    value += 24;
  }
  if (value < 0){
    value = value+24;
  }

  finalTime.Hours = value;
  return finalTime;

}

Time operator+(Time const& t, int sec) {
return add_time(t,int_to_time(sec));

}

Time operator-(Time const& t, int sec) {

return sub_time(t, int_to_time(sec));

}



Time& operator++(Time& t) {
  t = add_time(t,Time{0,0,1});
}

Time operator++(Time& t,int) {
  Time inputTime{t};
  t = add_time(t,Time{0,0,1});
  return inputTime;
}

Time& operator--(Time& t) {
  t = sub_time(t,Time{0,0,1});
}

Time operator--(Time& t,int) {
  Time inputTime{t};
  t = sub_time(t,Time{0,0,1});
  return inputTime;
}


bool operator<(Time const& arg1, Time const& arg2) {
    if(arg1.Hours > arg2.Hours) {
        return false;
    }
    if(arg1.Minutes > arg2.Minutes) {
        return false;
    }
    if(arg1.Seconds > arg2.Seconds) {
        return false;
    }
    return true;
}



bool operator>(Time const& arg1, Time const& arg2) {
    return !(arg1 < arg2);
}



bool operator==(Time const& arg1, Time const& arg2) {
    if (arg1.Hours == arg2.Hours &&
        arg1.Minutes == arg2.Minutes &&
        arg1.Seconds   == arg2.Seconds)
        {
          return true;
        }
        else
        {
          return false;
        }
}


bool operator<=(Time const& arg1, Time const& arg2) {
    return arg1 < arg2 || arg1 == arg2;
}

bool operator>=(Time const& arg1, Time const& arg2) {
    return arg1 > arg2 || arg1 == arg2;
}

bool operator!=(Time const& arg1, Time const& arg2) {
    return !(arg1 == arg2);
}

ostream& operator<<(ostream& stream, Time const& t) {
    stream << to_string(t, false) << endl;
    return stream;
}

istream& operator>>(istream& stream, Time& t) {
    stream >> t.Hours;
    stream.get();
    stream >> t.Minutes;
    stream.get();
    stream >> t.Seconds;

    if(!is_valid(t)) {
        stream.setstate(ios::failbit);
        cerr << "Incorrect time entered" << endl;
    }
    return stream;
}
