#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Graph {
private:
    unordered_map<string, vector<pair<string, int>>> adjacencyList;

public:
    void addEdge(const string& source, const string& destination, int cost) {
        adjacencyList[source].push_back(make_pair(destination, cost));
        adjacencyList[destination].push_back(make_pair(source, cost));
    }

    bool isConnected() {
        unordered_map<string, bool> visited;

        queue<string> q;
        q.push(adjacencyList.begin()->first);
        visited[q.front()] = true;

        while (!q.empty()) {
            string currentCity = q.front();
            q.pop();

            for (const auto& neighbor : adjacencyList[currentCity]) {
                const string& neighborCity = neighbor.first;

                if (!visited[neighborCity]) {
                    visited[neighborCity] = true;
                    q.push(neighborCity);
                }
            }
        }

        for (const auto& [city, visit] : visited) {
            if (!visit) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Graph flightGraph;
    int choice;

    do {
        cout << "Menu:" << endl;
        cout << "1. Add flight path between cities" << endl;
        cout << "2. Check if the graph is connected" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string source, destination;
                int cost;
                cout << "Enter the source city: ";
                cin >> source;
                cout << "Enter the destination city: ";
                cin >> destination;
                cout << "Enter the cost: ";
                cin >> cost;
                flightGraph.addEdge(source, destination, cost);
                cout << "Flight path added successfully!" << endl;
                break;
            }
            case 2:
                if (flightGraph.isConnected()) {
                    cout << "The graph is connected." << endl;
                } else {
                    cout << "The graph is not connected." << endl;
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
