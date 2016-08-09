/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            
        	vector<vector<int> > res;
            if(pRoot == NULL)	return res;
            deque<TreeNode*> q;
            q.push_back(pRoot);
            while(!q.empty()){
                int n = q.size();
                vector<int> level;
                while(n--){
                    TreeNode *p = q.front();
                    q.pop_front();
                    
                    level.push_back(p->val);
                    if(p->left)		q.push_back(p->left);
                    if(p->right)	q.push_back(p->right);
                }
                res.push_back(level);
            }
            return res;
        }
    
};
