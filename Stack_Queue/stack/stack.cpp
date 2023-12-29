
/*This is a program that illustrates an example of stack*/
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#define size 5
// using namespace std;
struct stack
{
  int data[size];
  int top;
} s;
using namespace std;
void push()
{
  if (s.top == size - 1)
  {
    std::cout << "Stack overflow.";
  }
  else
  {
    (s.top)++;
    std::cout << "Enter the data: ";
    std::cin >> s.data[s.top];
    std::cout << s.data[s.top] << " is added";
  }
}
void pop()
{
  // cout << "You have popped";
  if (s.top == -1)

    std::cout << "Stack underflow";
  else
  {
    std::cout << "You have popped" << s.data[s.top];
    (s.top)--;
  }
}
void display()
{
  // cout << "You are displaying.";
  if (s.top == -1)
    std::cout << "Stack is empty";
  else
  {
    int i;
    std::cout << "The numbers in the stack are: " << std::endl;
    for (i = s.top; i >= 0; i--)
    {
      std::cout << s.data[i] << "\t";
    }
  }
}
int main()
{
  int choice;
  s.top = -1;
  while (1)
  {
    system("clear");
    std::cout << "1.Push\n2.Pop\n3.Display\n4.Exit" << endl;
    std::cout << "Enter your choice ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      push();
      break;
    case 2:
      pop();
      break;
    case 3:
      display();
      break;
    case 4:
      exit(0);
    default:
      cout << "Invalid choice";
    }

    std::cin.ignore();
    std::cin.get();
  }

  return 0;
}
