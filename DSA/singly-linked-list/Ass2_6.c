#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int row, col, value;
    struct Node* next;
} Node;


Node* createNode(int row, int col, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(Node** head, int row, int col, int value) {
    Node* newNode = createNode(row, col, value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

Node* transposeSparseMatrix(Node* head) {
    Node* transposed = NULL;
    Node* temp = head;
    while (temp) {
        
        insertEnd(&transposed, temp->col, temp->row, temp->value);
        temp = temp->next;
    }
    return transposed;
}


void printSparseMatrix(Node* head) {
    printf("Row\tCol\tValue\n");
    while (head) {
        printf("%d\t%d\t%d\n", head->row, head->col, head->value);
        head = head->next;
    }
}


int main() {
    Node* sparse = NULL;
    
    insertEnd(&sparse, 0, 1, 5);
    insertEnd(&sparse, 1, 2, 8);
    insertEnd(&sparse, 2, 0, 3);

    printf("Original Sparse Matrix:\n");
    printSparseMatrix(sparse);

    Node* transposed = transposeSparseMatrix(sparse);

    printf("\nTransposed Sparse Matrix:\n");
    printSparseMatrix(transposed);


    return 0;
}