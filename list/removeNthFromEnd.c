#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


struct ListNode {
    int val;
    struct ListNode *next;
};


typedef struct ListNode node;

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    assert(head);
    assert(n >= 1);

    struct ListNode* res = head;
    struct ListNode* cur = head;
    struct ListNode* candicate_end = head;
    int stop = 0;

    while(n--) {
        candicate_end = candicate_end->next;
        if(NULL == candicate_end) {
            stop = 1;
            res = n > 0 ? NULL : head->next;
            break;
        }
    }

    if(!stop) {    
        while(candicate_end->next) {
            candicate_end = candicate_end->next;
            cur = cur->next;
        }

        cur->next = cur->next->next; 
    }
    
    return res;    
}

node* create_list() 
{
    node *head = NULL;
    head = malloc(sizeof(node));
    if(NULL == head) {
        printf("list create fails\n");
        return NULL;
    }
    head->val = 0;
    head->next = NULL;
    return head;

}

void print_list(node *head)
{
    if(NULL == head) {
        return;
    }

    printf("head -> ");

    node *element = head->next;
    while(element) {
        printf("%d -> ", element->val);
        element = element->next;
    }

    printf("NULL\n");
}

void insert(node* head, node *element) 
{
    if(NULL == head || NULL == element) {
        return;
    }

    node *tmp = head->next;
    if(NULL == tmp) {
        head->next = element;
    } else {
        head->next = element;
        element->next  = tmp;
    }
}


int main()
{
    node node1 = {1, NULL};
    node node2 = {2, NULL};
    node node3 = {3, NULL};
    node node4 = {4, NULL};
    node node5 = {5, NULL};
    node node6 = {6, NULL};
    node *head = create_list();
    if(NULL != head) {
        insert(head, &node1);
        insert(head, &node2);
        insert(head, &node3);
        insert(head, &node4);
        insert(head, &node5);
        insert(head, &node6);

        print_list(head);
        head = removeNthFromEnd(head, 1);
        print_list(head);
    }
  
    return 0;

}
