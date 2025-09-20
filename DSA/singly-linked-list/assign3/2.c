#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100  // Max rows supported dynamically

typedef struct Node {
    int data;
    struct Node *right;
    struct Node *down;
} Node;

Node* createNode(int data) {
    Node* newnode = (Node*) malloc(sizeof(Node));
    newnode->data = data;
    newnode->right = newnode->down = NULL;
    return newnode;
}

void printRowMajor(Node* rowHeads[], int rows) {
    for (int i = 0; i < rows; i++) {
        Node* curr = rowHeads[i];
        while (curr) {
            printf("%d ", curr->data);
            curr = curr->right;
        }
        printf("\n");
    }
}
void insertRow(Node* rowHeads[], int *rows, int cols) {
    if (*rows >= MAX_ROWS) {
        printf("Maximum row limit reached.\n");
        return;
    }

    printf("Enter %d elements for the new row:\n", cols);
    Node* newRow[cols];

    for (int j = 0; j < cols; j++) {
        int val;
        scanf("%d", &val);
        newRow[j] = createNode(val);
        if (j > 0) {
            newRow[j - 1]->right = newRow[j];
        }
    }
    if (*rows > 0) {
        Node* prev = rowHeads[*rows - 1];
        Node* curr = newRow[0];
        for (int j = 0; j < cols; j++) {
            if (prev) {
                prev->down = curr;
                prev = prev->right;
                curr = curr->right;
            }
        }
    }
    rowHeads[*rows] = newRow[0];
    (*rows)++;
}

int main() {
    int rows, cols;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    Node* rowHeads[MAX_ROWS];  
    Node* matrix[rows][cols];  

    printf("Enter matrix elements row-wise:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int val;
            scanf("%d", &val);
            matrix[i][j] = createNode(val);
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j < cols - 1)
                matrix[i][j]->right = matrix[i][j + 1];
            if (i < rows - 1)
                matrix[i][j]->down = matrix[i + 1][j];
        }
        rowHeads[i] = matrix[i][0];
    }
    int currentRows = rows;
    printf("\nInitial Matrix:\n");
    printRowMajor(rowHeads, currentRows);
    insertRow(rowHeads, &currentRows, cols);
    printf("\nUpdated Matrix after inserting a new row:\n");
    printRowMajor(rowHeads, currentRows);

    return 0;
}
