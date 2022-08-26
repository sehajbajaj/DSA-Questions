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
    
    ListNode* middleOfLL(ListNode* head){
        if(!head or !head->next){
            return head;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* reverseLL(ListNode* head){
        if(!head or !head->next){
            return head;
        }
        
        ListNode* prev = NULL, *curr = head, *next_ptr;
        while(curr){
            next_ptr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_ptr;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* mid = middleOfLL(head);
        ListNode* secondHead = reverseLL(mid);
        
        while(head and secondHead){
            if(head->val != secondHead->val){
                break;
            }
            head = head->next;
            secondHead = secondHead->next;
        }
        
        if(!head or !secondHead){
            return true;
        }
        return false;
    }
};