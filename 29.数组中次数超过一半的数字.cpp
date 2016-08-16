class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    	int n = numbers.size();
        if(n == 0)	return 0;
        int res = numbers[0];
        int count = 1;
        for(int i = 1; i <n; ++i){
            if(count == 0){	
                res = numbers[i];
                count = 1;
            }
            else if(numbers[i] == res)	++count;
            else	--count;
        }
        
        //if(count == 0)	return 0;//注意此情况的发生
        if(checkMoreThanHalf(numbers, res))	return res;
        return 0;
    }
private:
    bool checkMoreThanHalf(vector<int> numbers, int res){
        int n = numbers.size();
        bool flag = true;
        int c = 0;
        for(int i = 0; i < n; ++i){
            if(numbers[i] == res) ++c;
        }
        if(c * 2 <= n)	flag = false;
        return flag;
    }
};
