#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node *next_p;
} Node;

Node * create_node(int item) {
    Node *node_p;
    node_p = malloc(sizeof(struct Node));
    *node_p = (Node){
        .value = item,
        .next_p = NULL
    };
    printf("ptr=%d info=%d next=%d\n",node_p, node_p->value,node_p->next_p);
    return node_p;
}

int main() {
    Node *head_p = create_node(10);
}