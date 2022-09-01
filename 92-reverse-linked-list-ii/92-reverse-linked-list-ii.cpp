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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL){
            return NULL;
        }
        
        if(left == right){
            return head;
        }
        
        ListNode* curr = head, *prev = NULL;
        ListNode* nn;
        
        for(int i = 0; curr and i < left-1; i++){
            prev = curr;
            curr = curr->next;
        }
        
        ListNode* last = prev, *newEnd = curr;
        for(int i = 0; curr and i < right - left + 1; i++){
            nn = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nn;
        }
        
        if(last){
            last->next = prev;
        }else{
            head = prev;
        }
        newEnd->next = curr;
        return head;
    }
};