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
int len(Node*head){
    Node*temp = head;
    int count = 0;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count++;

}
void InsertAtHead(Node*&head,Node*&tail,int data){
    if(head==NULL){
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
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
/*void Insert(Node*&head,Node*tail,int pos,int data){
    if(pos<1){
        cout<<"Not Possible";
    }
    else if(pos>len(head) + 1){
        cout<<"Not possible";
    }
    else if(pos==1){
        InsertAtHead(head,tail,data);
    }
    else if(pos==len(head) + 1 ){
        InsertAtTail(head,tail,data);
    }
    else{
        Node*temp = head;
        Node * newNode =  new Node(data);
      for(int i=0;i<pos-2;i++){//indexing starting from 1
       // for(int i=0;i<pos-1;i++){//if indexing starting from 0

            temp=temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

}*/
void insert(Node *&head,Node * tail,int pos,int data){
    if(head == NULL){
        cout<<"Cannot insert in empty linked list";
        return;
    }
     if(pos<1){
        cout<<"Not Possible";
    }
    else if(pos>len(head) + 1){
        cout<<"Not possible";
    }
    else if(pos==1){
        InsertAtHead(head,tail,data);
    }
    else if(pos==len(head) + 1 ){
        InsertAtTail(head,tail,data);
    }
    else{
        Node * current = head;
        Node*prev = NULL;
        while(pos!=1){
            prev = current;
            current = current->next;
            pos--;
        }
        Node * newNode = new Node(data);
        newNode->next = current;
        prev->next = newNode;
    }
}
Node* CreateTail(Node*&head){
    Node*temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    return temp;
}

/*void insert(Node * NewNode, Node* & head, int position){
    if(position == 0){
        NewNode->next = head;
        head = NewNode;
    }
    else if(position >= len(head)){
        Node*temp = head;
        while(temp->next=NULL){
            temp=temp->next;
        }
        temp->next = NewNode;
        NewNode->next = NULL;
    }
    else{
        Node*temp = head;
        for(int i=0;i<position-1;i++){
            temp=temp->next;
        }
        NewNode->next=temp->next;
        temp->next=NewNode;
    }
}*/
//Code for deletion
void Delete(Node*&head,Node*&tail,int data,int pos){
    if(head==NULL){
        cout<<"Cannot delete from empty list";
        return;
    }
    if(head == tail){
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }
    if(pos==1){
        Node *temp = head;
        head = temp->next;//head = head->next
        temp->next = NULL;
        delete temp;
    }
    else if(pos==len(head)){
        Node * prev = head;
        while(prev->next !=tail){
            prev = prev->next;
        }
        prev->next = NULL;
        delete tail;
        tail = prev;
    }
    else{
        Node * current = head;
        Node * prev = NULL;
        while(pos!=1){
            prev = current;
            current = current->next;
            pos--;
        }
        prev->next = current->next;
        current->next = NULL;
        delete current;
    }
}

int main(){
    Node* first = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(4);
    Node* fourth = new Node(5);
   /*Node*NewNode1 = new Node(3);
    Node*NewNode2 = new Node(0);
    Node*NewNode3 = new Node(6);*/

    //linking all the nodes together

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    //first node = first , last node = tail

    Node* head = first; 
    Node*tail = fourth;
    //InsertAtHead(head,tail,0);
    //InsertAtTail(head,tail,6);

    //cout<<len(head);
    //insert(NewNode3,head,6);

   // Node* duplicate_tail = CreateTail(head);
    //cout<<"Tail created "<<duplicate_tail->data;

    //Insert(head,tail,2,3);
    insert(head,tail,3,3);
    cout<<"Before Deleting "<<endl;
    print(head);
    cout<<"After Deleting "<<endl;
   // Delete(head,tail,2,2);
    //print(head);
  
}
