#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define K 4
#define BASE 10000   

typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
} Node;

// BigInt structure
typedef struct {
    Node* head;
    Node* tail;
} BigInt;

// Create empty BigInt
BigInt* createBigInt() {
    BigInt* num = (BigInt*)malloc(sizeof(BigInt));
    num->head = num->tail = NULL;
    return num;
}

// Insert value at the front
void insertFront(BigInt* num, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->prev = NULL;
    newNode->next = num->head;

    if (num->head != NULL)
        num->head->prev = newNode;
    else
        num->tail = newNode;

    num->head = newNode;
}

// Insert value at the end
void insertEnd(BigInt* num, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = num->tail;

    if (num->tail != NULL)
        num->tail->next = newNode;
    else
        num->head = newNode;

    num->tail = newNode;
}

// Convert string to BigInt in blocks of K digits
BigInt* stringToBigInt_Block(const char* str) {
    int len = strlen(str);
    BigInt* num = createBigInt();

    for (int i = len; i > 0; i -= K) {
        int start = i - K;
        if (start < 0) start = 0;

        char block[K + 1] = {0};
        strncpy(block, str + start, i - start);
        insertFront(num, atoi(block));
    }
    return num;
}

// Convert string to BigInt digit-by-digit
BigInt* stringToBigInt_Digit(const char* str) {
    BigInt* num = createBigInt();
    for (int i = 0; str[i] != '\0'; i++) {
        insertEnd(num, str[i] - '0');
    }
    return num;
}

// Add two BigInts (base = BASE for block mode, base = 10 for digit mode)
BigInt* addBigInts(BigInt* a, BigInt* b, int base) {
    BigInt* result = createBigInt();
    Node* n1 = a->tail;
    Node* n2 = b->tail;
    int carry = 0;

    while (n1 || n2 || carry) {
        int v1 = (n1) ? n1->value : 0;
        int v2 = (n2) ? n2->value : 0;
        int sum = v1 + v2 + carry;
        carry = sum / base;
        insertFront(result, sum % base);
        if (n1) n1 = n1->prev;
        if (n2) n2 = n2->prev;
    }

    return result;
}

// Print BigInt
void printBigInt(BigInt* num, int padLength) {
    Node* curr = num->head;
    if (curr == NULL) {
        printf("0\n");
        return;
    }

    // Print the first block without leading zeros
    printf("%d", curr->value);
    curr = curr->next;

    // Print remaining blocks with leading zeros
    while (curr) {
        printf("%0*d", padLength, curr->value);
        curr = curr->next;
    }
    printf("\n");
}

// Free the memory of BigInt
void freeBigInt(BigInt* num) {
    Node* curr = num->head;
    while (curr) {
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(num);
}

// Compare block vs digit mode performance
void comparePerformance(const char* str1, const char* str2) {
    clock_t start, end;

    // Block mode
    BigInt* num1_block = stringToBigInt_Block(str1);
    BigInt* num2_block = stringToBigInt_Block(str2);
    start = clock();
    BigInt* sum_block = addBigInts(num1_block, num2_block, BASE);
    end = clock();
    double time_block = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n[Block Mode] Sum: ");
    printBigInt(sum_block, K);
    printf("[Block Mode] Time: %.6f seconds\n", time_block);

    // Digit mode
    BigInt* num1_digit = stringToBigInt_Digit(str1);
    BigInt* num2_digit = stringToBigInt_Digit(str2);
    start = clock();
    BigInt* sum_digit = addBigInts(num1_digit, num2_digit, 10);
    end = clock();
    double time_digit = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n[Digit Mode] Sum: ");
    printBigInt(sum_digit, 1);
    printf("[Digit Mode] Time: %.6f seconds\n", time_digit);

    // Cleanup
    freeBigInt(num1_block);
    freeBigInt(num2_block);
    freeBigInt(sum_block);
    freeBigInt(num1_digit);
    freeBigInt(num2_digit);
    freeBigInt(sum_digit);
}

int main() {
    char str1[10000], str2[10000];

    printf("Enter first large number: ");
    scanf("%s", str1);
    printf("Enter second large number: ");
    scanf("%s", str2);

    comparePerformance(str1, str2);
    return 0;
}
