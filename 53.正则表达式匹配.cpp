class Solution {
public:
    bool match(char* str, char* pattern){
    	if(str == NULL || pattern == NULL)	return false;
        return matchCore(str, pattern);
    }
    
    bool matchCore(char* str, char* pattern){
        if(*str == '\0' && *pattern == '\0')	return true;
        if(*str != '\0' && *pattern == '\0')	return false;
        //如果第二个字符是'*'
        if(*(pattern + 1) == '*'){
            //第一个字符可以匹配
            if(*pattern == *str || (*pattern == '.' && *str != '\0')){
                return
                    //实际上只有一个字符匹配
                    matchCore(str + 1, pattern + 2) ||
                    //实际上多个字符匹配
                    matchCore(str + 1, pattern) ||
                    //实际上没有字符匹配
                    matchCore(str, pattern + 2);
            }
            //第一个字符不匹配，直接跳过
            else	return matchCore(str, pattern + 2);
        }
        //第二个字符不是'*'
        //匹配，继续
        if(*str == *pattern || (*pattern == '.' && *str != '\0')){
            return matchCore(str + 1, pattern + 1);
        }
        //不匹配，返回false
        return false;
    }
};
