#include <stdio.h>
#define MAX 5
int queue_array[MAX];
int rear = -1;
int front = -1;
void display()
{
    int i;
    if (front == -1)
        printf("Queue is empty\n");
    else
    {
        printf("Queue is:\n");
        for (i = front; i <= rear; i++)
            printf("%d \n", queue_array[i]);
    }
}
void insert()
{
    int add_item;
    if (rear == MAX - 1)
        printf("Queue Overflow \n");
    else
    {
        if (front == -1)
            front = 0;
        printf("Insert the element in queue: ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
}
void delete()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return;
    }
    else
    {
        printf("Deleted element is: %d\n", queue_array[front]);
        front = front + 1;
    }
}
void main()
{
    int choice;
    while (1)
    {
        printf("1.enque\n");
        printf("2.deque\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;

        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("Invalid choice \n");
        }
    }
}
