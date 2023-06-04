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
        
        ListNode* temp = head;
        int count = 0;
        while(temp)
        {
            temp = temp->next;
            count++;
        }
        
        temp = head;
        int count2 = count-n-1;
        if(count-n==0)
            return head->next;
        while(count2)
        {
            temp = temp->next;
            count2--;
        }
        temp->next = temp->next->next;
        return head;
    }
};