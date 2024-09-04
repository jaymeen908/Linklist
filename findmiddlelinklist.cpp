#include <iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;

    }
    cout << endl;
}

Node* getMiddle(Node* &head){
    if(head == NULL){
        cout << "LL is empty" << endl;
        return head;
    }

    if(head -> next == NULL){
        // they have only  one link list then have to return the head
        return head;
    }

    //LL is grater than 1
    Node* slow = head;
    Node* fast = head -> next;

    while(slow != NULL && fast != NULL){
        fast = fast -> next;
        if(fast != NULL){
            fast = fast -> next;
            slow = slow -> next;

        }
    } 
    return slow;
}

int main(){

    Node* head = new Node(10);
    Node* seconde = new Node(20);
    Node* third =  new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);
    Node* seven = new Node(70);

    head->next = seconde;
    seconde-> next = third;
    third-> next = fourth;
    fourth-> next = fifth;
    fifth-> next = sixth;
    sixth -> next = seven;
    seven -> next = NULL;

    print(head);

    cout << "getMiddle node of link list  " << getMiddle(head) -> data << endl;
    return 0;
}