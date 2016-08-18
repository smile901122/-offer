bool comp(string s1, string s2){
	return s1 + s2 < s2 + s1;
}
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        int n = numbers.size();
        vector<string> s(n);
        for(int i = 0; i < n; ++i){
            s[i] = to_string(numbers[i]);
        }
        sort(s.begin(), s.end(), comp);
        string res = "";
        for(int i = 0; i < n; ++i){
            res += s[i];
        }
        return res;
    }
};
