/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct cmp {
    bool operator()(ListNode* A, ListNode* B) {
        return (A -> val > B -> val);
    } 
};
 
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
    for(int i=0; i<A.size(); i++) {
        pq.push(A[i]);
    }
    
    ListNode* res = new ListNode(0);
    ListNode* head = res;
    while(!pq.empty()) {
        ListNode* top = pq.top();
        pq.pop();
        res -> next = top;
        res = res -> next;
        
        if(top -> next)
            pq.push(top -> next);
    }
    return head -> next;
}

