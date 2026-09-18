#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char name[50];
    char phone[15];
    struct Contact *next;
};

struct Contact *head = NULL;

void insertBeginning() {
    struct Contact *newNode;

    newNode = (struct Contact *)malloc(sizeof(struct Contact));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", newNode->name);

    printf("Enter phone number: ");
    scanf("%s", newNode->phone);

    newNode->next = head;
    head = newNode;

    printf("Contact added successfully!\n");
}

void insertEnd() {
    struct Contact *newNode, *temp;

    newNode = (struct Contact *)malloc(sizeof(struct Contact));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", newNode->name);

    printf("Enter phone number: ");
    scanf("%s", newNode->phone);

    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("Contact added successfully!\n");
}

void deleteContact() {
    char name[50];
    struct Contact *temp, *prev;

    printf("Enter name to delete: ");
    scanf("%s", name);

    temp = head;
    prev = NULL;

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }

            free(temp);
            printf("Contact deleted successfully!\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Contact not found!\n");
}

void searchContact() {
    char name[50];
    struct Contact *temp;

    printf("Enter name to search: ");
    scanf("%s", name);

    temp = head;

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("Contact Found!\n");
            printf("Name: %s\n", temp->name);
            printf("Phone: %s\n", temp->phone);
            return;
        }
        temp = temp->next;
    }

    printf("Contact not found!\n");
}

void display() {
    struct Contact *temp = head;

    if (temp == NULL) {
        printf("Phonebook is empty!\n");
        return;
    }

    printf("\n--- Contact List ---\n");
    while (temp != NULL) {
        printf("Name: %s | Phone: %s\n", temp->name, temp->phone);
        temp = temp->next;
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Phonebook Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete Contact\n");
        printf("4. Search Contact\n");
        printf("5. Display All\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertBeginning();
                break;
            case 2:
                insertEnd();
                break;
            case 3:
                deleteContact();
                break;
            case 4:
                searchContact();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

