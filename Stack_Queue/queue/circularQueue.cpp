#include <iostream>
#include <cstdlib>
#include <iomanip>
#define size 5
struct queue
{
    int data[size];
    int rear;
    int front;
} s;
void Enqueue(struct queue *s)
{
    int item;
    if ((s->rear + 1) % size == s->front)
    {
        std::cout << "Queue is full\n";
        return;
    }
    else
    {
        std::cout << "Enter the element: ";
        std::cin >> item;
        if (s->rear == -1)
        {
            s->rear = 0;
            s->front = 0;
        }
        else
        {
            s->rear = (s->rear + 1) % size;
        }
        s->data[s->rear] = item;
        std::cout << "Enqueued element is: " << item << std::endl;
    }
}
void Dequeue(struct queue *s)
{
    int item;
    if (s->front == -1)
    {
        std::cout << "Queue is empty\n";
        return;
    }
    else
    {
        item = s->data[s->front];
        if (s->front == s->rear)
        {
            s->front = -1;
            s->rear = -1;
        }
        else
        {
            s->front = (s->front + 1) % size;
        }
        std::cout << "Deleted element is: " << item << std::endl;
    }
}
void Display(struct queue *s)
{
    int i;
    if (s->front == -1)
    {
        std::cout << "Queue is empty\n";
        return;
    }
    else
    {
        std::cout << "Queue elements are:\n";
        for (i = s->front; i != s->rear; i = (i + 1) % size)
        {
            std::cout << s->data[i] << std::endl;
        }
        std::cout << s->data[i] << std::endl;
    }
}
int main()
{
    int choice;
    s.rear = -1;
    s.front = -1;
    while (1)
    {
        system("clear");
        std::cout
            << "1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            Enqueue(&s);
            break;
        case 2:
            Dequeue(&s);
            break;
        case 3:
            Display(&s);
            break;
        case 4:
            exit(0);
        default:
            std::cout << "Invalid choice\n";
        }
        std::cin.ignore();
        std::cin.get();
    }
    return 0;
}
