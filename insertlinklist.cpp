#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(){
        this->data = 0;
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data <<" ";
        temp = temp->next;
    }
}

void  insertAt(Node* &head,int data){
    // how to insert at a link list

    //step 1:
    Node* newNode = new Node(data);

    //step 2:
    newNode -> next = head;

    //step 3:

    head = newNode;
}
int main(){

    Node* head = new Node(10);
    insertAt(head,33);
    insertAt(head,44);
    insertAt(head,55);
    insertAt(head,66);
    print(head);

}