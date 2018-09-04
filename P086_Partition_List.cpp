//
// Created by Zidong Liu on 8/30/18.
//
#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x),next(NULL){}
};
/////////// great solution
/////////// beat 100%
/////////// remember to set the end as NULL
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* ret = new ListNode(0), *cur= head, *prev_end, *post_begin = new ListNode(0), *post_end;
        prev_end = ret;
        post_end = post_begin;
        while(cur!=NULL){

            if(cur->val < x){
                prev_end->next = cur;
                prev_end = prev_end->next;
            }else{
                post_end->next = cur;
                post_end = post_end->next;
            }

            cur = cur->next;
        }
        prev_end->next = post_begin->next;
        post_end->next =NULL;
        return(ret->next);
    }
};