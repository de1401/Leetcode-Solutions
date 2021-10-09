class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector <string> v;
        for(int i = 1; i <= n; i++){
            string ans = "";
            if(i % 3 == 0){
                ans += "Fizz";
            }
            if(i % 5 == 0){
                ans += "Buzz";
            }
            if(ans == ""){
                stringstream ss; 
                ss << i;
                ss >> ans;
            }
            v.push_back(ans);
        }
        return v;
    }
};

