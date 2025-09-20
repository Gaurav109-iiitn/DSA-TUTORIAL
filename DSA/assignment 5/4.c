#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// A structure to represent the min-heap
typedef struct {
    int *heap_array; // Pointer to the array that stores heap elements
    int capacity;    // Maximum capacity of the heap
    int size;        // Current number of elements in the heap
} MinHeap;

// Function to create a new min-heap
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

// Helper function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to get the parent index
int parent(int i) {
    return (i - 1) / 2;
}

// Function to get the left child index
int left_child(int i) {
    return (2 * i + 1);
}

// Function to get the right child index
int right_child(int i) {
    return (2 * i + 2);
}

// Function to maintain the min-heap property by moving an element down
void sift_down(MinHeap* min_heap, int i) {
    int min_index = i;
    int left = left_child(i);
    int right = right_child(i);

    // Check if the left child exists and is smaller than the current minimum
    if (left < min_heap->size && min_heap->heap_array[left] < min_heap->heap_array[min_index]) {
        min_index = left;
    }

    // Check if the right child exists and is smaller than the current minimum
    if (right < min_heap->size && min_heap->heap_array[right] < min_heap->heap_array[min_index]) {
        min_index = right;
    }

    // If the smallest element is not the current element, swap and sift down
    if (min_index != i) {
        swap(&min_heap->heap_array[i], &min_heap->heap_array[min_index]);
        sift_down(min_heap, min_index);
    }
}

// Function to maintain the min-heap property by moving an element up
void sift_up(MinHeap* min_heap, int i) {
    // Keep sifting up as long as the parent is greater than the current element
    while (i > 0 && min_heap->heap_array[parent(i)] > min_heap->heap_array[i]) {
        swap(&min_heap->heap_array[parent(i)], &min_heap->heap_array[i]);
        i = parent(i);
    }
}

// Function to insert a new element into the min-heap
void insertElement(MinHeap* min_heap, int element) {
    // Check if the heap is full and resize if needed
    if (min_heap->size == min_heap->capacity) {
        min_heap->capacity *= 2; // Double the capacity
        min_heap->heap_array = (int*)realloc(min_heap->heap_array, min_heap->capacity * sizeof(int));
        if (min_heap->heap_array == NULL) {
            printf("Error: Memory reallocation failed.\n");
            exit(1);
        }
        printf("Resized heap capacity to %d.\n", min_heap->capacity);
    }

    // Insert the new element at the end
    min_heap->size++;
    int i = min_heap->size - 1;
    min_heap->heap_array[i] = element;

    // Sift up to maintain the min-heap property
    sift_up(min_heap, i);
}

// Function to find and delete the maximum element from the min-heap
int deleteMax(MinHeap* min_heap) {
    if (min_heap->size <= 0) {
        printf("Heap is empty.\n");
        return INT_MIN; // Return a sentinel value
    }

    // The maximum element in a min-heap is always a leaf node.
    // We must search all leaf nodes to find it.
    int max_val = INT_MIN;
    int max_index = -1;
    
    // Start searching from the first leaf node.
    int first_leaf_index = (min_heap->size / 2);
    for (int i = first_leaf_index; i < min_heap->size; i++) {
        if (min_heap->heap_array[i] > max_val) {
            max_val = min_heap->heap_array[i];
            max_index = i;
        }
    }

    // Handle the case where the heap only has one element (the root is also a leaf)
    if (min_heap->size == 1) {
        max_val = min_heap->heap_array[0];
        min_heap->size = 0;
        return max_val;
    }
    
    // Swap the maximum element with the last element
    swap(&min_heap->heap_array[max_index], &min_heap->heap_array[min_heap->size - 1]);
    
    // Decrease the size and get the max element
    min_heap->size--;
    int max_element = min_heap->heap_array[min_heap->size];
    
    // Restore the heap property
    sift_down(min_heap, max_index);
    sift_up(min_heap, max_index); // In case the swapped element is smaller than its parent
    
    return max_element;
}

// Function to build a min-heap from an array
void buildHeap(MinHeap* min_heap, int* array, int n) {
    // Copy elements from the array to the heap
    for (int i = 0; i < n; i++) {
        min_heap->heap_array[i] = array[i];
    }
    min_heap->size = n;
    
    // Start from the last non-leaf node and sift down each one
    for (int i = (n / 2) - 1; i >= 0; i--) {
        sift_down(min_heap, i);
    }
}

// Function to sort an array using the min-heap sort algorithm
void heapSort(int* array, int n) {
    MinHeap* temp_heap = createMinHeap(n);
    buildHeap(temp_heap, array, n);

    // Extract elements one by one to get a sorted array (in descending order)
    for (int i = n - 1; i >= 0; i--) {
        array[i] = deleteMax(temp_heap); // This is inefficient for a min-heap,
                                        // so we use deleteMax to sort descending
    }
    
    free(temp_heap->heap_array);
    free(temp_heap);
}

// Function to print a text-based representation of the heap tree
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
                // Copy the current heap to a new array for sorting
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



















#include <stdio.h>
#include <stdbool.h>

// Function to visualize the binary tree structure of the array
void visualize_binary_tree(int* arr, int size) {
    if (size == 0) {
        printf("The array is empty.\n");
        return;
    }
    
    printf("\n--- Binary Tree Representation ---\n");
    
    // We'll print the tree level by level
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

// Function to check if the array satisfies the max-heap property
bool is_max_heap(int* arr, int size) {
    if (size <= 1) {
        // A heap with 0 or 1 element is always a max-heap
        return true;
    }
    
    // We only need to check nodes that have at least one child.
    // These are the nodes from index 0 up to (size / 2) - 1.
    for (int i = 0; i < (size / 2); i++) {
        int parent_val = arr[i];
        
        // Calculate the indices of the children
        int left_child_index = 2 * i + 1;
        int right_child_index = 2 * i + 2;
        
        // Check if the left child exists and is greater than the parent
        if (left_child_index < size && arr[left_child_index] > parent_val) {
            printf("Violation found: Parent node %d is smaller than its left child %d.\n", parent_val, arr[left_child_index]);
            return false; // Not a max-heap
        }
        
        // Check if the right child exists and is greater than the parent
        if (right_child_index < size && arr[right_child_index] > parent_val) {
            printf("Violation found: Parent node %d is smaller than its right child %d.\n", parent_val, arr[right_child_index]);
            return false; // Not a max-heap
        }
    }
    
    // If we've checked all parent nodes and found no violations, it's a max-heap
    return true;
}

int main() {
    // The given array
    int A[] = {10, 20, 5, 6, 1, 8, 9, 4};
    int n = sizeof(A) / sizeof(A[0]);
    
    printf("Given Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    
    // Visualize the array as a binary tree
    visualize_binary_tree(A, n);
    
    // Check if the array satisfies the max-heap property
    printf("Checking for Max-Heap Property...\n");
    bool is_valid = is_max_heap(A, n);
    
    if (is_valid) {
        printf("\nResult: The array IS a max-heap.\n");
    } else {
        printf("\nResult: The array IS NOT a max-heap.\n");
    }
    
    return 0;
}



















#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to represent a task with a name and a priority level
typedef struct {
    char name[50];
    int priority;
} Task;

// A structure to represent the max-heap
typedef struct {
    Task* heap_array; // Array to store tasks
    int capacity;     // Maximum capacity of the heap
    int size;         // Current number of tasks in the heap
} MaxHeap;

// Function to create a new max-heap
MaxHeap* createMaxHeap(int capacity) {
    MaxHeap* new_heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    if (new_heap == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    new_heap->size = 0;
    new_heap->capacity = capacity;
    new_heap->heap_array = (Task*)malloc(capacity * sizeof(Task));
    if (new_heap->heap_array == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    return new_heap;
}

// Helper function to swap two tasks
void swap_tasks(Task* a, Task* b) {
    Task temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain the max-heap property by moving an element up
void sift_up(MaxHeap* max_heap, int i) {
    int parent_index = (i - 1) / 2;
    while (i > 0 && max_heap->heap_array[parent_index].priority < max_heap->heap_array[i].priority) {
        swap_tasks(&max_heap->heap_array[i], &max_heap->heap_array[parent_index]);
        i = parent_index;
        parent_index = (i - 1) / 2;
    }
}

// Function to maintain the max-heap property by moving an element down
void sift_down(MaxHeap* max_heap, int i) {
    int largest_index = i;
    int left_child_index = 2 * i + 1;
    int right_child_index = 2 * i + 2;

    // Check if left child exists and has higher priority
    if (left_child_index < max_heap->size && max_heap->heap_array[left_child_index].priority > max_heap->heap_array[largest_index].priority) {
        largest_index = left_child_index;
    }

    // Check if right child exists and has higher priority
    if (right_child_index < max_heap->size && max_heap->heap_array[right_child_index].priority > max_heap->heap_array[largest_index].priority) {
        largest_index = right_child_index;
    }

    // If the largest is not the current node, swap and continue sifting down
    if (largest_index != i) {
        swap_tasks(&max_heap->heap_array[i], &max_heap->heap_array[largest_index]);
        sift_down(max_heap, largest_index);
    }
}

// Function to insert a new task into the priority queue (max-heap)
void insertTask(MaxHeap* max_heap, Task new_task) {
    if (max_heap->size == max_heap->capacity) {
        printf("Priority queue is full. Cannot insert task: %s\n", new_task.name);
        return;
    }

    // Add the new task to the end of the heap
    max_heap->size++;
    int i = max_heap->size - 1;
    max_heap->heap_array[i] = new_task;

    // Sift the task up to its correct position to maintain the max-heap property
    sift_up(max_heap, i);
}

// Function to extract the highest priority task (the root) from the heap
Task extractMax(MaxHeap* max_heap) {
    if (max_heap->size <= 0) {
        Task empty_task = {"", -1}; // Return an empty task to signal an error
        return empty_task;
    }

    // The highest priority task is always at the root of the max-heap
    Task max_task = max_heap->heap_array[0];

    // Move the last element to the root position
    max_heap->heap_array[0] = max_heap->heap_array[max_heap->size - 1];
    max_heap->size--;

    // Sift down the new root to maintain the max-heap property
    sift_down(max_heap, 0);

    return max_task;
}

// Function to print the current tasks in the heap (not sorted)
void printHeap(MaxHeap* max_heap) {
    printf("Current tasks in the priority queue (heap order):\n");
    for (int i = 0; i < max_heap->size; i++) {
        printf(" - Task: %s, Priority: %d\n", max_heap->heap_array[i].name, max_heap->heap_array[i].priority);
    }
    if (max_heap->size == 0) {
        printf("  (Queue is empty)\n");
    }
    printf("\n");
}

int main() {
    int initial_capacity = 10;
    MaxHeap* task_queue = createMaxHeap(initial_capacity);

    printf("--- Priority Queue System Simulation ---\n\n");
    printf("Inserting tasks with different priorities:\n");

    // Define some tasks
    Task tasks[] = {
        {"Fix critical bug", 100},
        {"Write documentation", 20},
        {"Run server backups", 95},
        {"Review pull request", 50},
        {"Update website content", 30},
        {"User support ticket", 75}
    };
    int num_tasks = sizeof(tasks) / sizeof(tasks[0]);

    // Insert the tasks into the priority queue
    for (int i = 0; i < num_tasks; i++) {
        printf("Inserting task: %s (Priority: %d)\n", tasks[i].name, tasks[i].priority);
        insertTask(task_queue, tasks[i]);
    }

    // Print the heap after all insertions
    printf("\n--- All tasks inserted ---\n");
    printHeap(task_queue);
    
    // As a visual aid, here's how a max-heap looks. The highest priority item is always at the top.
    // 

    printf("--- Processing tasks in order of priority (Highest first) ---\n\n");

    // Extract and "process" tasks until the queue is empty
    while (task_queue->size > 0) {
        Task high_priority_task = extractMax(task_queue);
        printf("--> Processing task: %s (Priority: %d)\n", high_priority_task.name, high_priority_task.priority);
        printHeap(task_queue);
    }

    printf("--- All tasks processed. Priority queue is empty. ---\n");

    // Clean up memory
    free(task_queue->heap_array);
    free(task_queue);

    return 0;
}
