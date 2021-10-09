class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        int **ans = new int*[n]; 
        for(int i = 0; i < n; i++){ 
            ans[i] = new int[n]; 
        }
        for(int i = 0; i < n; i++){
            ans[i][i] = 1;
        }
        int curr_len;
        for(curr_len = 2; curr_len <= n; curr_len++){
            for(int i = 0; i < n - curr_len + 1; i++){
                int j = i + curr_len - 1;
                if(s[i] == s[j] and curr_len == 2){
                    ans[i][j] = 2;
                }
                else if(s[i] == s[j]){
                    ans[i][j] = 2 + ans[i + 1][j - 1];
                }
                else{
                    ans[i][j] = max(ans[i][j - 1], ans[i + 1][j]);
                }
            }
        }
        return ans[0][n - 1];
    }
};

