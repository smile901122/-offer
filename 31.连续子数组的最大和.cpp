class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
    	int n = array.size();
        if(n == 0)	return 0;
        int sum = array[0];
        int max = INT_MIN;
        for(int i = 1; i < n; ++i){
            if(sum <= 0)	sum = array[i];
            else	sum += array[i];
            if(max < sum)	max = sum;
        }
        return max;
    }
};
