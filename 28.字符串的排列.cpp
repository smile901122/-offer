class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        if(str.size() == 0)	return res;
        permutation(str, res, 0);
        //按字典序顺序，则应该排序
        sort(res.begin(), res.end());
        return res;
    }
private:
    void permutation(string str, vector<string> &res, int begin){
        if(begin == str.size() - 1)	res.push_back(str);
        else{
            int i;
            for(i = begin; i < str.size(); ++i){
                //若果字符重复则跳过，该情况两种排列相同
                if(i != begin && str[i] == str[begin])	continue;
                
                char temp = str[i];
                str[i] = str[begin];
                str[begin] = temp;
                
                permutation(str, res, begin + 1);
            	//若不使用引用，则可以不见换回来，不影响结果
            	//temp = str[i];
            	//str[i] = str[begin];
            	//str[begin] = temp;
            } 
        }
    }
};
