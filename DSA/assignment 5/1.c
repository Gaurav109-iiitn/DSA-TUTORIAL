#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int *heap_array; 
    int capacity;   
    int size;        
} MinHeap;

MinHeap* createMinHeap(int capacity) {
    MinHeap* new_heap = (MinHeap*)malloc(sizeof(MinHeap));
    if (new_heap == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    new_heap->size = 0;
    new_heap->capacity = capacity;
    new_heap->heap_array = (int*)malloc(capacity * sizeof(int));
    if (new_heap->heap_array == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    return new_heap;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int parent(int i) {
    return (i - 1) / 2;
}

int left_child(int i) {
    return (2 * i + 1);
}

int right_child(int i) {
    return (2 * i + 2);
}

void sift_down(MinHeap* min_heap, int i) {
    int min_index = i;
    int left = left_child(i);
    int right = right_child(i);

    if (left < min_heap->size && min_heap->heap_array[left] < min_heap->heap_array[min_index]) {
        min_index = left;
    }

    if (right < min_heap->size && min_heap->heap_array[right] < min_heap->heap_array[min_index]) {
        min_index = right;
    }

    if (min_index != i) {
        swap(&min_heap->heap_array[i], &min_heap->heap_array[min_index]);
        sift_down(min_heap, min_index);
    }
}

void sift_up(MinHeap* min_heap, int i) {
    while (i > 0 && min_heap->heap_array[parent(i)] > min_heap->heap_array[i]) {
        swap(&min_heap->heap_array[parent(i)], &min_heap->heap_array[i]);
        i = parent(i);
    }
}

void insertElement(MinHeap* min_heap, int element) {
    if (min_heap->size == min_heap->capacity) {
        min_heap->capacity *= 2; 
        min_heap->heap_array = (int*)realloc(min_heap->heap_array, min_heap->capacity * sizeof(int));
        if (min_heap->heap_array == NULL) {
            printf("Error: Memory reallocation failed.\n");
            exit(1);
        }
        printf("Resized heap capacity to %d.\n", min_heap->capacity);
    }
    min_heap->size++;
    int i = min_heap->size - 1;
    min_heap->heap_array[i] = element;
    sift_up(min_heap, i);
}

int deleteMax(MinHeap* min_heap) {
    if (min_heap->size <= 0) {
        printf("Heap is empty.\n");
        return INT_MIN; 
    }

    int max_val = INT_MIN;
    int max_index = -1;
    
    int first_leaf_index = (min_heap->size / 2);
    for (int i = first_leaf_index; i < min_heap->size; i++) {
        if (min_heap->heap_array[i] > max_val) {
            max_val = min_heap->heap_array[i];
            max_index = i;
        }
    }
    if (min_heap->size == 1) {
        max_val = min_heap->heap_array[0];
        min_heap->size = 0;
        return max_val;
    }
    swap(&min_heap->heap_array[max_index], &min_heap->heap_array[min_heap->size - 1]);
    min_heap->size--;
    int max_element = min_heap->heap_array[min_heap->size];
    sift_down(min_heap, max_index);
    sift_up(min_heap, max_index); 
    return max_element;
}

void buildHeap(MinHeap* min_heap, int* array, int n) {
    for (int i = 0; i < n; i++) {
        min_heap->heap_array[i] = array[i];
    }
    min_heap->size = n;
    for (int i = (n / 2) - 1; i >= 0; i--) {
        sift_down(min_heap, i);
    }
}

void heapSort(int* array, int n) {
    MinHeap* temp_heap = createMinHeap(n);
    buildHeap(temp_heap, array, n);
    for (int i = n - 1; i >= 0; i--) {
        array[i] = deleteMax(temp_heap); 
    }
    free(temp_heap->heap_array);
    free(temp_heap);
}

void visualize(MinHeap* min_heap) {
    if (min_heap->size == 0) {
        printf("Heap is empty.\n");
        return;
    }
    
    printf("\n--- Heap Visualization (Tree Structure) ---\n");
    int level = 0;
    int nodes_at_level = 1;
    int current_nodes_printed = 0;
    
    for (int i = 0; i < min_heap->size; i++) {
        printf("%d ", min_heap->heap_array[i]);
        current_nodes_printed++;
        
        if (current_nodes_printed == nodes_at_level) {
            printf("\n");
            level++;
            nodes_at_level *= 2;
            current_nodes_printed = 0;
        }
    }
    printf("\n-------------------------------------------\n");
}

int main() {
    int capacity = 10;
    MinHeap* min_heap = createMinHeap(capacity);
    
    int sample_array[] = {1, 5, 6, 8, 9, 7, 3};
    int n = sizeof(sample_array) / sizeof(sample_array[0]);
    
    printf("Building a min-heap from the sample array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", sample_array[i]);
    }
    printf("\n");
    
    buildHeap(min_heap, sample_array, n);
    visualize(min_heap);
    
    int choice, element;
    
    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Insert an element\n");
        printf("2. Delete the maximum element\n");
        printf("3. Sort the current heap (Heap Sort)\n");
        printf("4. Visualize the heap\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insertElement(min_heap, element);
                printf("Inserted %d.\n", element);
                visualize(min_heap);
                break;
            case 2:
                element = deleteMax(min_heap);
                if (element != INT_MIN) {
                    printf("Deleted max element: %d.\n", element);
                    visualize(min_heap);
                }
                break;
            case 3:
                printf("Sorting the heap (descending order)...\n");
                int* array_to_sort = (int*)malloc(min_heap->size * sizeof(int));
                if (array_to_sort == NULL) {
                    printf("Error: Memory allocation failed.\n");
                    break;
                }
                for (int i = 0; i < min_heap->size; i++) {
                    array_to_sort[i] = min_heap->heap_array[i];
                }
                
                heapSort(array_to_sort, min_heap->size);
                
                printf("Sorted array (descending): ");
                for (int i = 0; i < min_heap->size; i++) {
                    printf("%d ", array_to_sort[i]);
                }
                printf("\n");
                free(array_to_sort);
                break;
            case 4:
                visualize(min_heap);
                break;
            case 5:
                printf("Exiting program.\n");
                free(min_heap->heap_array);
                free(min_heap);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
