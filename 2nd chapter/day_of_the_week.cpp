/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 96
  Exercise text translated from Croatian to English by me.

  Make a program that inputs day.month.year and prints which day in the week it is.
  The inputted date will be after 1.1.1900.

  1.1.1990. was Monday

  This solution was generated after looking at the book's solution and trying to re-create it.
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
  int day, month, year;
  char dot;
  cin >> day >> dot >> month >> dot >> year;
  int months[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int additions[12] {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  string days[7] {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
  int offset = 0;
  for (int i = 1990; i < year; i++)
  {
    if ((((i % 4) == 0) && ((i % 100) != 0)) || (i % 400) == 0)
    {
      offset += 366;
    }
    else
    {
      offset += 365; // number of days in a year
    }
  }
  for (int i = 1; i < month; i++)
  {
    if ((((year % 4) == 0) && ((year % 100) != 0)) || (year % 400) == 0)
    {
      offset += months[i - 1] + additions[i - 1];
    }
    else
    {
      offset += months[i - 1];
    }
  }
  offset += (day - 1);
  cout << days[offset % 7] << endl;
}


