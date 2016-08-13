/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(struct ListNode* head) {
        vector<int> res;
        print(head, res);
        return res;
    }
    //递归打印
    void print(ListNode* head, vector<int> &res){
        if(head == NULL)	return;
        print(head->next, res);
        res.push_back(head->val);
    }
};
