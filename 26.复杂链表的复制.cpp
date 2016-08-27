/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead){
        if(pHead == NULL)	return NULL;
        cloneNodes(pHead);
        connectRandom(pHead);
        return connectNext(pHead);
    }
private:
    void cloneNodes(RandomListNode* head){
        RandomListNode *p = head;
        while(p != NULL){
            RandomListNode *node = new RandomListNode(p->label);
            node->next = p->next;
            p->next = node;
            //循环
            p = node->next;
        }
    }
    
    void connectRandom(RandomListNode* head){
        RandomListNode *p = head;
        while(p != NULL){
            if(p->random != NULL)
            	p->next->random = p->random->next;
            p = p->next->next;
        }
    }
    
    RandomListNode* connectNext(RandomListNode* head){
        RandomListNode *clonedHead = head->next;
        RandomListNode *p = head;
        RandomListNode *q = clonedHead;
        //p先走一步
        if(p != NULL){
            p->next = q->next;
            p = p->next;
        }
        
        while(p != NULL){
            q->next = p->next;
            q = q->next;
            p->next = q->next;
            p = p->next;
        }
        return clonedHead;
    }
};
