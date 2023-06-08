/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //Using Extra Space
//         map<Node*, Node*> mp;
        
//         Node* temp = head;
        
//         while(temp)
//         {
//             mp[temp] = new Node(temp->val);
//             temp = temp->next;//Mapping complete
//         }
//         temp = head;
        
//         while(temp)
//         {
//             mp[temp]->next = mp[temp->next];
//             mp[temp]->random = mp[temp->random];
//             temp = temp->next;
//         }
        
//         return mp[head];
        
        //Without Extra Spce
        if (head == NULL) {
            return NULL;
        }
         
        // Step 1: Create new nodes and insert them next to the original nodes
        Node* curr = head;
        while (curr != NULL) {
            Node* newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }
        
        // Step 2: Set the random pointers of the new nodes
        curr = head;
        while (curr != NULL) {
            if (curr->random != NULL) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        
        // Step 3: Separate the new nodes from the original nodes
        curr = head;
        Node* clonedHead = head->next;
        Node* clonedCurr = clonedHead;
        while (clonedCurr->next != NULL) {
            curr->next = curr->next->next;
            clonedCurr->next = clonedCurr->next->next;
            curr = curr->next;
            clonedCurr = clonedCurr->next;
        }
        curr->next = NULL;
        clonedCurr->next = NULL;
         
        return clonedHead;
    }
};