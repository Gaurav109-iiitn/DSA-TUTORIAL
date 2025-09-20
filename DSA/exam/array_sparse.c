#include<stdio.h>
#include<stdlib.h>
void pr(int row,int col,int a[row][col]){
   for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
    printf("%d\t",a[i][j]);
            }
printf("\n");
        }
    } 
int main(){
    int row,col;
    printf("enter row and col");
    scanf("%d %d",&row,&col);
    int a[row][col];
for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            a[i][j]=0;
        }
    }

    int n;
    printf("no of elements you want to enter");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int pos1,pos2,val;
        printf("enter its location and value ");
        scanf("%d %d %d",&pos1,&pos2,&val);
        a[pos1][pos2]=val;
    }
    
    pr(row,col,a);
    return 0;
}