class Solution {
public:
    int maxDepth(string s) {
        int n=s.length();
        int cur=0;
        int maxi=0;

        for(int i=0; i<n; i++){
            char ch = s[i];

            if(ch == '('){
                cur++;
                maxi = max(maxi,cur);
            }
            else if(ch == ')'){
                cur--;
            }
        }

        return maxi;
    }
};