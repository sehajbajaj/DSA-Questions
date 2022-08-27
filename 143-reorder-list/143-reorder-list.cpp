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
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* newNode;
        
        while(curr){
            newNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = newNode;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        if(head == nullptr or head->next == nullptr){
            return;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast != nullptr and fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* mid = slow->next;
        slow->next = nullptr;
        
        ListNode* secondHead = reverse(mid);
        ListNode* firstHead = head;
        
        while(firstHead != nullptr and secondHead != nullptr){
            ListNode* temp = firstHead->next;
            firstHead->next = secondHead;
            firstHead = temp;
            
            temp = secondHead->next;
            secondHead->next = firstHead;
            secondHead = temp;
        }
        
    }
};