#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) {
        printf("Queue full\n");
    } else {
        if (front == -1)
            front = 0;
        queue[++rear] = x;
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Empty\n");
    } else {
        printf("Printing document : %d\n", queue[front++]);
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("No pending documents\n");
    } else {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, x;

    do {
        printf("\n1. Add 2. Print 3. Display 4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Enter doc id: ");
            scanf("%d", &x);
            enqueue(x);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        }

    } while (choice != 4);

    return 0;
}