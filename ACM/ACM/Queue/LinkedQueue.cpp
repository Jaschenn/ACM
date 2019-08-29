//
//  LinkedQueue.cpp
//  ACM
//
//  Created by jas chen on 2019/8/29.
//  Copyright © 2019 jas chen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
# define MaxSize 50
# define ElemType int
typedef struct LinkNode{
    ElemType data;
    LinkNode *next;
}LinkNode;

typedef struct {
    LinkNode *front,*rear;
}LinkQueue;

void InitQueue(LinkQueue &Q){
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next=nullptr;
}

bool IsEmpty(LinkQueue Q){
    if (Q.front==Q.rear) {
        return true;
    }else{
        return false;
    }
}

void EnQueue(LinkQueue &Q,ElemType x){
    LinkNode *s=(LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = nullptr;
    Q.rear->next=s;
    Q.rear=s;
}

bool DeQueue(LinkQueue &Q, ElemType &x){
    if(Q.front==Q.rear){
        return false;
    }
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if(Q.rear==p){
        Q.rear = Q.front;
    }
    free(p);
    return true;
}
