class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.length();

        char goodInteger = ' ';

        for(int i=2; i<n; i++){
            if(num[i]==num[i-1] && num[i]==num[i-2]){
                goodInteger = max(goodInteger, num[i]);
            }
        }

        if(goodInteger ==' '){
            return "";
        }

        return string(3,goodInteger);
    }
};