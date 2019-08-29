//
//  Stack.cpp
//  ACM
//
//  Created by jas chen on 2019/8/29.
//  Copyright © 2019 jas chen. All rights reserved.
//

#include <stdio.h>
#include <stdio.h>
#include "iostream"
using namespace std;

#define MAXSIZE 50
#define Elemtype int
typedef struct{
    ElemType data[MAXSIZE];
    int top;
}SqStack;
void InitStack(SqStack &S);



void InitStack(SqStack &S){
    S.top = -1;
}

bool IsEmpty(SqStack S){
    if(S.top==-1){
        return true;
    }else{
        return false;
    }
}

bool Push(SqStack &S, Elemtype x){
    if(S.top==MAXSIZE-1){
        return false;
    }
    S.data[++S.top] = x;
    return true;
}

bool Pop(SqStack &S,Elemtype &x){
    if(S.top==-1){
        return false;
    }
    x = S.data[S.top--];
    return true;
}

bool GetTop(SqStack S, Elemtype &x){
    if(S.top==-1){
        return false;
    }
    x = S.data[S.top];
    return true;
}
