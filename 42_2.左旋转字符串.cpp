class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(str.empty() || n <= 0 || n >= str.size())	return str;
        int length = str.size() - n;
        reverse(str.begin(), str.end());
        string::iterator index = str.begin();
        while(length--)	++index;
        reverse(str.begin(), index);
        reverse(index, str.end());
        return str;
    }
};
