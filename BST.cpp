#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insertNode(root, value);
    }

    int longestPath() {
        return longestPathFromRoot(root);
    }

    int minValue() {
        return findMinValue(root);
    }

    void swapRoles() {
        swapRolesHelper(root);
    }

    bool search(int value) {
        return searchValue(root, value);
    }

    void printInOrder() {
        printInOrderTraversal(root);
    }

private:
    Node* insertNode(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }

        if (value < root->data) {
            root->left = insertNode(root->left, value);
        } else if (value > root->data) {
            root->right = insertNode(root->right, value);
        }

        return root;
    }

    int longestPathFromRoot(Node* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftHeight = longestPathFromRoot(root->left);
        int rightHeight = longestPathFromRoot(root->right);

        return 1 + max(leftHeight, rightHeight);
    }

    int findMinValue(Node* root) {
        if (root == nullptr) {
            cout << "The tree is empty!" << endl;
            return -1;
        }

        while (root->left != nullptr) {
            root = root->left;
        }

        return root->data;
    }

    void swapRolesHelper(Node* root) {
        if (root == nullptr) {
            return;
        }

        Node* temp = root->left;
        root->left = root->right;
        root->right = temp;

        swapRolesHelper(root->left);
        swapRolesHelper(root->right);
    }

    bool searchValue(Node* root, int value) {
        if (root == nullptr) {
            return false;
        }

        if (value == root->data) {
            return true;
        }

        if (value < root->data) {
            return searchValue(root->left, value);
        } else {
            return searchValue(root->right, value);
        }
    }

    void printInOrderTraversal(Node* root) {
        if (root == nullptr) {
            return;
        }

        printInOrderTraversal(root->left);
        cout << root->data << " ";
        printInOrderTraversal(root->right);
    }
};

int main() {
    BinarySearchTree bst;
    int choice;
    int value;

    do {
        cout << "Menu:" << endl;
        cout << "1. Insert new node" << endl;
        cout << "2. Find number of nodes in longest path from root" << endl;
        cout << "3. Minimum data value found in the tree" << endl;
        cout << "4. Change the tree so that left and right pointers are swapped" << endl;
        cout << "5. Search a value" << endl;
        cout << "6. Print the tree in order" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                bst.insert(value);
                cout << "Node inserted successfully!" << endl;
                break;
            case 2:
                cout << "Number of nodes in the longest path from root: " << bst.longestPath() << endl;
                break;
            case 3:
                cout << "Minimum data value in the tree: " << bst.minValue() << endl;
                break;
            case 4:
                bst.swapRoles();
                cout << "Tree roles swapped successfully!" << endl;
                break;
            case 5:
                cout << "Enter the value to search: ";
                cin >> value;
                if (bst.search(value)) {
                    cout << "Value found in the tree." << endl;
                } else {
                    cout << "Value not found in the tree." << endl;
                }
                break;
            case 6:
                cout << "Tree in order traversal: ";
                bst.printInOrder();
                cout << endl;
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
