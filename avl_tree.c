#include<stdio.h>
#include<stdlib.h>

struct node{
    int key;
    struct node* left,* right;
    int height;
};

struct node* root=NULL;

int height(struct node* n){
    if(n==NULL)
    return 0;
    return n->height;
}

int max(int a,int b){
    return (a>b)?a:b;
}

int bf(struct node* n){
    if(n==NULL)
    return 0;
    return height(n->left)-height(n->right);
}

struct node* newnode(int key){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->key=key;
    temp->height=1;
    temp->left=temp->right=NULL;
    return temp;
}

struct node* rightrotate(struct node* y){
struct node* x=y->left;
struct node* t2=x->right;

x->right=y;
y->left=t2;   

y->height=max(height(y->left),height(y->right))+1;
x->height=max(height(x->left),height(x->right))+1;

return x;
}

struct node* leftrotate(struct node* x){
    struct node* y=x->right;
    struct node* t2=y->left;

    y->left=x;
    x->right=t2;

    x->height=max(height(x->left),height(x->right))+1;
    y->height=max(height(y->left),height(y->right))+1;

    return y;
}

struct node* insertion(struct node* node,int key){
    if(node==NULL)
    return newnode(key);

    if(key<node->key)
    node->left=insertion(node->left,key);
    else if(key>node->key){
        node->right=insertion(node->right,key);
    }
    else
    return node;

    node->height=1+max(height(node->left),height(node->right));

int bf1=bf(node);

if(bf1>1 && key<node->left->key){
    return rightrotate(node);
}

if(bf1<-1 && key>node->right->key){
    return leftrotate(node);
}

if(bf1>1 && key>node->left->key){
    node->left=leftrotate(node->left);
    return rightrotate(node->left);
}

if(bf1<-1 && key<node->right->key){
    node->right=rightrotate(node->right);
    return leftrotate(node->right);
}
 
return node;
}

void preorder(struct node* root){
    if(root==NULL)
    return;
    printf("%d\t",root->key);
    preorder(root->left);
    preorder(root->right);
}

int main(){

    int n;
    printf("enter number of nodes\n");
    scanf("%d",&n);
    printf("enter data in nodes\n");
    for(int i=0;i<n;i++){
        int data;
        scanf("%d",&data);
        root=insertion(root,data);
    }

    preorder(root);
    return 0;
}