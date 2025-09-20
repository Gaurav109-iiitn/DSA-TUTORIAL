#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int val) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = val;
    node->next = NULL;
    return node;
}

Node* reverse(Node* head) {
    Node *prev = NULL, *curr = head, *next;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* addTwoLists(Node* num1, Node* num2) {
    num1 = reverse(num1);
    num2 = reverse(num2);
    Node *res = NULL, *tail = NULL;
    int carry = 0;

    while (num1 || num2 || carry) {
        int sum = carry;
        if (num1) sum += num1->data, num1 = num1->next;
        if (num2) sum += num2->data, num2 = num2->next;

        Node* newNode = createNode(sum % 10);
        carry = sum / 10;

        if (!res) res = tail = newNode;
        else tail->next = newNode, tail = newNode;
    }

    return reverse(res);
}

void printList(Node* head) {
    while (head) {
        printf("%d", head->data);

        head = head->next;
    }
    printf("\n");
}

Node* buildList(int n) {
    Node *head = NULL, *tail = NULL;
    printf("Enter %d digits (most significant first): ", n);
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        Node* newNode = createNode(val);
        if (!head) head = tail = newNode;
        else tail->next = newNode, tail = newNode;
    }
    return head;
}

int main() {
    int n1, n2;
    printf("Enter number of digits in first number: ");
    scanf("%d", &n1);
    Node* num1 = buildList(n1);

    printf("Enter number of digits in second number: ");
    scanf("%d", &n2);
    Node* num2 = buildList(n2);

    printf("First number: ");
    printList(num1);
    printf("Second number: ");
    printList(num2);

    Node* sum = addTwoLists(num1, num2);
    printf("Sum: ");
    printList(sum);

    return 0;
}
