#include <stdio.h>

// Define a structure to represent time
struct Time {
    int hour;
    int min;
    int sec;
};

// Function to add two Time objects
struct Time addTime(struct Time t1, struct Time t2) {
    struct Time result;
    result.sec = t1.sec + t2.sec;
    result.min = t1.min + t2.min + result.sec / 60;
    result.hour = t1.hour + t2.hour + result.min / 60;

    // Normalize the time
    result.sec %= 60;
    result.min %= 60;
    result.hour %= 24;

    return result;
}

// Function to find the difference between two Time objects
struct Time findTimeDifference(struct Time t1, struct Time t2) {
    struct Time result;
    int totalSeconds1 = t1.hour * 3600 + t1.min * 60 + t1.sec;
    int totalSeconds2 = t2.hour * 3600 + t2.min * 60 + t2.sec;

    int differenceSeconds = totalSeconds1 - totalSeconds2;

    if (differenceSeconds < 0) {
        differenceSeconds += 24 * 3600; // 24 hours in seconds
    }

    result.sec = differenceSeconds % 60;
    result.min = (differenceSeconds / 60) % 60;
    result.hour = differenceSeconds / 3600;

    return result;
}

// Function to display a Time object
void displayTime(struct Time t) {
    printf("%02d:%02d:%02d\n", t.hour, t.min, t.sec);
}

// Function to read input into a Time object
void readTime(struct Time* t) {
    printf("Enter hour, minute, and second (hh:mm:ss): ");
    scanf("%d:%d:%d", &t->hour, &t->min, &t->sec);
}

int main() {
    struct Time time1, time2, result;

    printf("Enter the first time:\n");
    readTime(&time1);

    printf("Enter the second time:\n");
    readTime(&time2);

    // Add the times
    result = addTime(time1, time2);
    printf("Sum of times: ");
    displayTime(result);

    // Find the difference
    result = findTimeDifference(time1, time2);
    printf("Difference between times: ");
    displayTime(result);

    return 0;
}
