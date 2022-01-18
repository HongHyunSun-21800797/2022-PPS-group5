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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<pair<int, ListNode*>> v;
        
        
        ListNode* curr = list1;
        
        if(list1 != nullptr) {
        while(curr != nullptr) {
            v.push_back(make_pair(curr->val, curr));
            curr = curr->next;
        }
        }
        
        if(list2 != nullptr) {
        curr = list2;
        while(curr != nullptr) {
            v.push_back(make_pair(curr->val, curr));
            curr = curr->next;
        }
        }
        
        if(v.empty()) return nullptr;
        
        sort(v.begin(), v.end());
        
        for(int i = 0; i < v.size() - 1; i++) {
            v[i].second->next = v[i+1].second;
        }
        v[v.size()-1].second->next = nullptr;
        
        return v[0].second;
    }
};