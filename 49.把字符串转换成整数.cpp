class Solution {
public:
    int StrToInt(string str) {
        int n = str.size();
        if(n == 0)	return 0;
        int res = 0;
        int i = 0;
        int flag = 1;
        if(str[0] == '+' || str[0] == '-'){
            ++i;
            if(str[0] == '-')	flag = -1;
        }
        for(; i < n; ++i){
            if(str[i] < '0' || str[i] > '9')	return 0;
            else{
                res = res * 10 + (str[i] - '0');
            }
        }
        return flag * res;
    }
};
