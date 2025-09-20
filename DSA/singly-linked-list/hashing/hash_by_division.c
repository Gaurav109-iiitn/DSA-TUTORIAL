#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define size 10

typedef struct node{
int key;
char* value;
struct node* next;
}Node;

Node* hashtable[size];

int hash_function(int key){
    return key%size;
}

Node* create(int key,char* value){
Node* newnode=(struct node*)malloc(sizeof(struct node));
newnode->key=key;
newnode->value=strdup(value);
newnode->next=NULL;
return newnode;
}

void insert(int key,char* value){
int index=hash_function(key);
Node* newnode=create(key,value);
if(hashtable[index]==NULL){
hashtable[index]=newnode;
}
else{
     Node* temp=hashtable[index];
    while(temp->next!=NULL)
    temp=temp->next;
    temp->next=newnode;
}
}

char* search(int key){
    int index=hash_function(key);
    Node* curr=hashtable[index];
    while(curr!=NULL){
        if(curr->key==key){
            return  curr->value;
        }
        curr=curr->next;
    }
    return NULL;
}

void display(){
    for(int i=0;i<size;i++){
        printf("Index %d: ",i);
       if(hashtable[i]!=NULL){
       Node* temp=hashtable[i];
       while(temp!=NULL){
       printf("(%d, %s) -> ",temp->key,temp->value);
       temp=temp->next;
       } 
       printf("NULL\n");
       } 
       else{
        printf("content is empty\n");
       }
    }
}

int main(){
    for(int i=0;i<size;i++){
        hashtable[i]=NULL;
    }
int n;
printf("enter n\n");
scanf("%d",&n);
for(int i=0;i<n;i++){
    int key;
    char value[100];
    printf("enter key and value\n");
    scanf("%d %s",&key,&value);
    insert(key,value);
}
display();
int key;
printf("enter key\n");
scanf("%d",key);
printf("%s\n",search(key));

return 0;
}
