// 链表的表示和实现
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100 
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

//结构
typedef struct StackNode{
    int data;
    struct StackNode *next;
}StackNode,*LinkStack;


// 函数声明
LinkStack InitList(LinkStack list);  // 初始化
int StackEmpty(LinkStack list);
LinkStack Push(LinkStack top, int value); // 入栈
LinkStack Pull(LinkStack list,int* value); // 出栈
int GetTopElem(LinkStack list); // 取栈顶元素

int main(int argc, char *argv){
    LinkStack list;
    int value=0;
    list = InitList(list);
    list = Push(list,10);
    list = Push(list,20);
    list = Pull(list,&value);
    printf("%d",value);
    printf("%d",StackEmpty(list));




    return 0;
}
// top 指针在函数内部建立了一个局部指针变量，导致返回后，top的指针地址会变回全局变量时的值。

// 函数定义
// 初始化
LinkStack InitList(LinkStack list){
    list = NULL;
    return list;
}

int StackEmpty(LinkStack list){
    if(list=NULL)
        return TRUE;
    return FALSE;
}


LinkStack Push(LinkStack list,int value){
    LinkStack p = (LinkStack)malloc(sizeof(StackNode));
    p->data = value;
    p->next = list;
    list = p;
}

LinkStack Pull(LinkStack list,int* value){
    if(list==NULL)         // 如果栈内没有元素，则返回
        return list;
    LinkStack p = (LinkStack)malloc(sizeof(StackNode));
    *value = list->data;
    p=list;
    list = list->next;
    free(p);
    
    return list;
}

int GetTopElem(LinkStack list){
    if(list!=NULL){
        return list->data;
    }
}

// 新增
// void Add(LinkStack top,int value){
//     top->data = value;
//     top = top->next;
// }

