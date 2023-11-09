#include <stdio.h>
#include <stdlib.h>

typedef struct WashingMachine {
    int machineNumber;
    int remainingTime;
    struct WashingMachine* next;
    struct WashingMachine* prev;
} WashingMachine;

WashingMachine* createMachine(int machineNumber) {
    WashingMachine* machine = (WashingMachine*)malloc(sizeof(WashingMachine));
    machine->machineNumber = machineNumber;
    machine->remainingTime = 0;
    machine->next = machine;
    machine->prev = machine;
    return machine;
}

void addMachine(WashingMachine** head, int machineNumber) {
    WashingMachine* newMachine = createMachine(machineNumber);
    if (*head == NULL) {
        *head = newMachine;
    } else {
        WashingMachine* tail = (*head)->prev;
        newMachine->next = *head;
        newMachine->prev = tail;
        tail->next = newMachine;
        (*head)->prev = newMachine;
    }
}

void bookMachine(WashingMachine** head, int machineNumber, int time) {
    WashingMachine* current = *head;
    while (current->machineNumber != machineNumber) {
        current = current->next;
        if (current == *head) {
            printf("Machine with number %d not found.\n", machineNumber);
            return;
        }
    }

    if (current->remainingTime == 0) {
        current->remainingTime = time;
        printf("Machine %d is booked for %d minutes.\n", machineNumber, time);
    } else {
        printf("Machine %d is already booked for %d minutes.\n", machineNumber, current->remainingTime);
    }
}

void releaseMachine(WashingMachine** head) {
    WashingMachine* current = *head;
    do {
        if (current->remainingTime > 0) {
            current->remainingTime--;
            if (current->remainingTime == 0) {
                printf("Machine %d is now available.\n", current->machineNumber);
            }
        }
        current = current->next;
    } while (current != *head);
}

void displayMachines(WashingMachine* head) {
    WashingMachine* current = head;
    do {
        printf("Machine %d is %s\n", current->machineNumber, current->remainingTime > 0 ? "booked" : "available");
        current = current->next;
    } while (current != head);
}

int main() {
    WashingMachine* machines = NULL;
    int machineCount, machineNumber, choice, time;

    printf("Enter the number of washing machines: ");
    scanf("%d", &machineCount);

    for (int i = 1; i <= machineCount; i++) {
        addMachine(&machines, i);
    }

    while (1) {
        printf("\nWashing Machine Rental System\n");
        printf("1. Book a machine\n");
        printf("2. Release machines\n");
        printf("3. Display machine status\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the machine number to book: ");
                scanf("%d", &machineNumber);
                printf("Enter the booking duration (in minutes): ");
                scanf("%d", &time);
                bookMachine(&machines, machineNumber, time);
                break;
            case 2:
                releaseMachine(&machines);
                break;
            case 3:
                displayMachines(machines);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
