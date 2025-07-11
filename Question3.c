//CONGO LINE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for each person in the Congo line
struct Node {
    char name[50];
    struct Node* next;
};

struct Node* head = NULL; // Head of the line
struct Node* tail = NULL;  // End of the line

// Function to add a person at the end (enqueue)
void congoline(char* name) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (tail == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }

    printf("%s joined the Congo line!\n", name);
}
/*
// Function to remove person from front (dequeue)
void leaveCongoLine() {
    if (front == NULL) {
        printf("Congo line is empty!\n");
        return;
    }

    struct Person* temp = front;
    printf("%s left the Congo line!\n", front->name);
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}
*/
// Function to display the Congo line
void displayLine() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("Congo line is empty!\n");
        return;
    }

    printf("Congo Line:\n");
    while (temp != NULL) {
        printf("-> %s\n", temp->name);
        temp = temp->next;
    }
}

int main() {
    int choice;
    char name[50];

    do {
        printf("\n1. Join Congo Line\n2. Display Line\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);
        getchar(); // To consume newline

        switch (choice) {
            case 1:
                printf("Enter person's name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                congoline(name);
                break;
            //case 2:
              //  leaveCongoLine();
                //break;
            case 2:
                displayLine();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
