/*
Scooby likes the kth element

Scooby wants to help you as he knows that you are preparing for interviews. So Scooby gives you a very simple question.
You are given N numbers.

You need to find the kth largest element in the subarray [1 to i] where i varies 
from 1 to N. In other words you need to find the kth largest element in the sub-arrays
[1:1], [1:2], [1:3], ...., [1:n] . 

*/
vector<int> Solution::solve(int A, vector<int> &B) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int popped = A;
    vector<int> ret;
    for(int i = 0; i < A - 1; i++) {
        pq.push(B[i]);
        ret.push_back(-1);
    }
    for(int i = A - 1; i < B.size(); i++) {
        if(i == A - 1)
            pq.push(B[i]);
        else if(pq.top() < B[i]) {
            pq.pop();
            pq.push(B[i]);
        }
        ret.push_back(pq.top());
    }
    return ret;
}

