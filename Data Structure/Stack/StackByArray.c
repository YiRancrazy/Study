#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100 
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

// 顺序栈数据类型定义
typedef struct{
    int *base;   // 栈底指针
    int *top;    // 栈顶指针
    int stackSize; // 栈最大容量
}SqStack;

// 函数声明

void InitStack(SqStack* list); // 初始化一个空栈
int StackEmpty(SqStack* list); // 判断是否为空栈
int GetLength(SqStack* list);
void ClearStack(SqStack* list); // 清空栈
void DestroyStack(SqStack* list);
int Push(SqStack* list,int value);
int Pull(SqStack* list,int* value);


int main(int argc, char *argv){
    SqStack list;

    return 0;
}

// 初始化一个空栈
void InitStack(SqStack* list){
    list->base = (int*)malloc(MaxSize*sizeof(int));  // 申请内存空间
    list->top = list->base;   // 栈顶指针等于栈底指针
    list->stackSize = MaxSize;
}

// 判断是否为空栈
int StackEmpty(SqStack* list){
    if (list->top==list->base)
        return TRUE;
    return FALSE;
}

// 求栈的长度
int GetLength(SqStack* list){
    return list->top-list->base;
}

// 清空栈
void ClearStack(SqStack* list){
    list->top = list->base;
}

void DestroyStack(SqStack* list){
    if(list->base){
        free(list->base);   // 销毁数组
        // 将结构类型中的字段设置为空
        list->stackSize = 0;             
        list->base = list->top = NULL;
    }
}


// 入栈
int Push(SqStack* list,int value){
    if(list->top-list->base==list->stackSize)  // 判断栈满
        return ERROR;
    // *list.top++=value;    // list指针++，list.top 赋值
    list->top++;
    *list->top=value;
    
    return OK;
}


// 出栈
int Pull(SqStack* list,int* value){
    if(list->top==list->base)
        return ERROR;
    *value=*list->top;
    list->top--;
    return OK;
}
