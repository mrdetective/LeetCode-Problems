/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int c = 0){
        if(!l1 && !l2 && !c){
            return NULL;
        } 
        ListNode *l3 = new ListNode();
        if(l1 && l2){
            l3->val = (l1->val + l2->val + c) % 10;
            l3->next = addTwoNumbers(l1->next, l2->next, (l1->val + l2->val + c) / 10);
            return l3;
        }
        else if(l1){
            l3->val = (l1->val + c) % 10;
            l3->next = addTwoNumbers(l1->next, l2, (l1->val + c) / 10);
            return l3;
        }   
        else if(l2){
            l3->val = (l2->val + c) % 10;
            l3->next = addTwoNumbers(l1, l2->next, (l2->val + c) / 10);
            return l3;
        }
        else if(c){
           l3->val = c;
           l3->next = NULL;
           return l3;
        }
        return NULL;            
    }
};