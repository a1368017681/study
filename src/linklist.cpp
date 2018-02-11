#include <iostream>
#include <time.h>

using namespace std;
#define N 10
typedef struct Node{
    int val;
    Node* next;
}LinkNode;

LinkNode* head = NULL;

void printLinkList(LinkNode* hd) {
    LinkNode* tmp = hd;
    while (tmp) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void insert_back(int value) {
    LinkNode* node = (LinkNode*)malloc(sizeof(LinkNode));
    node->next = NULL;
    node->val = value;
    LinkNode* tmp = head;
    if (head == NULL) {
        head = node;
    } else {
        while (tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = node;
    }
}

void back_insert(int value) {
    LinkNode* node = (LinkNode*)malloc(sizeof(LinkNode));
    node->val = value;
    node->next = head;
    head = node;
    //printLinkList(*hd);
}

void reverse(LinkNode* hd) {
    LinkNode* tail = NULL;
    LinkNode* curr = hd;
    while (curr) {
        /*LinkNode* node = (LinkNode*)malloc(sizeof(LinkNode));
          node->val = curr->val;
          node->next = tail;
          tail = node;
          curr = curr->next;*/
        LinkNode* node = curr->next;
        curr->next = tail;
        tail = curr;
        curr = node;
    }
    printLinkList(tail);
}

void initLinkList() {
    //for (int i = 0; i < N; i++) {
    //	insert_back(i);
    //}
    for (int i = 0; i < N; i++) {
        back_insert(i);
    }
}

int _linklist() {
    srand(time(NULL));
    initLinkList();
    printLinkList(head);
    reverse(head);
    //printLinkList(head);
}
