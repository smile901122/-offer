class Solution {
public:
    //O(n)递归解法
    /*
    int LastRemaining_Solution(unsigned int n, unsigned int m){
        if(n < 1 || m < 1)	return -1;
        if(n == 1)	return 0;
        return (LastRemaining_Solution(n - 1, m) + m) % n;
    }
    */
    //传统模拟解法 O(mn), O(n)
    int LastRemaining_Solution(unsigned int n, unsigned int m){
        if(n < 1 || m < 1)	return -1;
        
        list<int> numbers;
        for(int i = 0; i < n; ++i){
            numbers.push_back(i);
        }
        
        list<int>::iterator current = numbers.begin();
        while(--n){//控制循环，直到剩下一个结点
            //得到将要删除的结点current
            for(int i = 0; i < m - 1; ++i){
                ++current;
                //若已经到链尾，则置下一个结点为链头
            	if(current == numbers.end())	
                	current = numbers.begin();
            }
            //得到下一个起始结点（删除结点之后的结点）
            list<int>::iterator next = current;
            ++next;
            if(next == numbers.end())
                next = numbers.begin();
            //删除待删除结点
            numbers.erase(current);
            current = next;
        }
        return *current;
    }
};
