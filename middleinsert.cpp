#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* &head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int findLength(Node* &head) {
    int len = 0;
    Node* temp = head;
    while (temp != NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtHead(Node* &tail, Node* &head, int data) {
    // check for empty link list

    if (head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // Step 1: Create a new node
    Node* newNode = new Node(data);

    // Step 2: Link the new node to the head
    newNode->next = head;

    // Step 3: Update the head
    head = newNode;
}

void insertAtTail(Node* &tail, Node* &head, int data) {
    if (head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // Step 1: Create a new node
    Node* newNode = new Node(data);

    // Step 2: Link the new node to the current tail
    tail->next = newNode;

    // Step 3: Update the tail
    tail = newNode;
}

void insertAtPosition(int data, int position, Node* &tail, Node* &head) {
    if (head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // If inserting at the head
    if (position == 0) {
        insertAtHead(tail, head, data);
        return;
    }

    int len = findLength(head);
    // If inserting at the tail
    if (position >= len) {
        insertAtTail(tail, head, data);
        return;
    }

    // Find the position: prev and current
    int i = 1;
    Node* prev = head;
    while (i < position) {
        prev = prev->next;
        i++;
    }
    Node* curr = prev->next;

    // Step 2: Create a new node
    Node* newNode = new Node(data);

    // Step 3: Link new node to the current node
    newNode->next = curr;

    // Step 4: Link previous node to the new node
    prev->next = newNode;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(tail, head, 33);
    insertAtHead(tail, head, 44);
    insertAtHead(tail, head, 55);
    insertAtHead(tail, head, 66);
    insertAtTail(tail, head, 77);

    print(head);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;

    insertAtPosition(101, 4, tail, head);
    print(head);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;

    return 0;
}
 