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
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr or head->next == nullptr){
            return nullptr;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                break;
            }
        }
        
        if(!fast or !fast->next){
            return nullptr;
        }
        
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};