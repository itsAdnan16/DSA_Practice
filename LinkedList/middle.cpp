/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/*class Solution {
public:
    int len(ListNode* head){
        ListNode*temp = head;;
        int count = 0;
        while(temp!=NULL){
            temp = temp->next;
            count++;
        }
        return count;
    }
    ListNode* middleNode(ListNode* head) {
       /
        //method 1
        /*int length = len(head);
        ListNode * temp = head;
        for(int i=1;i<=length/2;i++){
            temp=temp->next;
        }
        return temp;

        //method 2
        /*int length = len(head);
        ListNode * temp = head;
        int pos = length/2 + 1;
        int current_pos = 1;
        while(current_pos!=pos){
            temp = temp->next;
            current_pos++;
        }
        return temp;


         
    }
};*/
#include <iostream>
using namespace std;
//tortoise Algorithm
class Node{
    public:
    int data;
    Node*next;
    Node(){
        this->next=NULL;
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
//for even if we want to find left side head
/*Node * find_mid(Node *head){
    Node *fast = head;
    Node *slow = head;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}*/
//right side middle in case of even linked list

Node * find_mid(Node *head){
    Node *fast = head;
    Node *slow = head;
    while(fast->next!=NULL){
        fast=fast->next;
        if(fast->next!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}


int main(){
    Node * head = NULL;
    Node * tail = head;
    insert_tail(head,tail,1);
    insert_tail(head,tail,2);
    insert_tail(head,tail,3);
    insert_tail(head,tail,4);
    insert_tail(head,tail,5);
    insert_tail(head,tail,6);

    print(head);
    cout<<endl;
    cout<<"After finding the middle element "<<endl;
    Node * middle = find_mid(head);
    print(middle);
    


}
