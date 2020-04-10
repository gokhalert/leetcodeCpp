/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int getPartSize(int remaining, int parts) {
        if(remaining == 0) return 0;
        if(remaining % parts == 0) return remaining / parts;
        else return remaining / parts + 1;
    }
    class ListIterator {
        ListNode* it_;
        public:
        ListIterator(ListNode* head) : it_(head) {}
        ListNode* next(int k) {
            if(!it_) return it_;
            ListNode* ans = it_;
            ListNode* prev = it_;
            for(int i = 0; i < k; i++) {
                assert(it_);
                prev = it_;
                it_ = it_->next;
            }
            prev->next = nullptr;
            return ans;
        }
        bool hasNext() { return it_ != nullptr; }
    };
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> res;
        
        ListIterator it(root);
        auto remaining = 0;
        for(auto curr = root; curr; curr = curr->next) remaining++;
        
        while(it.hasNext() || k > 0) {
            auto partSize = getPartSize(remaining, k);
            remaining -= partSize;
            k--;
            res.push_back(it.next(partSize));
        }
        return res;
    }
};
