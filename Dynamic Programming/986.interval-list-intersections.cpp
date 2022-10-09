class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n = firstList.size(), m = secondList.size(), i = 0, j = 0;
        vector<vector<int>> ans;
        while(i < n && j < m) {
            int start = max(firstList[i][0], secondList[j][0]), end = min(firstList[i][1], secondList[j][1]);

            if (start <= end) ans.push_back({start, end}); //skip where start > end
            if (end == firstList[i][1]) i++;
            else j++;
        }

        return ans;
    }
};