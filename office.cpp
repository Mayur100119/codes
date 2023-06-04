#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;

struct Edge {
    string source;
    string destination;
    int cost;
};

class Graph {
private:
    unordered_map<string, vector<Edge>> adjacencyList;

public:
    void addEdge(const string& source, const string& destination, int cost) {
        adjacencyList[source].push_back({source, destination, cost});
        adjacencyList[destination].push_back({destination, source, cost});
    }

    vector<Edge> findMinimumSpanningTree() {
        vector<Edge> minimumSpanningTree;
        unordered_map<string, bool> visited;
        unordered_map<string, int> minCost;

        for (const auto& [office, _] : adjacencyList) {
            minCost[office] = INT_MAX;
        }

        minCost.begin()->second = 0; 

        for (int i = 0; i < adjacencyList.size(); ++i) {
            string minCostVertex;
            int minCostValue = INT_MAX;

            for (const auto& [office, _] : adjacencyList) {
                if (!visited[office] && minCost[office] < minCostValue) {
                    minCostVertex = office;
                    minCostValue = minCost[office];
                }
            }

            visited[minCostVertex] = true;

            // Add the minimum cost edge to the minimum spanning tree
            if (!minCostVertex.empty()) {
                for (const auto& edge : adjacencyList[minCostVertex]) {
                    if (visited[edge.destination]) {
                        continue;
                    }
                    minimumSpanningTree.push_back(edge);
                }
            }

            // Update the minimum cost of neighboring offices
            for (const auto& edge : adjacencyList[minCostVertex]) {
                int totalCost = minCost[edge.source] + edge.cost;
                if (totalCost < minCost[edge.destination]) {
                    minCost[edge.destination] = totalCost;
                }
            }
        }

        return minimumSpanningTree;
    }
};

int main() {
    Graph officeGraph;
    int choice;

    do {
        cout << "Menu:" << endl;
        cout << "1. Add phone line between offices" << endl;
        cout << "2. Find minimum cost connections" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string source, destination;
                int cost;
                cout << "Enter the source office: ";
                cin >> source;
                cout << "Enter the destination office: ";
                cin >> destination;
                cout << "Enter the cost: ";
                cin >> cost;
                officeGraph.addEdge(source, destination, cost);
                cout << "Phone line added successfully!" << endl;
                break;
            }
            case 2: {
                vector<Edge> minimumSpanningTree = officeGraph.findMinimumSpanningTree();
                int totalCost = 0;
                cout << "Minimum cost connections: " << endl;
                for (const auto& edge : minimumSpanningTree) {
                    cout << "Office " << edge.source << " -- Office " << edge.destination << ", Cost: " << edge.cost << endl;
                    totalCost += edge.cost;
                }
                cout << "Total cost: " << totalCost << endl;
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
