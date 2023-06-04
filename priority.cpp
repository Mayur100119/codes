#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Patient {
    string name;
    int priority;

    bool operator<(const Patient& other) const {
        return priority < other.priority;
    }
};

int main() {
    priority_queue<Patient> hospitalQueue;
    int choice;

    do {
        cout << "Menu:" << endl;
        cout << "1. Add a serious patient" << endl;
        cout << "2. Add a non-serious patient" << endl;
        cout << "3. Add a general checkup patient" << endl;
        cout << "4. Serve the next patient" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                cout << "Enter the name of the serious patient: ";
                cin >> name;
                hospitalQueue.push({name, 1});
                cout << "Serious patient added to the queue." << endl;
                break;
            }
            case 2: {
                string name;
                cout << "Enter the name of the non-serious patient: ";
                cin >> name;
                hospitalQueue.push({name, 2});
                cout << "Non-serious patient added to the queue." << endl;
                break;
            }
            case 3: {
                string name;
                cout << "Enter the name of the general checkup patient: ";
                cin >> name;
                hospitalQueue.push({name, 3});
                cout << "General checkup patient added to the queue." << endl;
                break;
            }
            case 4:
                if (!hospitalQueue.empty()) {
                    Patient nextPatient = hospitalQueue.top();
                    hospitalQueue.pop();
                    cout << "Serving patient: " << nextPatient.name << endl;
                } else {
                    cout << "No patients in the queue." << endl;
                }
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    } while (choice != 0);

    return 0;
}
