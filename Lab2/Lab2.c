#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int value;
    struct Node * next;
} Node;

Node *create_node(int value)
{
    Node *new_node;
    new_node = malloc(sizeof(struct Node));
    if (new_node != NULL)
    {
        new_node->value = value;
        new_node->next = NULL;
    }
    printf("ptr=%d info=%d next=%d\n", new_node, new_node->value, new_node->next);
    return new_node;
}

Node *add_node(Node *head, int value)
{
    struct Node *new_node;
    new_node = malloc(sizeof(struct Node));
    if (new_node != NULL)
    {
        new_node->value = value;
        new_node->next = head;
    }
    printf("ptr=%d info=%d next=%d \n", new_node, new_node->value, new_node->next);
    return new_node;
}

Node * delete_head(Node *head) 
{
    struct Node *new_head;
    if (head)
    {
        printf("ptr=%d info=%d next=%d \n", head, head->value, head->next);
        new_head = head->next;
        free(head);
    }
    return new_head;
}

int main()
{
    struct Node *head = create_node(10);
    head = add_node(head, 20);
    head = add_node(head, 30);

    printf(" ptr = %d \n", head);

    head = delete_head(head);
    head = delete_head(head);
    head = delete_head(head);

    printf(" ptr = %d \n", head);
    return 0;
}