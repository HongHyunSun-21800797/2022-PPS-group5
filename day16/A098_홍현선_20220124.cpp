/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* currA = headA;
        ListNode* currB = headB;
        
        vector<ListNode*> v;
        
        while(currA != nullptr) {
            v.push_back(currA);
            currA = currA->next;
        }
        
        while(currB != nullptr) {
            auto it = find(v.begin(), v.end(), currB);
            if(it != v.end()) return currB;
  
            currB = currB->next;
        }
        
        return nullptr;
    }
};