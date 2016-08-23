class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
		int depth = 0;
        return isBalanced(pRoot, depth);
    }
    //利用后序遍历一边遍历一遍判断每个结点是不是平衡的
private:
    bool isBalanced(TreeNode *root, int &depth){
        if(root == NULL){
            depth = 0;
            return true;
        }
        int left = 0;
        int right = 0;
        if(isBalanced(root->left, left) && isBalanced(root->right, right)){
            int diff = left - right;
            if(diff <= 1 && diff >= -1){
                depth = 1 + (left > right ? left : right);
                return true;
            }
        }
        return false;
    }
};
