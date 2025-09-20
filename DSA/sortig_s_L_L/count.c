#include<stdio.h>
#include<stdlib.h>

void count(int a[],int n){
    int mx=a[0];
    for(int i=0;i<n;i++){
        if(a[i]>mx){
            mx=a[i];
        }
    }
    int* freq=(int*)calloc(mx+1,sizeof(int)); // to initialize its initial value 0
for(int i=0;i<n;i++){
   freq[a[i]]++; 
}
for(int i=1;i<=mx;i++){
freq[i]+=freq[i-1];
}
int* out=(int*)malloc(n*sizeof(int));
for(int i=n-1;i>=0;i--){
    out[freq[a[i]]-1]=a[i];
    freq[a[i]]--;
}
for(int i=0;i<n;i++){
    a[i]=out[i];
}
free(freq);
free(out);
}

int main(){
    int a[]={1,2,1,3,6,4,1,2,3,5,3,8,7,6,9,0,8,7,9,0};
int n=sizeof(a)/sizeof(a[0]);
    count(a,n);
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    return 0;
}