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
        ListNode* fast = head->next;
        
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* merge(ListNode* firstHead, ListNode* secondHead){
        if(!firstHead){
            return secondHead;
        }
        
        if(!secondHead){
            return firstHead;
        }
        
        ListNode* tempHead;
        if(firstHead->val <= secondHead->val){
            tempHead = firstHead;
            tempHead->next = merge(firstHead->next, secondHead);
        }else{
            tempHead = secondHead;
            tempHead->next = merge(firstHead, secondHead->next);
        }
        return tempHead;
    }
    
    ListNode* sortList(ListNode* head) {
        if(!head or !head->next){
            return head;
        }
        
        ListNode* mid = middleOfLL(head);
        ListNode* firstHead = head;
        ListNode* secondHead = mid->next;
        mid->next = NULL;
        
        firstHead = sortList(firstHead);
        secondHead = sortList(secondHead);
        
        return merge(firstHead, secondHead);
    }
    
    
};