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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *node = head, *startprev = NULL, *prev = NULL;
        int pos = 1;
        while(node != NULL){ 
            if(pos >= left && pos <= right){
                ListNode *temp = node->next;
                if(pos > left){
                    node->next = prev;
                }
                if(pos == right && startprev){
                    if(startprev->next){
                        startprev->next->next = temp;
                    }
                    startprev->next = node; 
                    break;
                }
                else if(pos == right && !startprev){
                    head->next = temp;
                    head = node;
                    break;
                }
                prev = node;
                node = temp;
            }
            else{
                if(pos < left){
                    startprev = node;
                }
                node = node->next;
            }
            pos++;
        }
        return head;
    }
};