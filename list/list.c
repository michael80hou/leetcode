#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


typedef struct element {
    int data;
    struct element *next;
} node;


node* create_list() 
{
    node *head = NULL;
    head = malloc(sizeof(node));
    if(NULL == head) {
        printf("list create fails\n");
        return NULL;
    }
    head->data = 0;
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
        printf("%d -> ", element->data);
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

//delete element in middle of list
void delete_mid(node *element) 
{
    if(NULL == element) {
        return;
    }

    if(NULL == element->next) {
        printf("only used to delete mid element!\n");
    } else {
        element->data = element->next->data;
        element->next = element->next->next;
    }   

}

void reverse(node *head) 
{
    if(NULL == head || NULL == head->next) {
        return;
    }


    node *pre = NULL;
    node *cur = head->next;

    while(cur) {
        if(cur->next) {
            node *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        } else {
            cur->next = pre;
            head->next = cur;
            break;
        }
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

        //delete_mid(&node2);
        reverse(head);
        print_list(head);
    }
  
    return 0;

}
