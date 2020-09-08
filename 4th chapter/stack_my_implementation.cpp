/*
  My stack pointer-based implementation before looking at the solution from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 167

  Not the most optimal, just a crude implementation.
*/

#include <iostream>

using namespace std;

template <typename T>
class Stack
{
  private:
    
  struct Element
  {
    T value;
    Element* next;
  };

  Element *stack_top = nullptr;
  
  public:

  Stack() { }

  void push(T new_value) // could have used a different return type
  {
    Element *new_element = new Element;
    new_element->value = new_value;
    new_element->next = stack_top;
    stack_top = new_element;
  }

  T pop()
  {
    Element *head = stack_top;
    if (head == nullptr)
    {
      cout << "Stack empty- can't pop" << endl;
      return -1;
    }
    stack_top = stack_top->next;
    T head_value = head->value;
    delete head;
    return head_value;
  }
};

int main()
{
  Stack<int> s = Stack<int>();
  s.push(1);
  s.push(2);
  s.push(3);
  cout << s.pop() << " " << s.pop() << endl;
  s.pop();
  s.pop();
  return 0;
}
