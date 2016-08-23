//length为牛客系统规定字符串输出的最大长度，固定为一个常数
class Solution {
public:
	void replaceSpace(char *str, int length) {
		int spaceNum = 0;
		int len = 0;
		for (int i = 0; str[i] != '\0'; ++i)
		{
			++len;
			if (str[i] == ' ')
				++spaceNum;
		}
	
		int newIndex = len + 2 * spaceNum;
    	if(newIndex >= length)	return;
		int index = len;
		while (newIndex >= 0 && newIndex > index)
		{
			if (str[index] == ' ')
			{
				str[newIndex--] = '0';
				str[newIndex--] = '2';
				str[newIndex--] = '%';
			}
			else{
				str[newIndex--] = str[index];
			}
			--index;
		}
	}
};
