#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// 1. 定义双向链表节点
typedef struct DNode {
    int data;
    struct DNode* prior, * next;
} DNode;

// 2. 初始化头节点（带头结点）
DNode* initList() {
    DNode* head = (DNode*)malloc(sizeof(DNode));
    head->prior = NULL;
    head->next = NULL;
    return head;
}

// 3. 头插法
void addFirst(DNode* head, int data) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = data;
    newNode->prior = head;
    newNode->next = head->next;
    if (head->next != NULL) {
        head->next->prior = newNode;
    }
    head->next = newNode;
}

void printList(DNode* list)
{
    DNode* p = list;
    while (p->next != NULL)
    {
        p = p->next;
        printf("%d<->", p->data);
    }
}


//尾插法
void lastCreate(DNode* list1, int* arr, int n)
{
    DNode* rail = list1;
    for (int i = 0;i < n; i++)
    {
        DNode* newNode = (DNode*)malloc(sizeof(DNode));
        newNode->data = arr[i];
        newNode->next = NULL;
        newNode->prior = rail;
        rail = newNode;
    }

}

int main() 
{
    DNode* list = initList();
    addFirst(list, 10);
    addFirst(list, 20);
    addFirst(list, 30);
    printList(list);   // 预期: 30 <-> 20 <-> 10 <-> NULL

    //尾插法
    DNode* list1 = initList();
    int n;
    printf("请输入个数");
    scanf("%d", &n);
    int* arr = (int*)malloc(sizeof(int) * n);
    printf("请输入数组数据");
    for (int i = 0;i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
lastCreate(list1, arr, n);

return 0;
}