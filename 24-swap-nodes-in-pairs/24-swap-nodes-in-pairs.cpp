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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr or head->next == nullptr){
            return head;
        }
        
        ListNode* curr = head, *prev = nullptr, *nn;
        int cnt = 0;
        
        while(curr and cnt < 2){
            nn = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nn;
            cnt++;
        }
        
        if(nn){
            head->next = swapPairs(nn);
        }
        return prev;
    }
};