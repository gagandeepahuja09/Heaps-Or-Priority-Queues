/*
Minimum Cost to Hire K Workers

Given two array of integers of A and B describing the quality and minimum wage expectations of N workers.

Now, you want to hire exactly C workers to form a paid group. When hiring a group of C workers, we must pay them according to the following rules:

    Every worker in the paid group should be paid in the ratio of their quality compared to other workers in the paid group.
    Every worker in the paid group must be paid at least their minimum wage expectation.

let D be the least amount of money needed to form a paid group satisfying the above conditions. D can be any real value.

Return the ceil(D).

ceil(x): Returns the smallest integer that is greater than or equal to x (i.e: rounds up the nearest integer).


Input Format

The first argument given is the integer array A.
The second argument given is the integer array B.
The third argument given is the integer C.

Output Format

Return the ceil(D).

Constraints

1 <= N <= 100000
1 <= A[i], B[i] <= 10000 
1 <= C <= N

For Example

Input 1:
    A = [10, 20, 5]
    B = [70, 50, 30]
    C = 2
Output 1:
    105
    Explanation 1:
        Pay 70 to the first worker
        Pay 35 to the third worker
        Total = 70 + 35 = 105

Input 2:
    A = [3, 1, 10, 10, 1]
    B = [4, 8, 2, 2, 7]
    C = 3
Output 2:
    31
    Explanation 2:
        Pay 4 to the first worker
        Pay 13.33333 to the third worker
        Pay 13.33333 to the fourth worker
        Total = 4 + 13.33333 + 13.333333 = 30.66667
        ceil(30.66667) = 31
*/

int Solution::solve(vector<int> &q, vector<int> &w, int K) {
    vector<vector<double>> workers;
    for(int i = 0; i < q.size(); i++) {
        workers.push_back({ (double(w[i]) /  q[i]), (double)(q[i]) });
    }
    sort(workers.begin(), workers.end());
    double res = INT_MAX, sum = 0;
    priority_queue<int> pq;
    for(auto worker : workers) {
        sum += worker[1];
        pq.push(worker[1]);
        if(pq.size() > K) {
            sum -= pq.top();
            pq.pop();
        }
        if(pq.size() == K) {
            res = min(res, sum * worker[0]);
        }
    }
    return ceil(res);
}

