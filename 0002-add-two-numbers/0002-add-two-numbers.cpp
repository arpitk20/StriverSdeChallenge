// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* temp1 = l1;
//         ListNode* temp2 = l2;
//         ListNode* temp;
//         ListNode* tempHead = new ListNode();
//         temp = tempHead;
//         int carry = 0;
//         while(temp1 && temp2)
//         {
            
//             temp->val = (temp1->val + temp2->val + carry)%10;
//             carry = (temp1->val + temp2->val + carry)/10;
//             temp1 = temp1->next;
//             temp2 = temp2->next;
//             temp->next = new ListNode();
//             temp = temp->next;
//         }
//         while(temp1)
//         {
            
//             temp->val = (temp1->val + carry)%10;
//             carry = (temp1->val + carry)/10;
//             temp1 = temp1->next;
//             temp->next = new ListNode();
//             temp = temp->next;
//         }
//         while(temp2)
//         {
            
//             temp->val = (temp2->val + carry)%10;
//             carry = (temp2->val + carry)/10;
//             temp2 = temp2->next;
//             temp->next = new ListNode();
//             temp = temp->next;
//         }
//         if(carry)
//         {
//             temp->next = new ListNode();
//             temp->next->val = carry;
//         }
//         return tempHead;
        
        
//     }
// };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* temp;
        ListNode* tempHead = new ListNode();
        temp = tempHead;
        int carry = 0;
        while(temp1 || temp2)
        {
            int sum = carry;
            if(temp1) {
                sum += temp1->val;
                temp1 = temp1->next;
            }
            if(temp2) {
                sum += temp2->val;
                temp2 = temp2->next;
            }
            temp->next = new ListNode(sum % 10);
            carry = sum / 10;
            temp = temp->next;
        }
        if(carry)
        {
            temp->next = new ListNode(carry);
        }
        return tempHead->next;
    }
};
