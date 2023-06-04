#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

void displayAscending(const map<string, string>& dictionary) {
    for (const auto& entry : dictionary) {
        cout << entry.first << ": " << entry.second << endl;
    }
}

void displayDescending(const map<string, string>& dictionary) {
    for (auto it = dictionary.rbegin(); it != dictionary.rend(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }
}

int main() {
    map<string, string> dictionary;
    int choice;

    do {
        cout << "Menu:" << endl;
        cout << "1. Add a keyword" << endl;
        cout << "2. Delete a keyword" << endl;
        cout << "3. Update the meaning of a keyword" << endl;
        cout << "4. Display data in ascending order" << endl;
        cout << "5. Display data in descending order" << endl;
        cout << "6. Find the maximum comparisons for finding a keyword" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string keyword, meaning;
                cout << "Enter the keyword: ";
                cin >> keyword;
                cout << "Enter the meaning: ";
                cin >> meaning;
                dictionary[keyword] = meaning;
                cout << "Keyword added successfully." << endl;
                break;
            }
            case 2: {
                string keyword;
                cout << "Enter the keyword to delete: ";
                cin >> keyword;
                if (dictionary.erase(keyword) > 0) {
                    cout << "Keyword deleted successfully." << endl;
                } else {
                    cout << "Keyword not found." << endl;
                }
                break;
            }
            case 3: {
                string keyword, meaning;
                cout << "Enter the keyword to update: ";
                cin >> keyword;
                cout << "Enter the new meaning: ";
                cin >> meaning;
                dictionary[keyword] = meaning;
                cout << "Keyword updated successfully." << endl;
                break;
            }
            case 4:
                cout << "Data in ascending order:" << endl;
                displayAscending(dictionary);
                break;
            case 5:
                cout << "Data in descending order:" << endl;
                displayDescending(dictionary);
                break;
            case 6: {
                string keyword;
                cout << "Enter the keyword to find: ";
                cin >> keyword;
                auto it = dictionary.find(keyword);
                if (it != dictionary.end()) {
                    int comparisons = distance(dictionary.begin(), it) + 1;
                    cout << "Maximum comparisons required: " << comparisons << endl;
                } else {
                    cout << "Keyword not found." << endl;
                }
                break;
            }
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
