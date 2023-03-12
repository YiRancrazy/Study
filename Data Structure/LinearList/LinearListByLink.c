#include<stdio.h>
#include<stdlib.h>
#define YES 1
#define NO 0
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2


typedef struct Lnode{
    int data;
    struct Lnode* next;
}Lnode,*Linklist;

// 初始化
Linklist initList(Linklist list){
    list = (Linklist)malloc(sizeof(Lnode));
    list->next=NULL;
    return list;
}


// 返回第i个结点的值
int GetElem(Linklist list,int index){
    Linklist p = list;
    for (int i = 0; i <= index; i++){       // 向后扫描，直到找到指定位置
        if(i==index){
            return p->data;
        }
        p = p->next;
    }
    return 0;
}


// 查找
int search(Linklist list,int value){
    int index = 0;
    Linklist p = list;
    while(list){
        if(p->data == value)
            return index;
        p = p->next;   
        index++;
    }

}

//插入
int insert(Linklist list,int index,int value){
    Linklist p = list;
    int i = 0;
    while (p&&i<index-1){
        p=p->next;
        i++;
    }

    if(!p||i>index-1)
        return ERROR;
    
    Linklist newNode = (Linklist)malloc(sizeof(Lnode));
    newNode->data = value;
    newNode->next = p->next;
    p->next = newNode;

    return OK;
}







//其他操作
// 判断链表是否为空
int isEmpty(Linklist list){
    if(list->next==0)
        return NO;
    else
        return YES;
}



// 创建一个新结点
Linklist newNode(){
    Linklist p = (Linklist)malloc(sizeof(Lnode));
    scanf("%d",&p->data);
    p->next = NULL;                                     // p的next指针置空
    return p;
}

//新增结点（有bug)
void add(Linklist list){
    Linklist p = newNode();
    Linklist q = list;
    while (q->next){
        q = q->next;
    }

    q->next = p;
}

// 销毁链表
int DestroyList(Linklist list){
    Linklist p;
    while (list){
        p=list;
        list=list->next;
        free(p);
    }
    return OK;
}

//清空列表
int ClearList(Linklist list){            
    Linklist p = list->next,q; 
    while(p){                     //是否为表尾
        q = p->next;
        free(p);
        p=q;
    }
    list->next=NULL;             //头结点指针域为空
    return OK;
}

// 求链表的长度
int GetLen(Linklist list){
    Linklist p = list->next;              //p 指向第一个结点
    int count = 0;
    while (p){
        p=p->next;
        count++;
    }   
    return count;
}

// 删除结点
int delete(Linklist list,int index){
    Linklist p= list;
    int count = 0;
    while (p->next&&count<index-1){
        p = p->next;
        count++;
    }

    if(!(p->next)||index>count-1)
        return ERROR;
    Linklist q = p->next;
    p->next = q->next;          //改变删除结点前驱结点的指针域
    free(q);                    // 释放删除结点的空间
}

// 输出
void Print(Linklist list){
    Linklist p = list->next;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}



// 主函数
int main(int argc, char *argv){
    Linklist list;
    list = initList(list);
    add(list);
    add(list);
    add(list);
    Print(list);

    return 0;
}