#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int TABLE_SIZE = 10; 

struct Client {
    string name;
    string phoneNumber;
};

class HashTable {
private:
    vector<Client> table; 
    vector<bool> isOccupied; 

    int hashFunction(const string& key) {
        int sum = 0;
        for (size_t i = 0; i < key.length(); i++) {
            sum += key[i];
        }
        return sum % TABLE_SIZE;
    }

    int linearProbe(int index, int attempt) {
        return (index + attempt) % TABLE_SIZE;
    }

    int quadraticProbe(int index, int attempt) {
        return (index + attempt * attempt) % TABLE_SIZE;
    }

public:
    HashTable() {
        table.resize(TABLE_SIZE);
        isOccupied.resize(TABLE_SIZE, false);
    }

    void insertClientLinear(const string& name, const string& phoneNumber) {
        int index = hashFunction(name);
        int attempt = 0;

        while (isOccupied[index]) {
            index = linearProbe(index, attempt);
            attempt++;
        }

        table[index] = { name, phoneNumber };
        isOccupied[index] = true;
    }

    void insertClientQuadratic(const string& name, const string& phoneNumber) {
        int index = hashFunction(name);
        int attempt = 0;

        while (isOccupied[index]) {
            index = quadraticProbe(index, attempt);
            attempt++;
        }

        table[index] = { name, phoneNumber };
        isOccupied[index] = true;
    }

    void searchClient(const string& name) {
        int index = hashFunction(name);
        int attempt = 0;

        while (isOccupied[index]) {
            if (table[index].name == name) {
                cout << "Phone Number: " << table[index].phoneNumber << endl;
                cout << "Number of comparisons: " << (attempt + 1) << endl;
                return;
            }

            index = linearProbe(index, attempt); 
            attempt++;
        }

        cout << "Client not found." << endl;
        cout << "Number of comparisons: " << (attempt + 1) << endl;
    }
};

int main() {
    HashTable telephoneBook;
    int choice;
    string name, phoneNumber;

    do {
        cout << "Telephone Book Menu:" << endl;
        cout << "1. Add Client using Linear Probing" << endl;
        cout << "2. Add Client using Quadratic Probing" << endl;
        cout << "3. Search Client" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter client name: ";
                cin >> name;
                cout << "Enter client phone number: ";
                cin >> phoneNumber;
                telephoneBook.insertClientLinear(name, phoneNumber);
                cout << "Client added successfully using Linear Probing!" << endl;
                break;
            case 2:
                cout << "Enter client name: ";
                cin >> name;
                cout << "Enter client phone number: ";
                cin >> phoneNumber;
                telephoneBook.insertClientQuadratic(name, phoneNumber);
                cout << "Client added successfully using Quadratic Probing!" << endl;
                break;
            case 3:
                cout << "Enter client name to search: ";
                cin >> name;
                telephoneBook.searchClient(name);
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    } while (choice != 4);

    return 0;
}

