#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node * node_init(int item) {
    Node *node_p;
    node_p = malloc(sizeof(struct Node));
    *node_p = (Node){
        .value = item,
        .next = NULL
    };
    return node_p;
}

int main() {

}