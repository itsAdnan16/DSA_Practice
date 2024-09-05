#include<iostream>
using namespace std;

class Node{
    public:
    Node*next;
    int data;
    Node(){
        this->next = NULL;
    }
    Node(int data){
        this->next = NULL;
        this->data = data;
    }
};

void insert_tail(Node*&head,Node*&tail,int data){
    if(head==NULL){
        Node * newNode = new Node(data);
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
void print(Node *head){
    Node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}
void reverse(Node* &head,Node* &tail){
    Node *prev = NULL;
    Node *temp = head;
    Node* current = head;

    while(temp!=NULL){
        temp = temp->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    head = prev;
}
void reverse_recursion(Node* &head,Node* &tail,Node*&temp,Node*&prev,Node*&current){
    //Base Case
    if(temp==NULL){
        return;
    }
    //one step we are solving
    temp = temp->next;
    current->next = prev;
    prev = current;
    current = temp;
    
    //now recursion will solve.
    reverse_recursion(head,tail,temp,prev,current);
}
void helper(Node*&head,Node*&tail){
    Node *prev = NULL;
    Node *temp = head;
    Node* current = head;

    reverse_recursion(head,tail,temp,prev,current);
    head = prev;
}
int main(){
    Node * head = NULL;
    Node * tail = head;
    insert_tail(head,tail,1);
    insert_tail(head,tail,2);
    insert_tail(head,tail,3);
    insert_tail(head,tail,4);

    cout<<"Before Reversing the linked list"<<endl;
    print(head);
    cout<<endl;

    cout<<"Linked list after reversing"<<endl;
    //reverse(head,tail);
    helper(head,tail);
    print(head);

}