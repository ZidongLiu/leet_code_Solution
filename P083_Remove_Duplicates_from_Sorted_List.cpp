//
// Created by Zidong Liu on 8/28/18.
//

#include <vector>
#include <iostream>
using namespace std;
//////// beat 98%

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x),next(NULL){}
};


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL){
            return(head);
        }
        ListNode *ret = new ListNode(0);
        ListNode *ret_end = head, *cur=head;
        ret->next = ret_end;
        while(cur!=NULL){
            if(cur->val!=ret_end->val){
                ret_end->next = cur;
                ret_end = ret_end->next;
            }
            cur = cur->next;
        }
        ret_end->next = NULL;
        return(ret->next);
    }
};