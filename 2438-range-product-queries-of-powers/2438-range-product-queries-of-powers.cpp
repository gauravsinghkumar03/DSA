class Solution {
public:
int M=1e9+7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> pow;
        vector<int> res;

        for(int i=0;i<32;i++){
            if((n&(1<<i))!=0){
                pow.push_back(1<<i);
            }
        }

        for(auto& que : queries){
            int st=que[0]; int end=que[1];
            long prod=1;
            for(int i=st;i<=end;i++){
                prod=(prod*pow[i])%M;
            }
            res.push_back(prod);
        }
        return res;

    }
};