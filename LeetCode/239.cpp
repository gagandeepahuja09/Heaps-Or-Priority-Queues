// 1 3 -1 --> 3
// { 3, 1} { 1, 0 } { -1, 1 }
// We can keep on popping all elements which are before i - k index
// 3 -1 -3 --> 
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // First we will try O(N logN) solution
        priority_queue<vector<int>> mx;
        for(int i = 0; i < k; i++) {
            mx.push({ nums[i], i });
        }
        vector<int> ret;
        int n = nums.size();
        for(int i = k; i < n; i++) {
            ret.push_back(mx.top()[0]);
            while(!mx.empty() && mx.top()[1] <= i - k) {
                mx.pop();
            }
            mx.push({ nums[i], i });
        }
        ret.push_back(mx.top()[0]);
        return ret;
    }
};
