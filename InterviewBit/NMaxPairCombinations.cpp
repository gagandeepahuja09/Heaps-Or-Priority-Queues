vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    int n = A.size();
    priority_queue<pair<int, pair<int, int>>> pq;
    set<pair<int, int>> indices;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    vector<int> ret;
    pq.push({ A[n - 1] + B[n - 1], { n - 1, n - 1 }});
    indices.insert({ n - 1, n - 1 });
    while(n--) {
        auto t = pq.top();
        pq.pop();
        ret.push_back(t.first);
        int x = t.second.first - 1, y = t.second.second;
        if(indices.find({ x, y }) == indices.end()) {
            indices.insert({ x, y });
            pq.push({ A[x] + B[y], { x, y } });
        }
        x = t.second.first, y = t.second.second - 1;
        if(indices.find({ x, y }) == indices.end()) {
            indices.insert({ x, y });
            pq.push({ A[x] + B[y], { x, y } });
        }
    }
    return ret;
}

