/*
  My queue array-based implementation before looking at the solution from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 165

  Not the most optimal, just a crude implementation.
*/

#include <iostream>

using namespace std;

constexpr int NUMBER_OF_ELEMENTS = 100;

template<class T>
class Queue
{
  private:
  
    T arr[NUMBER_OF_ELEMENTS];
    int last_index_enter = 0;
    int last_index_exit = 0;
  
  public:

  Queue(T arr_arg[], int arr_len)
    {
      for (int i = 0; i < arr_len; i++)
      {
	arr[i] = arr_arg[i];
	last_index_enter++;
      }
    }
  
    void enterQueue(T new_element)
    {
      if ((last_index_enter + 1) >= NUMBER_OF_ELEMENTS)
      {
	cout << "Too many elements in the queue already. Operation not succesful." << endl;
	return;
      }
      arr[last_index_enter] = new_element;
      last_index_enter++;
    }

    T exitQueue() // returns the first element in the queue
    {
      if (last_index_exit == last_index_enter)
      {
	// the queue is emptied, let's restart the indicies
	last_index_enter = 0;
	last_index_exit = 0;
	return arr[last_index_exit];
      }
      last_index_exit++;
      return arr[last_index_exit - 1];
    }

    void printQueue()
    {
      for (int i = last_index_exit; i < last_index_enter; i++)
      {
	cout << arr[i] << " ";
      }
      cout << endl;
    }
};

  

int main()
{
  int arr[5] = {1, 2, 3, 4, 5};
  Queue<int> q(arr, 5);
  q.printQueue();
  q.enterQueue(6);
  q.printQueue();
  int number = q.exitQueue();
  cout << number << endl;
  q.printQueue();
  q.exitQueue();
  q.printQueue();
  q.exitQueue();
  q.printQueue();
  q.exitQueue();
  q.printQueue();
  q.exitQueue();
  q.printQueue();
  q.exitQueue();
  q.printQueue();
  q.enterQueue(1);
  q.printQueue();
  return 0;
}
