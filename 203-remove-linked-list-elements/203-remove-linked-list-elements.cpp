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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        
        ListNode* prev = dummy;
        ListNode* temp = head;
        
        while(temp != NULL){
            if(temp->val == val){
                prev->next = temp->next;
                temp = prev->next;
            }else{
                temp = temp->next;
                prev = prev->next;
            }
        }
        return dummy->next;
    }
};