//
// Created by Zidong Liu on 8/28/18.
//
/*
#include <vector>
#include <iostream>
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

void printlist(ListNode* l){
    while(l!=NULL){
        cout<<l->val<<" ";
        l = l->next;
    }
    cout<<endl;
}

 */