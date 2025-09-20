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
    break;
}
    temp=temp->next;
}
return head;
}

struct node* add(struct node* h1,struct node* h2,int r1,int c1){
    for(int i=0;i<r1;i++){
    for(int j=0;j<c1;j++){
    struct node* head3=insertvalue(head3,i,j,h1->value+ h2->value);
    }
        }
    }
    


void print(struct node* head,int trow,int tcol){
    struct node* temp=head;
    for(int i=0;i<trow;i++){
        for(int j=0;j<tcol;j++){
            if(temp!=NULL && temp->row==i && temp->col==j ){
                printf("%d\t",temp->value);
                temp=temp->next;
            }
        }
        printf("\n");
    }
}

int main(){
    int row,col;
    printf("enter row and col\t");
    scanf("%d %d",&row,&col);
    for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
    head=insertNode(head,i,j,0);
    }
    }
    int n;
    printf("enter n\t");
    scanf("%d",&n);
    printf("enter non-zeros elements\n");
    for(int i=0;i<n;i++){
        int ro,co,value;
        printf("Enter row, col and value: \n");
        scanf("%d %d %d",&ro,&co,&value);
        head=insertvalue(head,ro,co,value);
    }

    int row1,col1;
    printf("enter row and col\t");
    scanf("%d %d",&row1,&col1);
    for(int i=0;i<row1;i++){
    for(int j=0;j<col1;j++){
    head=insertNode(head1,i,j,0);
    }
    }
    int n1;
    printf("enter n\t");
    scanf("%d",&n1);
    printf("enter non-zeros elements\n");
    for(int i=0;i<n1;i++){
        int ro,co,value;
        printf("Enter row, col and value: \n");
        scanf("%d %d %d",&ro,&co,&value);
        head=insertvalue(head,ro,co,value);
    }
    int r1,c1;
    r1=(row>row1) ?row : row1;
    c1=(col>col1) ?col : col1;
    printf("sparse matrix A\n");
    print(head,row,col);
     printf("sparse matrix B\n");
    print(head1,row1,col1);
    printf("\n");
    add(head,head1,r1,c1);
    print(head3,r1,c1);
    return 0;
}