#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node*prev;
    Node(){
        this->next = NULL;
        this->prev = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
void print(Node*&head){
    Node*temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
}

int len(Node * head){
    Node*temp = head;
    int count = 0;
    while(temp!=NULL){
        temp = temp->next;
        count ++;
    }
    return count++;
}

Node* CreateTail(Node*&head){
    Node*temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    return temp;
}

void insert_at_head(Node*&head,Node*&tail,int data){
    if(head == NULL){
        Node * newNode = new Node(data);
        newNode ->next = NULL;
        newNode ->prev = NULL;
        head = newNode;
        tail = newNode;
    }else{
        Node * newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}
void insert_at_tail(Node*&head,Node*&tail,int data){
    if(tail==NULL){
        Node * newNode = new Node(data);
        newNode->next = NULL;
        newNode->prev = NULL;
        head = newNode;
        tail = newNode;
    }else{
        Node * newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = NULL;
        tail = newNode;
    }
}

void insert(Node*&head,Node*&tail,int data,int pos){
    if(head == NULL){
        Node * newNode = new Node(data);
        head = newNode;
        tail = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;

        return;
    }
    if(pos == 1){
        insert_at_head(head,tail,data);
    }
    else if(pos == len(head) + 1){
        insert_at_tail(head,tail,data);
    }
    else{
        Node * newNode = new Node(data);
        Node * previous = NULL;
        Node * current = head;
        while(pos!=1){
            previous = current;
            current = current->next;
            pos--;
        }
        newNode->next = current;
        newNode->prev = previous;
        previous->next = newNode;
        current->prev = newNode;
    }
}

void delete_head(Node* &head,Node* &tail){
    if(head==NULL){
        cout<<"Cannot delete";
    }
    else{
        
        Node*temp = head;
        head = head->next;
        //isolate
        temp->next = NULL;
        head->prev = NULL;
        //now kill
        delete temp;
    
    }
}
void delete_tail(Node*&head,Node*&tail){
    if(tail == NULL){
        cout<<"Cannot delete";
    }
    else{
        Node*temp = tail;
        tail = temp->prev;
        //now isolate
        tail->next = NULL;
        temp->prev = NULL;
        //now delete_tail
        delete temp;
    }
}

void Delete(Node*&head,Node*&tail,int pos){
    if(head == NULL){
        cout<<"Cannot Delete";
    }
    if(head == tail){
        Node * temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
    }
    if(pos == 1){
        delete_head(head,tail);
    }
    else if(pos == len(head)){
        delete_tail(head,tail);
    }
    else{
        Node * current = head;
        Node * prev_node = NULL;
        while(pos!=1){
            prev_node = current;
            current = current->next;
            pos--;
        }
        prev_node->next = current->next;
        current->next->prev = prev_node;
        
        //now we will isolate
        current->next = NULL;
        current->prev = NULL;
        
        //now we will delete
        delete current;
        
    }
}



int main(){
    Node * newNode = new Node(10);;
    Node * head = newNode;
    Node * tail = head;

    
   /* insert_at_head(head,tail,10);
    insert_at_head(head,tail,20);
    insert_at_head(head,tail,30);*/
    
    insert_at_tail(head,tail,20);
    insert_at_tail(head,tail,40);
    insert_at_tail(head,tail,50);
    
    //Node * tail = CreateTail(head)
    
    cout<<"Before inserting "<<endl;
    print(head);
    cout<<endl;
    
    insert(head,tail,30,3);
    cout<<"After inserting "<<endl;
    print(head);
    cout<<endl;
    
    cout<<"Before deleting "<<endl;
    print(head);
    cout<<endl;
    
    //delete_head(head,tail);
    //delete_tail(head,tail);
    
    Delete(head,tail,4);
    
    cout<<"After deleting "<<endl;
    
    print(head);
    cout<<endl;
    
   /* Node*first = head->next->prev;//0
    Node*second = head->next->next->prev;//10
    
    cout<<first->data<<" "<<second->data;*/
    
}