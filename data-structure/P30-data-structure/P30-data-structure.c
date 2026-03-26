#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 1. 节点结构体
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 2. 链表结构体（也可以直接用一个头指针，这里用结构体方便扩展）
typedef struct LinkedList {
    Node* head;
} LinkedList;

// 初始化链表
void initList(LinkedList* list) {
    list->head = NULL;
}

// 头插法：新节点成为新的头
void addFirst(LinkedList* list, int data) {
    // TODO: 
    // 1. 创建新节点，分配内存
    // 2. 新节点的 next 指向当前头结点
    // 3. 头指针指向新节点
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = data;
    p->next = list->head;
    list->head = p;
}

// 尾插法：新节点放在链表末尾
void addLast(LinkedList* list, int data) {
    // TODO:
    // 1. 创建新节点
    // 2. 如果链表为空，直接让 head 指向新节点
    // 3. 否则，遍历到最后一个节点，让它的 next 指向新节点
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (list->head == NULL)
    {
        list->head = newNode;
    }
    else
    {
        Node* current = list->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }

}

// 打印链表
void printList(LinkedList* list) {
    // TODO:
    // 从 head 开始，遍历每个节点，输出 data，用 -> 连接
    // 最后输出 NULL 换行
    Node* currunt = list->head;
    while (currunt!= NULL)
    {
        printf("%d", currunt->data);
        currunt = currunt->next;
    }
}

// 释放链表内存（防止内存泄漏）
void freeList(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    list->head = NULL;
}

int main() {
    LinkedList list;
    initList(&list);

    // 头插法测试
    addFirst(&list, 1);
    addFirst(&list, 2);
    addFirst(&list, 3);
    printf("头插后: ");
    printList(&list);  // 预期: 3 -> 2 -> 1 -> NULL

    // 尾插法测试
    addLast(&list, 4);
    addLast(&list, 5);
    printf("再尾插后: ");
    printList(&list);  // 预期: 3 -> 2 -> 1 -> 4 -> 5 -> NULL

    // 释放内存
    freeList(&list);
    return 0;
}