//
// Created by Zidong Liu on 9/1/18.
//
#include <iostream>
using namespace std;
///////// beat 100%
////////
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x),next(NULL){}
};


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n)
        {
            return(head);
        }
        ListNode *rev_start =NULL,*rev_end, *front_end, *back_start;
        ListNode *cur = head;
        int i=1;
        if(m>1){
            while(i < m-1){
                i++;
                cur = cur->next;
            }
            front_end = cur;
            i++;
            cur = cur->next;
        }

        while(i<=n){
            ListNode *this_node = new ListNode(cur->val);
            if(i==m){
                rev_end = this_node;
            }
            this_node ->next = rev_start;
            rev_start = this_node;
            i++;
            cur = cur->next;
        }
        rev_end->next = cur;
        if(m==1){
            return(rev_start);
        }else{
            front_end->next = rev_start;
            return(head);
        }
    }
};
