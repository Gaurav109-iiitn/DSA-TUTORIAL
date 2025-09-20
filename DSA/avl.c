#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    int height;
    struct node* left,* right;
};

int h(struct node* temp){
    if(temp==NULL)
    return 0;
    return temp->height;
}

int max(int a,int b){
    return (a>b)? a:b;
}

struct node* rightrotate(struct node* y){
    struct node* x=y->left;
    struct node* t2=x->right;

    x->right=y;
    y->left=t2;

    y->height=max(h(y->left),h(y->right))+1;
    x->height=max(h(x->left),h(x->right))+1;
    return x;
}

struct node* leftrotate(struct node* x){
struct node* y=x->right;
struct node* t2=y->left;

y->left=x;
x->right=t2;
x->height=max(h(x->left),h(x->right))+1;
y->height=max(h(y->left),h(y->right))+1;
return y;
}

struct node* newnode(int data){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->height=1;
    temp->left=temp->right=NULL;
    return temp;
}

int bf(struct node* n){
    if(n==NULL)
    return 0;
    return h(n->left)-h(n->right);
}

struct node* insertion(struct node* node,int key){
    if(node==NULL)
    return newnode(key);
    if(key<node->data){
        node->left=insertion(node->left,key);
    }
    else if(key>node->data){
        node->right=imsertion(node->right,key);
    }
    else
    return node;

    node->height=max(h(node->left),h(node->right))+1;

    int bf1=bf(node);

    if(bf1>1 && key<node->left->data){
        return rightrotate(node);
    }
    if(bf1<-1 && key>node->right->data){
        return leftrotate(node);
    }
    if(bf1>1 && key>node->left->data){
        node->left=leftrotate(node);
        return rightrotate(node);
    }
    if(bf1<-1&& key)
}

int main(){
    return 0;
}