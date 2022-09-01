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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !head->next or k <= 0) return head; 
        
        ListNode* temp = head;
        int len = 1;
        while(temp->next){
            temp = temp->next;
            len++;
        }
        
        temp->next = head;
        
        int rotations = k % len;
        int skips = len - rotations;
        
        ListNode* newEnd = head;
        for(int i = 0; i < skips-1; i++){
            newEnd = newEnd->next;
        }
        head = newEnd->next;
        newEnd->next = NULL;
        return head;
    }
};