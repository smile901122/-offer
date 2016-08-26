class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        int n = numbers.size();
        if(n == 0)	return false;
        
        sort(numbers.begin(), numbers.end());
        int zero = 0;
        int gap = 0;
        for(int i = 0; i < n; ++i){
            if(numbers[i] == 0)	++zero;
            if(i > 0 && numbers[i - 1] != 0){
                if(numbers[i] == numbers[i - 1])	return false;
                if(numbers[i] > numbers[i - 1] + 1){
                    gap += numbers[i] - numbers[i - 1] - 1;
                }
            }
        }
        if(zero >= gap)	return true;
        return false;
    }
};
