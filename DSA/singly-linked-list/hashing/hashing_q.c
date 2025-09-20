#include <stdio.h>
#include <stdlib.h>
#define S1 10

// Linked list node for separate chaining
typedef struct node {
    int key;
    struct node* next;
} Node;

Node* h1[S1];   // for separate chaining
int h2[S1];     // for open addressing

// Hash function
int hash_function(int key) {
    return (2 * key + 3) % S1;
}

// Create new node
Node* create(int key) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->key = key;
    temp->next = NULL;
    return temp;
}

// Insert using separate chaining
void separate_chaining(int key) {
    int index = hash_function(key);
    Node* temp = create(key);

    if (h1[index] == NULL) {
        h1[index] = temp;
    } else {
        Node* curr = h1[index];
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = temp;
    }
}

// Insert using open addressing (linear probing)
void open_addressing(int key) {
    int index = hash_function(key);

    // linear probing
    int i = 0;
    while (h2[(index + i) % S1] != -1) {
        i++;
        if (i == S1) {  // table full
            printf("Hash table is full! Cannot insert %d\n", key);
            return;
        }
    }
    h2[(index + i) % S1] = key;
}

// Display for separate chaining
void display1(Node* a[], int s) {
    for (int i = 0; i < s; i++) {
        printf("Index %d: ", i);
        if (a[i] != NULL) {
            Node* temp = a[i];
            while (temp != NULL) {
                printf("%d -> ", temp->key);
                temp = temp->next;
            }
            printf("NULL\n");
        } else {
            printf("empty\n");
        }
    }
}

// Display for open addressing
void display2(int a[], int s) {
    for (int i = 0; i < s; i++) {
        if (a[i] == -1)
            printf("Index %d: empty\n", i);
        else
            printf("Index %d: %d\n", i, a[i]);
    }
}

int main() {
    // Initialize tables
    for (int i = 0; i < S1; i++) {
        h1[i] = NULL;
        h2[i] = -1;  // -1 means empty
    }

    int n;
    printf("Number of elements to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter key: ");
        scanf("%d", &data);
        separate_chaining(data);
        open_addressing(data);
    }

    printf("\n--- Separate Chaining ---\n");
    display1(h1, S1);

    printf("\n--- Open Addressing (Linear Probing) ---\n");
    display2(h2, S1);

    return 0;
}
