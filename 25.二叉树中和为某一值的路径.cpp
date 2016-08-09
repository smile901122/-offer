/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
	vector<vector<int> > res;
        if(root == NULL)	return res;
        vector<int> path;
        int sum = 0;
        find(root, res, path, sum, expectNumber);
        return res;
    }
private:
    void find(TreeNode *root, vector<vector<int> > &res, vector<int> &path, int sum, const int expectNumber){
        path.push_back(root->val);
        sum += root->val;
        
        bool isLeaf = (root->left == NULL) && (root->right == NULL);
        if(isLeaf && sum == expectNumber)	res.push_back(path);
        
        if(root->left)	find(root->left, res, path, sum, expectNumber);
        if(root->right)	find(root->right, res, path, sum, expectNumber);
        
        path.pop_back();
    }
};
