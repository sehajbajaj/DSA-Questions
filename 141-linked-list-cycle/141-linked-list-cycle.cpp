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
        //base case
        if(head == nullptr or head->next == nullptr){
            return false;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != nullptr and fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
            
            if(slow == fast){       //Linked list has a cycle in it.
                return true;
            }
        }
        return false;
    }
};