#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

void displayClock(int formatChoice) {
    time_t now = time(0);
    tm *local = localtime(&now);

    cout << "\n===== DIGITAL CLOCK =====\n\n";

    int dateParts[3];
    dateParts[0] = local->tm_mday;
    dateParts[1] = local->tm_mon + 1;
    dateParts[2] = local->tm_year + 1900;

    cout << "Date: ";

    for (int i = 0; i < 3; i++) {
        if (i == 2)
            cout << setw(4) << setfill('0') << dateParts[i];
        else
            cout << setw(2) << setfill('0') << dateParts[i] << "-";
    }

    cout << endl;

    int hour = local->tm_hour;

    if (formatChoice == 2) {
        string period = "AM";

        if (hour >= 12)
            period = "PM";

        hour = hour % 12;

        if (hour == 0)
            hour = 12;

        int timeParts[3] = {hour, local->tm_min, local->tm_sec};

        cout << "Time: ";

        for (int i = 0; i < 3; i++) {
            if (i == 2)
                cout << setw(2) << setfill('0') << timeParts[i] << " ";
            else
                cout << setw(2) << setfill('0') << timeParts[i] << ":";
        }

        cout << period << endl;

    } else {
        
        int timeParts[3] = {local->tm_hour, local->tm_min, local->tm_sec};

        cout << "Time: ";

        for (int i = 0; i < 3; i++) {
            if (i == 2)
                cout << setw(2) << setfill('0') << timeParts[i];
            else
                cout << setw(2) << setfill('0') << timeParts[i] << ":";
        }

        cout << endl;
    }
}

int main() {
    int choice;

    cout << "===== CLOCK MENU =====" << endl;
    cout << "1. 24-Hour Format" << endl;
    cout << "2. 12-Hour Format (AM/PM)" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    while (!(choice == 1 || choice == 2)) {
        cout << "Invalid choice! Enter again: ";
        cin >> choice;
    }

    displayClock(choice);

    return 0;
}
