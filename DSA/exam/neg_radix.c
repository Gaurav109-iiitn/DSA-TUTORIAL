#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head=NULL;

struct node* create(struct node* head,int data){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    if(head==NULL){
    head=temp;
    }
    else{
        struct node* curr=head;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=temp;
    }
    return head;
}

void print(struct node* h){
    struct node* temp=h;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int max(int a[],int n){
    if(n==0) return 0;
    int mx=a[0];
    for(int i=0;i<n;i++){
        if(mx<a[i])
        mx=a[i];
    }
    return mx;
}
void count_sort(int a[],int r[],int n){
    if(n==0) return;
    int* freq=(int*)calloc(10, sizeof(int));
    int* out=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
freq[r[i]]++;
    }
    for(int i=1;i<10;i++){
        freq[i]+=freq[i-1];
    }
    for(int i=0;i<n;i++){
        out[freq[r[i]]-1]=a[i];
        freq[r[i]]--;
    }
    for(int i=0;i<n;i++){
        a[i]=out[i];
    }
    free(out);
    free(freq);
}

struct node* radix(struct node* head,int n){
    struct node* temp=head;
    int* a=(int*)malloc(n*sizeof(int));
     int* b=(int*)malloc(n*sizeof(int));
     int* c=(int*)malloc(n*sizeof(int));
     int* d=(int*)malloc(n*sizeof(int));
     int i=0,j=0;
     while(temp!=NULL){
        if(temp->data>=0){
            a[i]=temp->data;
            b[i]=temp->data;
            i++;
        }
        else{
            c[j]=-temp->data;
            d[j]=-temp->data;
            j++;
        }
        temp=temp->next;
     }
     int mx1=max(a,i);
     int mx2=max(c,j);
     int digit1=0,digit2=0;
     while(mx1>0){
        digit1++;
        mx1/=10;
     }
      while(mx2>0){
        digit2++;
        mx2/=10;
     }
     int div1=1,div2=1;
     for(int p=0;p<digit1;p++){
        int* r=(int*)malloc(n*sizeof(int));
        for(int k=0;k<i;k++){
        r[k]=(a[k]/div1)%10;
        }
        count_sort(b,r,i);
        for(int o=0;o<i;o++){
            a[o]=b[o];
        }
        div1*=10;
        free(r);
     }
     for(int p=0;p<digit2;p++){
        int* r1=(int*)malloc(n*sizeof(int));
        for(int k=0;k<j;k++){
        r1[k]=(c[k]/div2)%10;
        }
        count_sort(d,r1,j);
        for(int o=0;o<j;o++){
            c[o]=d[o];
        }
        div2*=10;
        free(r1);
     }
     temp=head;
     for(int k=j-1;k>=0;k--){
temp->data=-d[k];
temp=temp->next;
     }
for(int k=0;k<i;k++){
temp->data=b[k];
temp=temp->next;
     }

     free(a);
     free(b);
     free(c);
     free(d);

return head;
}
int main(){
     int n;
    printf("enter n\t");
    scanf("%d",&n);
     for(int i=0;i<n;i++){
        int data;
        scanf("%d",&data);
        head=create(head,data);
    }
print(head);
printf("\n");
head=radix(head,n);
print(head);
    return 0;
}