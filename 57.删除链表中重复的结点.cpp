/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead){
		ListNode *newHead = new ListNode(0);
        ListNode *pre = newHead;
        ListNode *p = pHead;
        while(p != NULL){
            while(p !=  NULL && p->next != NULL && p->val == p->next->val){
                int value = p->val;
                while(p != NULL && p->val == value){
                    ListNode *toBeDel = p;
                    p = p->next;
                    delete toBeDel;
                    toBeDel = NULL;
                }
            }
            pre->next = p;
            if(p != NULL){
                p = p->next;
                pre = pre->next;
            }
            
        }
        p = newHead->next;
        delete newHead;
        newHead = NULL;
        return p;
    }
};
