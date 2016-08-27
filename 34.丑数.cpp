class Solution {
public:
    int GetUglyNumber_Solution(int index) {
    	if(index <= 0)	return 0;
        
        vector<int> ugly;
        ugly.push_back(1);
        int minU = 1;
        int count = 1;
        int u2 = 0;
        int u3 = 0;
        int u5 = 0;
        
        while(count < index){
            minU = min(ugly[u2] * 2, min(ugly[u3] * 3, ugly[u5] * 5));
            ugly.push_back(minU);
            ++count;
            
            while(ugly[u2] * 2 <= minU)	++u2;
            while(ugly[u3] * 3 <= minU)	++u3;
            while(ugly[u5] * 5 <= minU)	++u5;
        }
        return minU;
    }
};
