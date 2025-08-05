class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int n =fruits.size();
        int i=0,j=0,cnt=0;
        while(j<n){
            mp[fruits[j]]++;
            if(mp.size()<=2){
                cnt=max(cnt,j-i+1);
            }else{
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0){
                    mp.erase(fruits[i]);
                }
                i++;
            }
            j++;
        }
        return cnt;
    }
};