#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void displayClock(int formatChoice) {
    time_t now;
    time(&now);

    struct tm *local = localtime(&now);

    printf("\n===== DIGITAL CLOCK =====\n\n");

    // Print Date using loop (array concept)
    int dateParts[3];
    dateParts[0] = local->tm_mday;
    dateParts[1] = local->tm_mon + 1;
    dateParts[2] = local->tm_year + 1900;

    printf("Date: ");
    for (int i = 0; i < 3; i++) {
        if (i == 2)
            printf("%04d", dateParts[i]);
        else
            printf("%02d-", dateParts[i]);
    }

    printf("\n");

    int hour = local->tm_hour;

    // 12-hour format
    if (formatChoice == 2) {
        char *period = "AM";

        if (hour >= 12)
            period = "PM";

        hour = hour % 12;
        if (hour == 0)
            hour = 12;

        int timeParts[3] = {hour, local->tm_min, local->tm_sec};

        printf("Time: ");
        for (int i = 0; i < 3; i++) {
            if (i == 2)
                printf("%02d ", timeParts[i]);
            else
                printf("%02d:", timeParts[i]);
        }
        printf("%s\n", period);

    } else {
        // 24-hour format
        int timeParts[3] = {local->tm_hour, local->tm_min, local->tm_sec};

        printf("Time: ");
        for (int i = 0; i < 3; i++) {
            if (i == 2)
                printf("%02d\n", timeParts[i]);
            else
                printf("%02d:", timeParts[i]);
        }
    }
}

int main() {
    int choice;

    printf("===== CLOCK MENU =====\n");
    printf("1. 24-Hour Format\n");
    printf("2. 12-Hour Format (AM/PM)\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Validation using loop
    for (; !(choice == 1 || choice == 2); ) {
        printf("Invalid choice! Enter again: ");
        scanf("%d", &choice);
    }

    displayClock(choice);

    return 0;
}