#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* right;
    struct node* left;
};
struct node* root=NULL;
struct node* Node(int data){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
struct node* insertion(struct node* root,int data){
    if(root==NULL){
        root = Node(data);
    }
    else if(root->data>data){
    root->left= insertion(root->left,data);
    }
    else if(root->data<data) {
       root->right= insertion(root->right,data);
    }
    return root;
}

struct node* delete(struct node* root){
   
}

struct node* search(struct node* root,int data){

}

 void inorder(struct node* root){
    if(root!=NULL) {
     inorder(root->left);
    printf("%d\t",root->data);
   
    inorder(root->right);
 }
}
 void postorder(struct node* root){
    if(root!=NULL) {
    postorder(root->left);
    postorder(root->right);
     printf("%d\t",root->data);
 }
}
 void preorder(struct node* root){
    if(root!=NULL) {
    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->right);
    }
 }
 int main(){
    int n;
    printf("enter n\n");
    scanf("%d",&n);
    printf("enter data\n");
    for(int i=0;i<n;i++){
        int data;
        scanf("%d",&data);
       root= insertion(root,data);
    }
    printf("\nPreorder Traversal:\n");
    preorder(root);

    printf("\n\nInorder Traversal:\n");
    inorder(root);

    printf("\n\nPostorder Traversal:\n");
    postorder(root);
    return 0;
 }
