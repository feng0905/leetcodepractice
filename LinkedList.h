//
// Created by pwu5 on 8/18/2017.
//

#ifndef LEETCODE_LINKEDLIST_H
#define LEETCODE_LINKEDLIST_H

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int _val){
        val = _val;
    }
};

class LinkedList {

private:
    ListNode* head;

public:
    LinkedList();
    void insertNode(ListNode* newNode);
    void displayList();
public:
    void swapNode(int index) ;
};


#endif //LEETCODE_LINKEDLIST_H
