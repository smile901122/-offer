class Solution {
public:
    bool isNumeric(char* string){
    	if(string == NULL)	return false;
        if(*string == '+' || *string == '-')	++string;
        if(*string == '\0')	return false;
        if(!scanDigits(&string))	return false;
        //若是小数
        if(*string == '.'){
           ++string;
           if(!scanDigits(&string))	return false;
        }
        //若是科学计数法表示
        if(*string == 'e' || *string == 'E'){
            if(!isExponential(&string))	return false;
        }
        //若非科学计数法表示
        return *string == '\0';
    }
    //判断是否是一个整数
    bool scanDigits(char** string){
        /*
        bool isInteger = false;
        if(**string != '\0' && **string >= '0' && **string <= '9'){
            ++(*string);
            isInteger = true;
        }
        */
        while(**string != '\0' && **string >= '0' && **string <= '9')
            ++(*string);
        //return isInteger;
        return true;
    }
    //判断是否满足科学计数法表示
    bool isExponential(char** string){
        if(**string != 'e' && **string != 'E')	return false;
        ++(*string);
        if(**string == '+' || **string == '-')	++(*string);
        if(**string == '\0')	return false;
        if(!scanDigits(string))	return false;
        return **string == '\0';
    }
};
