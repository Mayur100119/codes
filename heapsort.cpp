#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void displayArray(const vector<int>& array) {
    cout << "Array: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;
}

void heapSort(vector<int>& array) {
    priority_queue<int, vector<int>, greater<int>> pq(array.begin(), array.end());
    for (int i = 0; i < array.size(); i++) {
        array[i] = pq.top();
        pq.pop();
    }
}

int main() {
    vector<int> array;
    int num;

    cout << "Enter the elements of the array (separated by space, 0 to stop): ";
    while (cin >> num && num != 0) {
        array.push_back(num);
    }

    heapSort(array);
    cout << "Array sorted using Heap Sort." << endl;
    displayArray(array);

    return 0;
}
