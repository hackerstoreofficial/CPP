#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Structure to represent a deque
struct Deque {
    int array[MAX_SIZE];
    int front, rear;
};

// Function to initialize a deque
void initializeDeque(struct Deque *deque) {
    deque->front = -1;
    deque->rear = -1;
}

// Function to check if the deque is empty
int isDequeEmpty(struct Deque *deque) {
    return (deque->front == -1 && deque->rear == -1);
}

// Function to check if the deque is full
int isDequeFull(struct Deque *deque) {
    return (deque->rear + 1) % MAX_SIZE == deque->front;
}

// Function to add an element to the front of the deque
void addToFront(struct Deque *deque, int value) {
    if (isDequeFull(deque)) {
        printf("Deque is full. Cannot add element to the front.\n");
        return;
    }

    if (isDequeEmpty(deque)) {
        deque->front = deque->rear = 0;
    } else {
        deque->front = (deque->front - 1 + MAX_SIZE) % MAX_SIZE;
    }

    deque->array[deque->front] = value;
    printf("Added %d to the front of the deque.\n", value);
}

// Function to add an element to the rear of the deque
void addToRear(struct Deque *deque, int value) {
    if (isDequeFull(deque)) {
        printf("Deque is full. Cannot add element to the rear.\n");
        return;
    }

    if (isDequeEmpty(deque)) {
        deque->front = deque->rear = 0;
    } else {
        deque->rear = (deque->rear + 1) % MAX_SIZE;
    }

    deque->array[deque->rear] = value;
    printf("Added %d to the rear of the deque.\n", value);
}

// Function to delete an element from the front of the deque
void removeFromFront(struct Deque *deque) {
    if (isDequeEmpty(deque)) {
        printf("Deque is empty. Cannot remove element from the front.\n");
        return;
    }

    printf("Removed %d from the front of the deque.\n", deque->array[deque->front]);

    if (deque->front == deque->rear) {
        // Last element is being removed
        initializeDeque(deque);
    } else {
        deque->front = (deque->front + 1) % MAX_SIZE;
    }
}

// Function to delete an element from the rear of the deque
void removeFromRear(struct Deque *deque) {
    if (isDequeEmpty(deque)) {
        printf("Deque is empty. Cannot remove element from the rear.\n");
        return;
    }

    printf("Removed %d from the rear of the deque.\n", deque->array[deque->rear]);

    if (deque->front == deque->rear) {
        // Last element is being removed
        initializeDeque(deque);
    } else {
        deque->rear = (deque->rear - 1 + MAX_SIZE) % MAX_SIZE;
    }
}

// Function to print the elements of the deque
void printDeque(struct Deque *deque) {
    if (isDequeEmpty(deque)) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque elements: ");
    int i = deque->front;
    do {
        printf("%d ", deque->array[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (deque->rear + 1) % MAX_SIZE);

    printf("\n");
}

int main() {
    struct Deque deque;

    initializeDeque(&deque);

    addToFront(&deque, 1);
    addToRear(&deque, 2);
    addToFront(&deque, 3);
    addToRear(&deque, 4);

    printDeque(&deque);

    removeFromFront(&deque);
    removeFromRear(&deque);

    printDeque(&deque);

    return 0;
}
