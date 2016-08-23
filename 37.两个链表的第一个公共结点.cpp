/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode *pHead1, ListNode *pHead2) {
        if(pHead1 == NULL || pHead2 == NULL)	return NULL;
        int n1 = 0;
        int n2 = 0;
        ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;
        while(p1 != NULL){
            ++n1;
            p1 = p1->next;
        }
        while(p2 != NULL){
            ++n2;
            p2 = p2->next;
        }
        if(n1 > n2){
            int n = n1 - n2;
            while(n--){
                pHead1 = pHead1->next;
            }
            while(pHead1 != NULL){
                if(pHead1 == pHead2)	return pHead1;
                else{
                    pHead1 = pHead1->next;
                    pHead2 = pHead2->next;
                }
            }
            return pHead1;
        }
        else{
            int n = n2 - n1;
            while(n--){
                pHead2 = pHead2->next;
            }
            while(pHead1 != NULL){
                if(pHead1 == pHead2)	return pHead1;
                else{
                    pHead1 = pHead1->next;
                    pHead2 = pHead2->next;
                }
            }
            return pHead1;
        } 
    }
};
