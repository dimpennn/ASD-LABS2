#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int value;
    struct Node *next_p;
} Node;

Node *create_node(int value)
{
    Node *prev_p;
    prev_p = malloc(sizeof(struct Node));
    if (prev_p != NULL)
    {
        prev_p->value = value;
        prev_p->next_p = NULL;
    }
    printf("ptr=%d info=%d next=%d\n", prev_p, prev_p->value, prev_p->next_p);
    return prev_p;
}

Node *add_node(Node *prev_p, int value)
{
    struct Node *node_p;
    node_p = malloc(sizeof(struct Node));
    if (node_p != NULL)
    {
        node_p->value = value;
        node_p->next_p = prev_p;
    }
    printf("ptr=%d info=%d next=%d \n", node_p, node_p->value, node_p->next_p);
    return node_p;
}

int main()
{
    struct Node *head_p = create_node(10);
    head_p = add_node(head_p, 20);
    head_p = add_node(head_p, 30);

    printf(" ptr = %d \n", head_p);
    return 0;
}