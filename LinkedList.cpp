//
// Created by pwu5 on 8/18/2017.
//

#include "LinkedList.h"
#include <iostream>
using  namespace std;

void LinkedList::insertNode(ListNode *newNode) {
    //insert into first node
    newNode->next = head;
    head = newNode;
}

LinkedList::LinkedList() {
    head = NULL;
}

void LinkedList::displayList() {
    ListNode* cur = head;
    while (cur!=NULL) {
        cout << cur->val << "->";
        cur = cur->next;
    }
    cout << "NULL"<< endl;
}

void LinkedList::swapNode(int index) {
    // swap the nodes with the given index from front and end of the List.
    int n = 0;  //USED to record the total number
    ListNode* cur = head;
    ListNode* node1 = NULL;
    ListNode* pre1 = NULL;
    while (cur!= NULL) {
        if (n+1 == index) {
            node1 = cur;
        }
        if (node1 == NULL)
            pre1 = cur;
        cur = cur->next;
        n++;
    }
    if (2*index -1 == n) return;    // the same node

    ListNode* node2 = NULL;
    ListNode* pre2 = NULL;

    int i = 1;
    cur = head;
    while ( i < n - index + 1) {
        pre2 = cur;
        cur = cur->next;
        i++;
    }
    node2 = cur;

    if (index == 1 ) {
        pre2->next = node1;
        cur = node1->next;
        node1->next = node2->next;
        node2->next = cur;
        head = node2;
    } else if (index == n) {
        pre1->next = node2;
        cur = node1->next;
        node1->next = node2->next;
        node2->next = cur;
        head = node1;
    }
    else {
        pre1->next = node2;
        pre2->next = node1;
        cur = node1->next;
        node1->next = node2->next;
        node2->next = cur;
    }


}
