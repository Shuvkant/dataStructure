/*This is a simple program for queue without shifting */
#include <iostream>
#include <iomanip>
#include <cstdio>
#define size 5
// using namespace std;
struct queue
{
    int data[size];
    int rear;
    int front;
};
void Enqueue(queue *q) //
{
    if (q->rear == size - 1)
        std::cout << "Queue is full" << std::endl;
    else
    {
        (q->rear)++;
        std::cout << "Enter the data: ";
        std::cin >> q->data[q->rear];
        std::cout << q->data[q->rear] << "enqued";
    }
}
void Dequeue(queue *q)
{
    if (q->front > q->rear)
    {
        std::cout << "Queue is empty" << std::endl;
        return;
    }
    else
    {
        std::cout << q->data[q->front] << " is dequed";
        (q->front)++;
    }
}

void Display(queue *q)
{
    int i;
    if (q->front > q->rear)
        std::cout << "Queue is empty";
    else
    {
        std::cout << "The numbers in the queue are:\n";
        for (i = q->front; i <= q->rear; i++)
        {
            std::cout << q->data[i] << "\t";
        }
        std::cout << std::endl;
    }
}
void dequeueShifting(queue *q)
{
    if (q->front > q->rear)
    {

        std::cout << "Queue is empty" << std::endl;
        return;
    }

    else
    {
        for (int i = q->front; i < q->rear; i++)
        {
            q->data[i] = q->data[i + 1];
        }
        (q->rear)--;
    }
}

int main()
{
    int choice;
    struct queue q;
    q.front = 0;
    q.rear = -1;
    while (1)
    {
        // getchar();
        // getchar();
        system("clear");
        std::cout << "1.Enqueue\n2.Dequeue\n3.Dequeue(with shifting)\n4.Display\n5.Exit " << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            Enqueue(&q);
            // getchar();
            break;

        case 2:
            Dequeue(&q);
            break;
        case 3:
            dequeueShifting(&q);
            break;

        case 4:
            Display(&q); //
            break;
        case 5:
            exit(0);
        default:
            std::cout << "Invalid Input";
        }
        std::cin.ignore(); // to ignore the newline character
        std::cin.get();    // to wait for the user to press enter
    }

    return 0;
}