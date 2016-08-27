class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > res;
        if(sum < 3)	return res;
        int small = 1;
        int big = 2;
        int middle = 1 + (sum - 1) / 2;
        int currSum = small + big;
        while(small < middle){
            if(currSum == sum){
                vector<int> seq;
                int i = small;
                while(i <= big){
            		seq.push_back(i);
            		++i;
        		}
                res.push_back(seq);
            }
            if(currSum >= sum){//此处应该是>=，要保证循环的进行，否则会陷入死循环。
                currSum -= small;
                ++small;
            }
            else{
                ++big;
                currSum += big; 
            }
        }
        return res;
    }
};
