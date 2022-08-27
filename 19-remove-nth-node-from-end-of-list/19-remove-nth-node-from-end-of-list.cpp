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
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr or n <= 0){
            return head;
        }
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        //Move fast forward n-1 times
        for(int i = 0; i < n; i++){
            fast = fast->next;
        }
        
        if(fast == nullptr) return slow->next;
        
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        return head;
    }
};