#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string in-place
void reverseString(char* str) {
    int length = strlen(str);
    int i, j;
    char temp;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to add two long positive integers
char* addLongIntegers(const char* num1, const char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxLen = len1 > len2 ? len1 : len2;

    char* result = (char*)malloc(maxLen + 2); // +1 for the result, +1 for the null terminator
    int carry = 0;
    int sum = 0;
    int i = 0;

    for (i = 0; i < maxLen; i++) {
        int digit1 = (i < len1) ? num1[len1 - 1 - i] - '0' : 0;
        int digit2 = (i < len2) ? num2[len2 - 1 - i] - '0' : 0;

        sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result[i] = (sum % 10) + '0';
    }

    if (carry > 0) {
        result[i] = carry + '0';
        i++;
    }

    result[i] = '\0';
    reverseString(result);

    return result;
}

int main() {
    char num1[] = "023456789012345678901234567890";
    char num2[] = "887654321098765432109876543210";

    char* sum = addLongIntegers(num1, num2);

    printf("Sum: %s\n", sum);

    free(sum); // Don't forget to free the dynamically allocated memory

    return 0;
}
