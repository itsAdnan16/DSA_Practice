#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(){
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
void print(Node *head){
    Node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}
void InsertAtTail(Node*&head,Node*&tail,int data){
    if(head==NULL){
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        Node * newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
        tail->next = NULL;
    }
}
int main(){
    Node * first = new Node(1);
    Node * tail = head;
    insert
}