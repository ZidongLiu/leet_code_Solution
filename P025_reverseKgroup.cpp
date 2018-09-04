//
// Created by Zidong Liu on 6/4/18.
//
/*
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x),next(NULL){}
};

ListNode* generate_list(vector<int> input){
    ListNode *dummy = new ListNode(0),*cur;
    cur = dummy;
    for(int i=0;i<input.size();i++){
        cur->next = new ListNode(input[i]);
        cur = cur->next;
    }
    return(dummy->next);
}


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* left=head, *right=head;
        for(int i=0;i<k-1;++i){
            right = right->next;
            if(right){
                return(left);
            }
        }
        right = right->next;
        ListNode *prev=NULL, *cur = head, *next=NULL;
        while(cur!=right){
            next = cur->next;
            cur->next = prev;/// reverse direction
            prev = cur;
            cur = next;
        }
        prev->next = reverseKGroup(right,k);
        return(prev);
    }
};

 */