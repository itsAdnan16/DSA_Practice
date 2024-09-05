#include<iostream>
using namespace std;

class Node{
    public:
    Node * next;
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
    Node * newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode ;
        tail = newNode;
    }
}
Node * Find_mid(Node*head){
    Node*fast = head;
    Node*slow = head;
    while(fast->next != NULL){
        fast = fast->next;
        if(fast->next!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow; 
}
void reverse(Node* &head){
    Node *prev = NULL;
    Node *temp = head;
    Node *current = head;

    while(temp!=NULL){
        temp = temp->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    head = prev;
}
bool compare_list(Node*&head1 , Node *& head2){
    while(head1!=NULL && head2!=NULL){
        if(head1->data == head2->data){
            head1 = head1->next;
            head2=head2->next;
        }else{
            return false;
        }
    }
    return true;
}

bool palin(Node*&head){
    Node * temp = head;
    Node * mid = Find_mid(head);
    Node * head2 = mid->next;
    //dividing the into halves
    mid->next = NULL;
    reverse(head2);
    return compare_list(temp,head2);
}
void print(Node*head){
    Node * temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}
int main(){
    Node * head = new Node(1);
    Node * tail =head;
    insert_tail(head,tail,2);
    insert_tail(head,tail,4);
    insert_tail(head,tail,6);
    insert_tail(head,tail,6);
    insert_tail(head,tail,4);
    insert_tail(head,tail,2);
    insert_tail(head,tail,1);
    print(head);
    cout<<endl;
    if(palin(head)){
        cout<<"Yes it is palindrome";
    }
}


