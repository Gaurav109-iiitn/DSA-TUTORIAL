#include<stdio.h>
#include<stdlib.h>

typedef struct  node{
    int data;
    struct node* left,* right;
}Node;

Node* parent=NULL;

Node* create(int data){
    Node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->right=temp->left=NULL;
    return temp;
}

Node* insert(Node* head,int data){
    if(head==NULL){
        return create(data);
    }
    if(data<head->data){
        head->left=insert(head->left,data);
    }
    if(data>head->data){
        head->right=insert(head->right,data);
    }
    return head;
}

void display_inorder(Node* temp){
if(temp!=NULL){
    display_inorder(temp->left);
    printf("%d ",temp->data);
    display_inorder(temp->right);
}
}

Node* search(Node* root,int data){
    if(root==NULL|| root->data==data){
        return root;
    }
    if(data<root->data){
        return search(root->left,data);
    }
    if(data>root->data)
    return search(root->right,data);
    return NULL;
}
int main(){
    int n;
    printf("enter n\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int data;
        scanf("%d",&data);
        parent=insert(parent,data);
    }
    int data1=67;
    display_inorder(parent);
    printf("\n");
    printf("%d",search(parent,data1)->data);
    return 0;
}