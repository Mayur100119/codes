#include <iostream>
#include <stack>

using namespace std;

class Node {
public:
    char data;
    Node* left;
    Node* right;

    Node(char value) : data(value), left(nullptr), right(nullptr) {}
};

class ExpressionTree {
private:
    Node* root;

public:
    ExpressionTree() : root(nullptr) {}

    void constructTree(const string& expression) {
        stack<Node*> s;

        for (int i = expression.size() - 1; i >= 0; i--) {
            char symbol = expression[i];

            if (isOperand(symbol)) {
                Node* newNode = new Node(symbol);
                s.push(newNode);
            } else {
                Node* newNode = new Node(symbol);
                newNode->left = s.top();
                s.pop();
                newNode->right = s.top();
                s.pop();

                s.push(newNode);
            }
        }

        root = s.top();
        s.pop();
    }

    void postOrderTraversal() {
        if (root == nullptr) {
            cout << "The tree is empty!" << endl;
            return;
        }

        stack<Node*> s;
        Node* current = root;
        Node* lastVisited = nullptr;

        while (current != nullptr || !s.empty()) {
            if (current != nullptr) {
                s.push(current);
                current = current->left;
            } else {
                Node* topNode = s.top();

                if (topNode->right != nullptr && topNode->right != lastVisited) {
                    current = topNode->right;
                } else {
                    cout << topNode->data << " ";
                    lastVisited = topNode;
                    s.pop();
                }
            }
        }

        cout << endl;
    }

    void deleteTree(Node* node) {
        if (node == nullptr) {
            return;
        }

        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

    void deleteEntireTree() {
        deleteTree(root);
        root = nullptr;
    }

private:
    bool isOperand(char symbol) {
        return isalpha(symbol) || isdigit(symbol);
    }
};

int main() {
    ExpressionTree et;
    string expression;
    int choice;

    do {
        cout << "Menu:" << endl;
        cout << "1. Construct expression tree" << endl;
        cout << "2. Post-order traversal" << endl;
        cout << "3. Delete the entire tree" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the prefix expression: ";
                cin >> expression;
                et.constructTree(expression);
                cout << "Expression tree constructed successfully!" << endl;
                break;
            case 2:
                cout << "Post-order traversal: ";
                et.postOrderTraversal();
                break;
            case 3:
                et.deleteEntireTree();
                cout << "The entire tree has been deleted!" << endl;
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
