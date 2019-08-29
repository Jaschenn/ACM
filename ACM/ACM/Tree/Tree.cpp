//
//  Tree.cpp
//  ACM
//
//  Created by jas chen on 2019/8/29.
//  Copyright © 2019 jas chen. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Stack.cpp"
using namespace std;

# define ElemType int

typedef struct BiTNode{
    ElemType data;
    BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void visit(BiTree T){
    cout<<T->data<<endl;
}

void PreOrder(BiTree T){
    if(T!=nullptr){
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(BiTree T){
    if (T!=nullptr) {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

void PostOrder(BiTree T){
    if(T!=nullptr){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

void InOrder2(BiTree T){
    SqStack S;
    //二叉树中序遍历非递归算法，需要借助一个栈
    InitStack(S);
    BiTree p = T; //p是遍历指针
    while (p||!IsEmpty(S)) {
        if(p){
            Push(S, p);
            p=p->lchild;
        }else{
            Pop(S, p);
            visit(p);
            p=p->rchild;
        }
    }
    
}

void LevelOrder(BiTree T){
    
}



