class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& b) {
        set<vector<int>> points;
        for(auto &v : b) {
            vector<int> start{ v[0], -v[2] };
            vector<int> end{ v[1], v[2] };
            points.insert(start); points.insert(end);
        }
        multiset<int> pq({0});
        vector<vector<int>> skylines;
        int maxHeight = 0;
        for(auto &p : points) {
            if(p[1] < 0) {
                if(-p[1] > maxHeight) {
                    maxHeight = -p[1];
                    skylines.push_back({ p[0], -p[1] });
                }
                pq.insert(-p[1]);
            }
            else {
                pq.erase(pq.find(p[1]));
                int pqMax = *pq.rbegin();
                if(pqMax < maxHeight) {
                    maxHeight = pqMax;
                    skylines.push_back({ p[0], maxHeight });
                }
            }
        }
        return skylines;
    }
};
