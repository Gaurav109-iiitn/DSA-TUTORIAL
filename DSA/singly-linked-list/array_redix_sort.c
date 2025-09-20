#include<stdio.h>
#include<stdlib.h>
void pr(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
int mx(int a[],int n){
    int mx=a[0];
    for(int i=0;i<n;i++){
        if(a[i]>mx){
            mx=a[i];
        }
    }
    int k=0;
    while(mx>0){
        k++;
        mx=mx/10;
    }
    return k;
}
void sort(int a[], int rem[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (rem[j] > rem[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                int t = rem[j];
                rem[j] = rem[j + 1];
                rem[j + 1] = t;
            }
        }
    }
    pr(a, n);
}
void radix(int a[], int n) {
    int k = mx(a, n);
    int rem[n], out[n], o1[n];
    for (int i = 0; i < n; i++) {
        o1[i] = a[i];
    }
    int divisor = 1;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            rem[j] = (o1[j] / divisor) % 10;
        }
        sort(o1, rem, n);
        divisor *= 10;
    }
    for (int i = 0; i < n; i++) {
        a[i] = o1[i];
    }
}
void input(int n,int a[]){
    for(int i=0;i<n;i++){
        printf("enter %d:",i);
        scanf("%d",&a[i]);
    }
}
int main(){
    int n;
    printf("enter n");
    scanf("%d",&n);
    int a[n];
    input(n,a);
    pr(a,n);
    printf("\n");
    radix(a,n);
    return 0;
}