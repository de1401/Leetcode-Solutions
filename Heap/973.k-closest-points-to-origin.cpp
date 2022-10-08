class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> pq;

        for (auto i : points) {
            int dist = pow(i[0], 2) + pow(i[1], 2);
            pq.push({dist, i[0], i[1]});
            if (pq.size() > k) pq.pop();
        }

        vector<vector<int>> ans;

        while(k--) {
            ans.push_back({pq.top()[1], pq.top()[2]});
            pq.pop();
        }
        return ans;
    }
};