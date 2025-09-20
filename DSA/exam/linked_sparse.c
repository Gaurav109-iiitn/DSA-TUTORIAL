#include<stdio.h>
#include<stdlib.h>

struct node{
    int row;
    int col;
    int value;
    struct node* next;
};

struct node* head=NULL;
struct node* head1=NULL;
struct node* head3=NULL;

struct node* createNode(int r,int c,int v){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->row=r;
    newNode->col=c;
    newNode->value=v;
    newNode->next=NULL;
    return newNode;
}

struct node* insertNode(struct node* head,int r,int c,int v){
    struct node* newNode=createNode(r,c,v);
    if(head==NULL){
        head=newNode;
        return head;
    }
    struct node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}
 
struct node* insertvalue(struct node* head,int r,int c,int value){
    struct node* temp=head;
    while(temp!=NULL){
        if(temp->row==r && temp->col==c){
            temp->value=value;
            return head;
        }
        temp=temp->next;
    }
    // if node not found, insert new one
    head=insertNode(head,r,c,value);
    return head;
}

int getValue(struct node* head,int r,int c){
    while(head!=NULL){
        if(head->row==r && head->col==c){
            return head->value;
        }
        head=head->next;
    }
    return 0;
}

struct node* add(struct node* head,struct node* head1,int trow,int tcol){
    struct node* result=NULL;
    for(int i=0;i<trow;i++){
        for(int j=0;j<tcol;j++){
            int value1=getValue(head,i,j);
            int value2=getValue(head1,i,j);
            int sum=value1+value2;
            if(sum!=0){
                result=insertNode(result,i,j,sum);
            }
        }
    }
    return result;
}

void print(struct node* head,int trow,int tcol){
    for(int i=0;i<trow;i++){
        for(int j=0;j<tcol;j++){
            printf("%d\t",getValue(head,i,j));
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    int row,col;
    printf("Enter rows and cols of matrix A: ");
    scanf("%d %d",&row,&col);

    int n;
    printf("Enter number of non-zero elements in A: ");
    scanf("%d",&n);
    printf("Enter row, col and value:\n");
    for(int i=0;i<n;i++){
        int ro,co,value;
        scanf("%d %d %d",&ro,&co,&value);
        head=insertvalue(head,ro,co,value);
    }

    int row1,col1;
    printf("Enter rows and cols of matrix B: ");
    scanf("%d %d",&row1,&col1);

    int n1;
    printf("Enter number of non-zero elements in B: ");
    scanf("%d",&n1);
    printf("Enter row, col and value:\n");
    for(int i=0;i<n1;i++){
        int ro,co,value;
        scanf("%d %d %d",&ro,&co,&value);
        head1=insertvalue(head1,ro,co,value);
    }

    // check dimensions before adding
    if(row!=row1 || col!=col1){
        printf("Matrix addition not possible! Rows and columns must be the same.\n");
        return 0;
    }

    printf("Matrix A:\n");
    print(head,row,col);

    printf("Matrix B:\n");
    print(head1,row1,col1);

    head3=add(head,head1,row,col);

    printf("Matrix A + B:\n");
    print(head3,row,col);

    return 0;
}
