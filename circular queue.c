#include <stdio.h>
#define N 5

int queue[N];
int rear = -1;
int front = -1;

void push(int x)
{
    if ((rear + 1) % N == front)
    {
        printf("queue overflow\n");
        return;
    }
    else if (front == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
}

void pop()
{
    if (front == -1)
    {
        printf("queue underflow\n");
        return;
    }
    else if (front == rear)
    {
        printf("Popped element: %d\n", queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("Popped element: %d\n", queue[front]);
        front = (front + 1) % N;
    }
}

void display()
{
    if (rear == -1)
    {
        printf("queue is empty\n");
        return;
    }
    printf("queue elements: ");
    for (int i = front; i != rear;i=(i + 1) % N)
    {
        printf("%d ", queue[i]);
    }
    printf("%d ", queue[rear]);
    printf("\n");
}

int main()
{
    int x;
    int element;

    printf("\n1: Enque  2: Deque  3: Display  4: Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &x);

    while (x != 5)
    {
        switch (x)
        {
        case 1:
            printf("Enter an element to insert ");
            scanf(" %d", &element);
            push(element);
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Exiting...\n");
            return;

        default:
            printf("Wrong choice! Please try again.\n");
            break;
        }
        printf("Enter your choice: ");
        scanf("%d", &x);
    }

    return 0;
}
