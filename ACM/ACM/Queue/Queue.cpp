//
//  Queue.cpp
//  ACM
//
//  Created by jas chen on 2019/8/29.
//  Copyright © 2019 jas chen. All rights reserved.
//

#include <stdio.h>
#include "iostream"
using namespace std;
# define MAXSIZE 50
# define ElemType int

typedef struct {
    ElemType data[MAXSIZE];
    int front,rear;
}SqQueue;

void InitQueue(SqQueue &Q){
    Q.rear = Q.front = 0;
}

bool isEmpty(SqQueue Q){
    if(Q.rear==Q.front) return true;
    else return false;
}

bool EnQueue(SqQueue &Q, ElemType x){
    if((Q.rear+1)%MAXSIZE==Q.front){
        return false;
    }
    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1)%MAXSIZE;
    return true;
}

bool DeQueue(SqQueue &Q,ElemType &x){
    if(Q.rear==Q.front){
        return false;
    }
    x = Q.data[Q.front];
    Q.front=(Q.front+1)%MAXSIZE;
    return true;
}


