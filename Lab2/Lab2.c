#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int value;
    struct Node * next;
} Node;

// створення нового/першого вузла
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

// додавання нового вузла на початок списку
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

// видалення першого вузла списку
Node * delete_head(Node *head) 
{
    struct Node *new_head = NULL;
    if (head)
    {
        printf("ptr=%d info=%d next=%d \n", head, head->value, head->next);
        new_head = head->next;
        free(head);
    }
    return new_head;
}

// видалення всього списку
Node * delete_list(Node *head) 
{
    while (head)
    {
        head = delete_head(head);
    }
    return NULL;
}

// виведення всього списку в консоль
void print_list(Node *head) 
{
    Node *temp = head;
    while (temp != NULL) 
    {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}

// зсув списку
Node *right_shift(Node *head, int k) 
{
    if (head == NULL || head->next == NULL || k == 0) 
    {
        return head;
    }

    Node *tail = head;
    int len = 1;

    while (tail->next != NULL) 
    {
        tail = tail->next;
        len++;
    }

    if (k == len) 
    {
        return head;
    }

    tail->next = head;

    int steps_to_new_tail = len - k - 1;
    Node *new_tail = head;
    for (int i = 0; i < steps_to_new_tail; i++) 
    {
        new_tail = new_tail->next;
    }

    Node *new_head = new_tail->next;
    new_tail->next = NULL;

    return new_head;
}

int main()
{
    int k = 2;

    struct Node *head = create_node(10);
    head = add_node(head, 20);
    head = add_node(head, 30);

    print_list(head);

    head = right_shift(head, k);

    print_list(head);
    head = delete_list(head);
    return 0;
}