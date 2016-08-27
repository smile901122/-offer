class Solution {
public:
    string ReverseSentence(string str) {
        if(str.empty())	return str;
        reverse(str.begin(), str.end());
        string::iterator start = str.begin();
        string::iterator end = str.begin();
        while(start != str.end()){
            while(*end != ' ' && end != str.end()){
                ++end;
            }
            reverse(start, end);
            if(*end == ' ')	++end;
            start = end;
        }
        return str;
        
        /*
        string res = "";
        int n = str.size();
        if(n == 0)	return res;
        stack<string> s;
        for(int i = 0; i < n; ++i){
            if(str[i] == ' '){
                s.push(res);
                s.push(" ");
                res = "";
            }
            else	res += str[i];
        }
        if(res != "")	s.push(res);
        res = "";
        n = s.size();
        while(n--){
            res += s.top();
            s.pop();
        }
        return res;
        */
    }
};
