/*1.If the number of elements are n in B and n is odd then consider medain as B[n/2] ( B must be in sorted order).

2.If the number of elements are n in B and n is even then consider medain as B[n/2-1] ( B must be in sorted order).*/

vector<int> Solution::solve(vector<int> &A) {
    vector<int> ret;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int i = 0; i < A.size(); i++) {
        if(maxHeap.empty() && minHeap.empty()) {
            maxHeap.push(A[i]);
        }
        else if(!maxHeap.empty() && A[i] > maxHeap.top()) {
            minHeap.push(A[i]);
        }
        else {
            maxHeap.push(A[i]);
        }
        if(minHeap.size() > 1 + maxHeap.size()) {
            int t = minHeap.top();
            minHeap.pop();
            maxHeap.push(t);
        }
        if(maxHeap.size() > 1 + minHeap.size()) {
            int t = maxHeap.top();
            maxHeap.pop();
            minHeap.push(t);
        }
        // Even elements
        if(i % 2) {
            ret.push_back(maxHeap.top());
        }
        else {
            if(minHeap.size() > maxHeap.size())
                ret.push_back(minHeap.top());
            else
                ret.push_back(maxHeap.top());
        }
    }
    return ret;
}

