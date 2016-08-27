class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int n = array.size();
        vector<int>	res;
        if(n <= 1)	return res;
        int small = 0;
        int big = n - 1;
        while(small < big){
            int currSum = array[small] + array[big];
            if(currSum == sum)	break;
            if(currSum > sum)	--big;
            else	++small;
        }
        if(small < big){
            res.push_back(array[small]);
        	res.push_back(array[big]);
        }
        return res;
    }
};
