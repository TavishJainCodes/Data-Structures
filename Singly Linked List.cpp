#include <iostream>
#include <climits>
#include <vector>
#include <unistd.h>

using namespace std;

class Node {
private:
    int data;
    Node* next;

public:
    Node(int key) {
        data = key;
        next = nullptr;
    }

    void insertAtStart(Node** head, int key);
    void insertAfterNode(Node* head, int prevKey, int key);
    void insertAtEnd(Node* endNode, int key);

    Node* searchElement(Node* head, int key);

    void deleteAtStart(Node** head);
    void deleteAfterNode(Node* head, int key);

    void printList(Node* head);

    void reverseList(Node** head);
};

void Node::insertAtStart(Node** head, int key) {
    Node* newNode = new Node(key);
    newNode->next = *head;
    *head = newNode;

    cout << "\nInserted '" << key << "' at the start of the list." << endl;
}

void Node::insertAfterNode(Node* head, int prevKey, int key) {
    Node* prevNode = this->searchElement(head, prevKey);

    if (prevNode == NULL) {
        cout << "Given previous Node is NULL" << endl;
        return;
    }

    Node* newNode = new Node(key);
    newNode->next = prevNode->next;
    prevNode->next = newNode;

    cout << "\nInserted '" << key << "' after '" << prevNode->data << "' in the list." << endl;
}

void Node::insertAtEnd(Node* head, int key) {

    Node* endNode = head;
    while (endNode->next != NULL) {
        endNode = endNode->next;
    }

    if (endNode == NULL) {
        cout << "Given end Node is NULL" << endl;
        return;
    }

    Node* newNode = new Node(key);
    endNode->next = newNode;

    cout << "\nInserted '" << key << "' at the end of the list." << endl;
}

Node* Node::searchElement(Node* head, int key) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void Node::deleteAtStart(Node** head) {
    if (head == NULL) {
        cout << "The List is Empty." << endl;
        return;
    }

    Node* temp = *head;
    *head = temp->next;

    cout << "\nDeleted '" << temp->data << "' from the list." << endl;

    free(temp);
}

void Node::deleteAfterNode(Node* head, int key) {
    head = this->searchElement(head, key);

    if (head->next == NULL) {
        cout << "No element after the given key." << endl;
        return;
    }

    Node* temp = head->next;
    head->next = temp->next;

    cout << "\nDeleted '" << temp->data << "' from the list." << endl;

    free(temp);
}

void Node::printList(Node* head) {
    Node* current = head;

    cout << "List: ";
    while (current->next != NULL) {
        cout << current->data << ", ";
        current = current->next;
    }
    cout << current->data << "\n";
}

void Node::reverseList(Node** head) {
    Node* next = NULL;
    Node* current = *head;
    Node* prev = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

int main() {
    cout << "\nEnter element to initialize the LinkedList with: ";
    int* init = new int;
    cin >> *init;

    Node* ll = new Node(*init);
    delete init;

    bool loop = true;

    while (loop) {
        cout << "\n\nSelect one of the following tasks: " << endl;
        cout << "1. Insert element at start of the LinkedList" << endl;
        cout << "2. Insert element at the end of the LinkedList" << endl;
        cout << "3. Insert element after an element in the LinkedList" << endl;
        cout << "4. Delete element from the start of the LinkedList" << endl;
        cout << "5. Delete element after an element from the LinkedList" << endl;
        cout << "6. Print the LinkedList" << endl;
        cout << "7. Reverse the LinkedList" << endl;
        cout << "8. Exit the code" << endl;
        cout << "\nEnter your choice: ";

        char c;
        cin >> c;

        cout << endl;

        int* temp = nullptr;
        int* temp1 = nullptr;

        switch (c) {
        case '1':
            cout << "Enter the element to insert: ";
            temp = new int;
            cin >> *temp;
            ll->insertAtStart(&ll, *temp);
            delete temp;
            break;
        case '2':
            cout << "Enter the element to insert: ";
            temp = new int;
            cin >> *temp;
            ll->insertAtEnd(ll, *temp);
            delete temp;
            break;
        case '3':
            cout << "Enter the element to insert: ";
            temp = new int;
            cin >> *temp;
            cout << "Enter the previous element: ";
            temp1 = new int;
            cin >> *temp1;
            ll->insertAfterNode(ll, *temp1, *temp);
            delete temp;
            delete temp1;
            break;
        case '4':
            ll->deleteAtStart(&ll);
            break;
        case '5':
            cout << "Enter the previous element: ";
            temp = new int;
            cin >> *temp;
            ll->deleteAfterNode(ll, *temp);
            delete temp;
            break;
        case '6':
            ll->printList(ll);
            break;
        case '7':
            ll->reverseList(&ll);
            break;
        case '8':
            cout << "Exiting Code...";
            loop = false;
            break;
        default:
            cout << "Wrong choice! Try Again!" << endl;
            break;
        }
    }

    return 0;
}
