/*
输入一个整数数组，判断该数组是不是某个二叉搜索树的后序遍历的结果。
*/
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
		int n = sequence.size();
        if(n == 0)	return false;
        return isBST(sequence, 0, n - 1);
    }
private:
    bool isBST(vector<int> v, int start, int end){
        if(v.size() == 0 || start > end)	return false;	
        int root = v[end];
        int l = start;
        while(l < end && v[l] < root){
            ++l;
        }
        int r = l;
        while(r < end && v[r] > root){
            ++r;
        }
        if(r != end)	return false;
        bool left = true;
        bool right = true;
        if(l - start > 0) left = isBST(v, start, l - 1);
        if(end - l > 0) right = isBST(v, l, end - 1);
        return left && right;
    }
};
