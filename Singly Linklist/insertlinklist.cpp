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

void  insertAtHead(Node* &tail,Node* &head,int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    // how to insert at a link list

    //step 1:
    Node* newNode = new Node(data);

   //step2: link the new node to the head
    newNode -> next = head;

    head = newNode;

    
  
}

void insertAtTail(Node* &tail,Node* &head,int data){
    // i want a print at a tail 
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    //step1:  create a new node
    Node* newNode = new Node(data);

    //if the list is empty, update both head and a tail
   
        //step2: link the new node to the current tail
         tail -> next = newNode;

        //step3: update a tail

        tail = newNode;
    

   
}

int main(){

    Node* head = NULL;
    Node* tail =NULL;
    insertAtHead(tail,head,33);
    insertAtHead(tail,head,44);
    insertAtHead(tail,head,55);
    insertAtHead(tail,head,66);
    insertAtTail(tail,head,77);
    print(head);

    return 0;

}