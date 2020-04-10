class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        std::stack<ListNode*> stk;
        
        ListNode* nh = nullptr, *nt = nullptr;
        
        auto curr = head;
        while(curr) {
            auto remaining = k;
            while(remaining > 0 && curr) {
                stk.push(curr);
                curr = curr->next;
                remaining--;
            }
            if(stk.size() == k) {
                // Reverse order
                while(!stk.empty()) {
                    auto topNode = stk.top(); stk.pop();
                    if(!nh) {
                        nh = nt = topNode;
                    } else {
                       nt->next = topNode;
                        nt = topNode;
                    }
                    nt->next = nullptr;                    
                }

            } else {
                // In order
                ListNode* tempH = nullptr, *tempT = nullptr;
                while(!stk.empty()) {
                    auto topNode = stk.top(); stk.pop();
                    if(!tempH) {
                        tempH = tempT = topNode;
                        tempT->next = nullptr;
                    } else {
                        topNode->next = tempH;
                        tempH = topNode;
                    }
                    nt->next = tempH;
                }
            }
        }
        return nh;
    }
};
