#include <stdio.h>

// Function to calculate the length of a string
int strLength(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Function to concatenate two strings
void strConcatenate(char* destination, const char* source) {
    int destLength = strLength(destination);
    int i = 0;

    while (source[i] != '\0') {
        destination[destLength + i] = source[i];
        i++;
    }
    destination[destLength + i] = '\0';
}

// Function to compare two strings
int strCompare(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}

// Function to insert a substring into a string at a specified position
void strInsert(char* str, const char* subStr, int position) {
    int strLength = strLength(str);
    int subStrLength = strLength(subStr);

    if (position < 0 || position > strLength) {
        printf("Invalid position for insertion\n");
        return;
    }

    // Shift the characters to make space for the substring
    for (int i = strLength; i >= position; i--) {
        str[i + subStrLength] = str[i];
    }

    // Copy the substring into the main string
    for (int i = 0; i < subStrLength; i++) {
        str[position + i] = subStr[i];
    }
}

// Function to delete a substring from a string at a specified position
void strDelete(char* str, int position, int length) {
    int strLength = strLength(str);

    if (position < 0 || position >= strLength || length < 0 || position + length > strLength) {
        printf("Invalid position or length for deletion\n");
        return;
    }

    // Shift the characters to remove the substring
    for (int i = position; i < strLength - length; i++) {
        str[i] = str[i + length];
    }
    str[strLength - length] = '\0';
}

int main() {
    char str1[100], str2[100];
    int choice, position, length;

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    printf("Choose an operation:\n");
    printf("1. Calculate the length of the first string\n");
    printf("2. Concatenate the two strings\n");
    printf("3. Compare the two strings\n");
    printf("4. Insert a substring into the first string\n");
    printf("5. Delete a substring from the first string\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Length of the first string: %d\n", strLength(str1));
            break;
        case 2:
            strConcatenate(str1, str2);
            printf("Concatenated string: %s\n", str1);
            break;
        case 3:
            if (strCompare(str1, str2) == 0) {
                printf("The strings are equal.\n");
            } else {
                printf("The strings are not equal.\n");
            }
            break;
        case 4:
            printf("Enter the position to insert: ");
            scanf("%d", &position);
            printf("Enter the substring to insert: ");
            scanf("%s", str2);
            strInsert(str1, str2, position);
            printf("Result after insertion: %s\n", str1);
            break;
        case 5:
            printf("Enter the position to delete from: ");
            scanf("%d", &position);
            printf("Enter the length to delete: ");
            scanf("%d", &length);
            strDelete(str1, position, length);
            printf("Result after deletion: %s\n", str1);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}

