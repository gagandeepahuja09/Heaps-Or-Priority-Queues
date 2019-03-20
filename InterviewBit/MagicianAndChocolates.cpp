#define MOD 1000000007

int Solution::nchoc(int A, vector<int> &B) {
    priority_queue<int> pq;
    for(int i=0; i<B.size(); i++) {
        pq.push(B[i]);
    }
    int sum = 0;
    while(A--) {
        int t = pq.top();
        pq.pop();
        pq.push(t/2);
        sum = (sum%MOD + t%MOD)%MOD;
    }
    return sum%MOD;
}

