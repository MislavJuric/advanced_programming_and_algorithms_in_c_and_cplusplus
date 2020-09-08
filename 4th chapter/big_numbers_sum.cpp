/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 148

  The task is to sum up two numbers (each of which has less than 1000 digits).

  The solution generated here is mine, before looking at the book's solution.
*/

#include <iostream>
#include <deque>
#include <string>

using namespace std;

constexpr char ASCII_OFFSET = 48;

int main()
{
  string first_number_str;
  string second_number_str;
  deque<int> first_number_vec; // could have used char instead of int to save space
  deque<int> second_number_vec;
  cin >> first_number_str >> second_number_str;
  for (int i = 0; i < first_number_str.length(); i++)
  {
    int digit = int(first_number_str[i]) - ASCII_OFFSET;
    first_number_vec.push_back(digit);
  }
  cout << endl;
  for (int i = 0; i < second_number_str.length(); i++)
  {
    int digit = int(second_number_str[i]) - ASCII_OFFSET;
    second_number_vec.push_back(digit);
  }
  // number length check and correction
  if (first_number_vec.size() > second_number_vec.size())
  {
    int size_difference = first_number_vec.size() - second_number_vec.size();
    for (int i = 0; i < size_difference; i++)
    {
      second_number_vec.push_front(0);
    }
  }
  if (second_number_vec.size() > first_number_vec.size())
  {
    int size_difference = second_number_vec.size() - first_number_vec.size();
    for (int i = 0; i < size_difference; i++)
    {
      first_number_vec.push_front(0);
    }
  }
  // go from the last digit to the first digit and add them up; keep track of the leftovers
  deque<int> result;
  int carryover = 0;
  for (int i = first_number_vec.size() - 1; i >= 0; i--)
  {
    int sum = first_number_vec[i] + second_number_vec[i] + carryover;
    int digit = 0;
    if (sum >= 10)
    {
      digit = sum % 10;
      carryover = sum / 10;
    }
    else
    {
      digit = sum;
      carryover = 0;
    }
    result.push_front(digit);
  }
  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i];
  }
  cout << endl;
  return 0;
}
