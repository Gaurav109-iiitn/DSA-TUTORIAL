#include <stdio.h>
#include <stdbool.h>

void visualize_binary_tree(int* arr, int size) {
    if (size == 0) {
        printf("The array is empty.\n");
        return;
    }
    printf("\n--- Binary Tree Representation ---\n");
    int level = 0;
    int nodes_on_level = 1;
    int index = 0;
    while (index < size) {
        printf("Level %d: ", level);
        for (int i = 0; i < nodes_on_level && index < size; i++) {
            printf("%d ", arr[index]);
            index++;
        }
        printf("\n");
        level++;
        nodes_on_level *= 2;
    }
    printf("------------------------------------\n");
}

bool is_max_heap(int* arr, int size) {
    if (size <= 1) {
        return true;
    }
    for (int i = 0; i < (size / 2); i++) {
        int parent_val = arr[i];
        int left_child_index = 2 * i + 1;
        int right_child_index = 2 * i + 2;
        if (left_child_index < size && arr[left_child_index] > parent_val) {
            printf("Violation found: Parent node %d is smaller than its left child %d.\n", parent_val, arr[left_child_index]);
            return false;
        }
        if (right_child_index < size && arr[right_child_index] > parent_val) {
            printf("Violation found: Parent node %d is smaller than its right child %d.\n", parent_val, arr[right_child_index]);
            return false; 
        }
    }
    return true;
}

int main() {
    int A[] = {10, 20, 5, 6, 1, 8, 9, 4};
    int n = sizeof(A) / sizeof(A[0]);
    
    printf("Given Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    visualize_binary_tree(A, n);
    printf("Checking for Max-Heap Property...\n");
    bool is_valid = is_max_heap(A, n);
    if (is_valid) {
        printf("\nResult: The array IS a max-heap.\n");
    } else {
        printf("\nResult: The array IS NOT a max-heap.\n");
    }
    return 0;
}
