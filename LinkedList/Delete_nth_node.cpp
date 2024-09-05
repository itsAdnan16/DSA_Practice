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
class Solution {
public:
    void reverse(ListNode * &head){
        ListNode * temp = head;
        ListNode * prev = NULL;
        ListNode * current = head;
        while(temp!=NULL){
            temp = temp->next;
            current ->next = prev;
            prev = current;
            current = temp;
        }
        head = prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return NULL;
        }
        if(n==1){
            if(head->next == NULL){
                delete head;
                return NULL;
            }
            ListNode * temp = head;
            while(temp->next->next != NULL){
                temp=temp->next;
            }
            ListNode * Node_to_be_deleted = temp->next;
            temp->next = NULL;
            delete Node_to_be_deleted;
            return head;
        }
        reverse(head);
        ListNode * it = head;
        for(int i=1;i<n-1;i++){
            if(it == NULL){
                reverse(head);
                return head;
            }
            it = it->next;
        }
        if(it->next == NULL || it==NULL){
            reverse(head);
            return head;
        }
        ListNode * Node_to_be_deleted = it->next;
        ListNode * NextNode = Node_to_be_deleted->next;
        delete Node_to_be_deleted;
        it->next = NextNode;
        reverse(head);
        return head;    
    }
};