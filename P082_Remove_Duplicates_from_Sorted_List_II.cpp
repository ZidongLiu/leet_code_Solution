//
// Created by Zidong Liu on 8/28/18.
//
#include <iostream>
using namespace std;
////// 8ms, beat 15%

struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
     };


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL){
            return(head);
        }
        ListNode* ret = new ListNode(0);
        ListNode* ret_end = new ListNode(0), *cur_start, *cur;
        ret = ret_end;
        cur = head;
        cur_start = head;
        int k=1;
        while(cur->next!=NULL){
            /*
            cout<<"ret: "<<endl;
            printlist(ret);
            cout<<"cur_start: "<<endl;
            printlist(cur_start);
            cout<<"cur: "<<endl;
            printlist(cur);
            cout<<"ret_end: "<<endl;
            printlist(ret_end);
            */
            ///cout<<cur_start->val<<endl;
            ///cout<<"K:"<<k<<endl;
            if(cur->next->val == cur_start->val){
                k++;
                cur = cur->next;
            }else{
                if(k==1){
                    //cout<<"here"<<endl;
                    ret_end->next = cur_start;
                    ret_end = ret_end->next;
                }
                cur = cur->next;
                cur_start = cur;
                k =1;
            }
            /*
            cout<<"k: "<<k<<endl;
            cout<<endl;
             */
        }
        if(k==1){
            ret_end->next = cur_start;
        }else{
            ret_end->next = NULL;
        }
        return(ret->next);
    }
};