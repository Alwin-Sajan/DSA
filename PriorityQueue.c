
#include <stdio.h>
#include <stdlib.h>

int F = -1, R = -1, pq[5], n, i, j;

void insertionsort() {
    for (i = R; i >= F; i--) {
        if (n < pq[i]) {
            pq[i + 1] = pq[i];
        } else {
            break;
        }
    }
    pq[i + 1] = n;
    R++;
}

void Enqueue() {
    if (R == 4) {
        printf("Queue is full.\n");
    } else if (F == -1 && R == -1) {
        F = 0;
        R = 0;
        printf("Enter the element to Enqueue: ");
        scanf("%d", &n);
        pq[R] = n;
    } else {
        printf("Enter the element to Enqueue: ");
        scanf("%d", &n);
        insertionsort();
    }
}

void Dequeue() {
    if (F == -1) {
        printf("Queue is empty.\n");
    } else if (F == R) {
        n = pq[F];
        F = -1;
        R = -1;
        printf("Removed element is: %d\n", n);
    } else {
        n = pq[F];
        F = F + 1;
        printf("Removed element is: %d\n", n);
    }
}

void Display() {
    if (F == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue: ");
        for (i = F; i <= R; i++)
            printf("%d ", pq[i]);
        printf("\n");
    }
}

int main() {
    int ch;
    while (1) {
        printf("\nMenu Of Priority Queue\n--------------------- \n");
        printf("1.Enqueue\n2.Dequeue\n3.Display the queue\n4.Exit\n");
        printf("ENTER THE CHOICE: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1: {
            Enqueue();
            break;
        }
        case 2: {
            Dequeue();
            break;
        }
        case 3: {
            Display();
            break;
        }
        case 4: {
            exit(0);
            break;
        }
        default: {
            printf("\nError No Choice Found.\n");
            break;
        }
        }
    }
    return 0;
}
