vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int n = A.size();
    set<pair<int, int>> indices;
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({ A[n-1] + B[n-1], { n-1, n-1 } });
    indices.insert({ n-1, n-1 });
    int k = A.size();
    vector<int> res;
    while(k--) {
        pair<int, pair<int, int>> temp = pq.top();
        pq.pop();
        res.push_back(temp.first);
        
        int i = temp.second.first;
        int j = temp.second.second;
        
        int sum = A[i-1] + B[j];
        pair<int, int> p1 = {i-1, j};
        if(indices.find(p1) == indices.end()) {
            indices.insert(p1);
            pq.push({ sum, p1 });
        }
        
        sum = A[i] + B[j-1];
        p1 = {i, j-1};
        if(indices.find(p1) == indices.end()) {
            indices.insert(p1);
            pq.push({ sum, p1 });
        }
    }
    return res;
}

