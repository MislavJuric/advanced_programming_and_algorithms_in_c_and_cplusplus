/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Pages 102-103
  Exercise text translated from Croatian to English by me.

  Implement binary search. Assumes sorted input

  This solution was generated after looking at the book's solution (because I had a bug).
*/

#include <iostream>

using namespace std;

int main()
{
	int P[10000];
	int searched_for_number;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> P[i];
	}
	cin >> searched_for_number;
	int lower_bound = 0;
	int upper_bound = (n - 1);
	while (lower_bound < upper_bound)
	{
	        int middle = (lower_bound + upper_bound) / 2;
		if (P[middle] >= searched_for_number)
		{
			upper_bound = middle;
		}
		else
		{
		        lower_bound = middle + 1; // + 1 here - that was the bug
		}
	}
	if (P[lower_bound] == searched_for_number)
	{
		cout << "Number exists. It is on index " << lower_bound << "." << endl;
	}
	else
	{
		cout << "The number doesn't exist." << endl;
	}
	return 0;
}
