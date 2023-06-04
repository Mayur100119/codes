#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    string content;
    vector<Node*> children;

    Node(const string& content) : content(content) {}

    void addChild(Node* child) {
        children.push_back(child);
    }

    void print(int depth = 0) {
        for (int i = 0; i < depth; i++) {
            cout << "  "; 
        }
        cout << content << endl;
        for (Node* child : children) {
            child->print(depth + 1);
        }
    }
};

int main() {
    Node* book = new Node("Book");

    int choice;
    string content;

    do {
        cout << "Menu:" << endl;
        cout << "1. Add Chapter" << endl;
        cout << "2. Add Section" << endl;
        cout << "3. Add Subsection" << endl;
        cout << "4. Print Book Structure" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Chapter title: ";
                cin.ignore();
                getline(cin, content);
                book->addChild(new Node(content));
                cout << "Chapter added successfully!" << endl;
                break;
            case 2: {
                cout << "Enter Chapter index to add Section: ";
                int chapterIndex;
                cin >> chapterIndex;
                if (chapterIndex < 0 || chapterIndex >= book->children.size()) {
                    cout << "Invalid Chapter index!" << endl;
                    break;
                }
                Node* chapter = book->children[chapterIndex];
                cout << "Enter Section title: ";
                cin.ignore();
                getline(cin, content);
                chapter->addChild(new Node(content));
                cout << "Section added successfully!" << endl;
                break;
            }
            case 3: {
                cout << "Enter Chapter index to add Subsection: ";
                int chapterIndex;
                cin >> chapterIndex;
                if (chapterIndex < 0 || chapterIndex >= book->children.size()) {
                    cout << "Invalid Chapter index!" << endl;
                    break;
                }
                Node* chapter = book->children[chapterIndex];
                cout << "Enter Section index to add Subsection: ";
                int sectionIndex;
                cin >> sectionIndex;
                if (sectionIndex < 0 || sectionIndex >= chapter->children.size()) {
                    cout << "Invalid Section index!" << endl;
                    break;
                }
                Node* section = chapter->children[sectionIndex];
                cout << "Enter Subsection title: ";
                cin.ignore();
                getline(cin, content);
                section->addChild(new Node(content));
                cout << "Subsection added successfully!" << endl;
                break;
            }
            case 4:
                cout << "Book Structure:" << endl;
                book->print();
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    } while (choice != 0);

    delete book;

    return 0;
}
