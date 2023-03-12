//linearlist
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100 
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2


typedef struct{
    int *elem;
    int length;
}SqList;


// 初始化线性表
int InitList(SqList *LinearList){
    LinearList->elem=(int*)malloc(sizeof(int)*MaxSize);
    if (!LinearList->elem)
        return OVERFLOW;  
    LinearList->length = 0;
    return OK;
}


// 销毁线性表
void DestroyList(SqList *LinearList){
    if(LinearList->elem)
        free(LinearList->elem);
}



// 清空线性表
void ClearList(SqList *LinearList){
    LinearList->length = 0;
}

// 求线性表的长度
int GetLength(SqList LinearList){
    return(LinearList.length);
}

// 生成线性表
void Initelem(SqList *LinearList){
    int i,count=0;
    for (int i = 0; i < 60; i++){
        LinearList->elem[i]=count++;
        LinearList->length=i+1;
    }
}

// 遍历线性表
void ErgodicList(SqList *LinearList){
    int i;
    for (int i = 0; i < LinearList->length; i++){
        printf("%d\n",LinearList->elem[i]);   
    }
}


// 判断线性表是否为空
int IsEmpty(SqList LinearList){
    if(LinearList.length == 0)
        return 1;
    else
        return 0;
}


// 取值
int GetElem(SqList LinearList,int i,int *e){
    if(i<1||i>LinearList.length)
        return ERROR;
    *e=LinearList.elem[i-1];
    return OK;
}

// 查找
int SearchList(SqList LinearList,int value){
    int i;
    for(i=0;i<LinearList.length;i++)
        if (LinearList.elem[i]==value)
            return i;
    return -1;    
}

// 插入
int InsertList(SqList *LinearList,int pos,int value){
    if(pos<0||pos>LinearList->length)  // 判断位置是否合法
        return ERROR;
    if (LinearList->length==MaxSize)  
        return ERROR;
    for (int i = LinearList->length; i >=pos; i--)
        LinearList->elem[i+1] = LinearList->elem[i]; 
    
    LinearList->elem[pos] = value;
    return ++LinearList->length;
}

// 删除


int main(int argc, char *argv){
    SqList List1;
    InitList(&List1);
    Initelem(&List1);
    printf("%d",GetLength(List1));
    InsertList(&List1,0,99);
    printf("%d\n",GetLength(List1));
    ErgodicList(&List1);


    return 0;
}




/* 线性表操作
    1、初始化
    2、销毁
    3、清空
    4、判断是否为空表
    5、判断长度
    6、查找
    7、筛选查找
    8、获取一个元素的前驱
    9、获取一个元素的后继
    10、插入
    11、删除
    12、遍历
    13、……
*/ 