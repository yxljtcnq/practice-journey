#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
//定义节点
typedef struct DNode {
    int data;
    struct DNode* prior, * next;
} DNode;

// 初始化链表
DNode* initList() {
    DNode* head = (DNode*)malloc(sizeof(DNode));
    head->prior = NULL;
    head->next = NULL;
    return head;
}

//头插法
void addFirst(DNode* head, int data)
{
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = data;
    newNode->prior = head;
    newNode->next = head->next;
    if (head->next != NULL)
        head->next->prior = newNode;
    head->next = newNode;
}


//打印链表
void printList(DNode* list)
{
    DNode* p = list->next;
    while (p != NULL)
    {
        printf("%d", p->data);
        if (p->next) printf("<->");
        p = p->next;
    }
    printf("\n");
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
        rail->next = newNode;
        rail = newNode;
    }
}

//删除链表
void destroyList(DNode* head) 
{
    DNode* p = head;
    while (p != NULL) 
    {
        DNode* temp = p;
        p = p->next;
        free(temp);
    }
}


//删除节点
void destroyNode(DNode* head,int data)
{
    DNode* p = head->next;
    if (p == NULL)
    {
        printf("链表为空\n");
    }
    while (p != NULL && p->data != data)
    {
        p = p->next;
    }
    p->prior->next = p->next;
    if (p->next != NULL)
    {
        p->next->prior = p->prior;
    }
    free(p);
}


int main()
{
    DNode* list = initList();
    addFirst(list, 10);
    addFirst(list, 20);
    addFirst(list, 30);
    printList(list);

    DNode* list1 = initList();
    int n;
    printf("请输入个数：");
    scanf("%d", &n);
    int arr[n];
    printf("请输入数组数据：");
    for (int i = 0;i < n; i++)
        scanf("%d", &arr[i]);

    lastCreate(list1, arr, n);
    printList(list1);

    printf("请输入要删除表二的哪个数据");
    int a = 0;
    scanf("%d", &a);
    destroyNode(list,10);
    destroyNode(list1,a);

    printf("删除后的链表");
    printList(list);
    printList(list1);
    destroyList(list);
    destroyList(list1);
    return 0;
}