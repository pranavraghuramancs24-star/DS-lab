#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void createList(struct Node** head, int data)
{
    struct Node* newNode = createNode(data);

    if (*head == NULL)
        {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}
void insertLeft(struct Node** head, int target, int data)
{
    struct Node* temp = *head;

    while (temp != NULL && temp->data != target)
        temp = temp->next;

    if (temp == NULL)
        {
        printf("Node with value %d not found!\n", target);
        return;
    }

    struct Node* newNode = createNode(data);

    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = newNode;
    else
        *head = newNode;

    temp->prev = newNode;
}
void deleteNode(struct Node** head, int value)
{
    struct Node* temp = *head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL)
        {
        printf("Value %d not found in list!\n", value);
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        *head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Node %d deleted successfully.\n", value);
}
void display(struct Node* head)
{
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main()
{
    struct Node* head = NULL;
    int choice, val, target;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Create/Insert at End\n");
        printf("2. Insert to Left of Node\n");
        printf("3. Delete Node by Value\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                createList(&head, val);
                break;

            case 2:
                printf("Insert value: ");
                scanf("%d", &val);
                printf("To the left of node with value: ");
                scanf("%d", &target);
                insertLeft(&head, target, val);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                deleteNode(&head, val);
                break;

            case 4:
                display(head);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
