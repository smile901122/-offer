class Solution
{
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
        in.push_back(ch);
        count[ch]++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
    	for(char ch : in){
            if(count[ch] == 1){
                return ch;
            }
        }
        return '#';
    }
private:
    vector<char> in;
    char count[256] = {0};
};
