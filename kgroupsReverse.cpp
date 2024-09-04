#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

int getLength(Node* &head) {
    int len = 0;
    Node* temp = head;
    while(temp != NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}

void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* reverseKNodes(Node* &head, int k) {
    if(head == NULL) {
        cout << "Linked list is empty." << endl;
        return NULL;
    }

    int len = getLength(head);
    if(k > len) {
        cout << "Enter a valid k." << endl;
        return head;
    }

    // Step 1: Reverse the first k nodes of the linked list
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    int count = 0;

    while(count < k && curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    // Step 2: Recursively call for the next part of the linked list
    if(forward != NULL) {
        head->next = reverseKNodes(forward, k);
    }

    // prev is the new head of the reversed part
    return prev;
}

int main() {
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = NULL;

    cout << "Original Linked List: ";
    print(head);

    // Reverse the linked list in groups of 3
    head = reverseKNodes(head, 3);

    cout << "Reversed Linked List in groups of 3: ";
    print(head);

    return 0;
}
