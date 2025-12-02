#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

int isEmpty()
{
    return front == -1 || front > rear;
}

void enqueue(int item)
{
    if (rear == MAX - 1)
    {
        printf("Queue is full\n");
    } else
    {
        rear = rear + 1;
        queue[rear] = item;
        if (front == -1)
        {
            front = 0;
        }
        printf("%d enqueued\n", item);
    }
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
    } else
    {
        int item = queue[front];
        printf("Deleted element: %d\n", item);
        front = front + 1;

        if (front > rear)
        {
            front = rear = -1;
        }
    }
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    display();

    enqueue(40);
    enqueue(50);
    enqueue(60);
    dequeue(60);
    dequeue(40);
    display();

    return 0;
}

