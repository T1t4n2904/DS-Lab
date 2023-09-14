#include <stdio.h>
#include <string.h>

// Define a structure to store student information
struct Student {
    char name[50];
    int rollNo;
    char grade;
};

// Function to read student information
void readStudents(struct Student students[], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter the roll number of student %d: ", i + 1);
        scanf("%d", &students[i].rollNo);
        printf("Enter the grade of student %d: ", i + 1);
        scanf(" %c", &students[i].grade); // Note the space before %c to consume the newline character
    }
}

// Function to display student information
void displayStudents(struct Student students[], int numStudents) {
    printf("Student Information:\n");
    printf("Roll No\tName\tGrade\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%d\t%s\t%c\n", students[i].rollNo, students[i].name, students[i].grade);
    }
}

// Function to sort student information by roll number
void sortStudents(struct Student students[], int numStudents) {
    // Use a simple bubble sort algorithm to sort by roll number
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = 0; j < numStudents - i - 1; j++) {
            if (students[j].rollNo > students[j + 1].rollNo) {
                // Swap the students
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    int numStudents;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    struct Student students[numStudents];

    // Read student information
    readStudents(students, numStudents);

    // Display unsorted student information
    printf("Unsorted Student Information:\n");
    displayStudents(students, numStudents);

    // Sort student information by roll number
    sortStudents(students, numStudents);

    // Display sorted student information
    printf("Sorted Student Information (by Roll No):\n");
    displayStudents(students, numStudents);

    return 0;
}

