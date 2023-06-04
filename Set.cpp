#include <iostream>
#include <unordered_set>

using namespace std;

class Set {
private:
    unordered_set<int> elements;

public:
    void Add(int element) {
        elements.insert(element);
    }

    void Remove(int element) {
        elements.erase(element);
    }

    bool Contains(int element) const {
        return elements.count(element) > 0;
    }

    size_t Size() const {
        return elements.size();
    }

    Set Intersection(const Set& other) const {
        Set result;
        for (int element : elements) {
            if (other.Contains(element)) {
                result.Add(element);
            }
        }
        return result;
    }

    Set Union(const Set& other) const {
        Set result = *this;
        for (int element : other.elements) {
            result.Add(element);
        }
        return result;
    }

    Set Difference(const Set& other) const {
        Set result;
        for (int element : elements) {
            if (!other.Contains(element)) {
                result.Add(element);
            }
        }
        return result;
    }

    bool IsSubsetOf(const Set& other) const {
        for (int element : elements) {
            if (!other.Contains(element)) {
                return false;
            }
        }
        return true;
    }

    void Print() const {
        cout << "Set elements: ";
        for (int element : elements) {
            cout << element << " ";
        }
        cout << endl;
    }
};

int main() {
    Set set;
    int choice;
    int element;

    do {
        cout << "Set Menu:" << endl;
        cout << "1. Add element" << endl;
        cout << "2. Remove element" << endl;
        cout << "3. Check if element is in set" << endl;
        cout << "4. Get size of set" << endl;
        cout << "5. Print set" << endl;
        cout << "6. Perform intersection with another set" << endl;
        cout << "7. Perform union with another set" << endl;
        cout << "8. Perform difference with another set" << endl;
        cout << "9. Check if set is a subset of another set" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to add: ";
                cin >> element;
                set.Add(element);
                cout << "Element added successfully!" << endl;
                break;
            case 2:
                cout << "Enter element to remove: ";
                cin >> element;
                set.Remove(element);
                cout << "Element removed successfully!" << endl;
                break;
            case 3:
                cout << "Enter element to check: ";
                cin >> element;
                if (set.Contains(element)) {
                    cout << "Element is present in the set." << endl;
                } else {
                    cout << "Element is not present in the set." << endl;
                }
                break;
            case 4:
                cout << "Size of the set: " << set.Size() << endl;
                break;
            case 5:
                set.Print();
                break;
            case 6: {
                Set intersection;
                cout << "Enter elements of the other set (0 to stop): ";
                while (cin >> element && element != 0) {
                    intersection.Add(element);
                }
                Set result = set.Intersection(intersection);
                cout << "Intersection: ";
                result.Print();
                break;
            }
            case 7: {
                Set unionSet;
                cout << "Enter elements of the other set (0 to stop): ";
                while (cin >> element && element != 0) {
                    unionSet.Add(element);
                }
                Set result = set.Union(unionSet);
                cout << "Union: ";
                result.Print();
                break;
            }
            case 8: {
                Set difference;
                cout << "Enter elements of the other set (0 to stop): ";
                while (cin >> element && element != 0) {
                    difference.Add(element);
                }
                Set result = set.Difference(difference);
                cout << "Difference: ";
                result.Print();
                break;
            }
            case 9: {
                Set subset;
                cout << "Enter elements of the other set (0 to stop): ";
                while (cin >> element && element != 0) {
                    subset.Add(element);
                }
                bool isSubset = set.IsSubsetOf(subset);
                if (isSubset) {
                    cout << "Set is a subset of the other set." << endl;
                } else {
                    cout << "Set is not a subset of the other set." << endl;
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
