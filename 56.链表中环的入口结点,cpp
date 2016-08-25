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
    ListNode* EntryNodeOfLoop(ListNode* pHead){
        ListNode* meet = findLoop(pHead);
        if(meet == NULL)	return NULL;
        
        ListNode* p = meet;
        int count = 1;
        while(p->next != meet){
            p = p->next;
            ++count;
        }
        
        p = pHead;
        while(count--){
            p = p->next;
        }
        ListNode* q = pHead;
        while(p != q){
            p = p->next;
            q = q->next;
        }
        return q;
    }
private:
    ListNode* findLoop(ListNode* head){ 
        if(head == NULL)	return NULL;
        
        ListNode* p1 = head;
        ListNode* p2 = p1->next;
        while(p2 != NULL ){
            if(p1 == p2)	return p2;
            p1 = p1->next;
            p2 = p2->next;
            if(p2 != NULL)	p2 = p2->next;
        }
        return NULL;
    }
};
