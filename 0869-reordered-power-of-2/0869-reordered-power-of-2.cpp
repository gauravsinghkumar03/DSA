class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> input=countDig(n);
        for(int i=0;i<31;i++){
            int pow=1<<i;
            vector<int>parray=countDig(pow);

            if(matches(input,parray)){
                return true;
            }
        }
        return false;
    }
    bool matches(vector<int>&a,vector<int>&b){
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]){
                return false;
            }
        }
        return true;
    }
    vector<int> countDig(int n){
        vector<int>count(10,0);

        while(n>0){
            count[n%10]++;
            n/=10;
        }
        return count;
    }
};