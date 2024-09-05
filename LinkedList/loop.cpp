/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //1 basic approach with map
       /* unordered_map<ListNode *,bool>check;
        ListNode * temp = head;
        while(temp!=NULL){
            ListNode * NodeAddress = temp;;
            if(check[NodeAddress]==false){
                check[NodeAddress]=true;
                temp=temp->next;
            }
            else{
                return true;
            }
        }
        return false;*/
    
    //2 approach with slow and fast pointer
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast!=NULL){
            fast = fast->next;
            if(fast!=NULL){
                fast = fast->next;
                slow = slow->next;
            }
            if(fast == slow){
                return true;
                break;
            }
        }
        return false;
    }
    
};