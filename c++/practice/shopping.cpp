#include<iostream>
using namespace std;
const int m=50;

class items{
    int itemcode[m];
    int itemprice[m];
    int count;
    public:

    void geta(){
        count=0;
    }

    void getitem();
    void displaysum();
    void remove();
    void show();
};
void items::getitem(){
cout<<"enter item code and item price"<<endl;
cin>>itemcode[count]>>itemprice[count];
count++;
}
void items::displaysum(){
    int sum=0;
    for(int i=0;i<count;i++){
        sum+=itemprice[i];
    }
    cout<<endl<<"total price ="<<sum<<endl;
}
void items::remove(){
    int a;
    cout<<"enter item code"<<endl;
    cin>>a;
    for(int i=0;i<count;i++){
        if(itemcode[i]==a){
            itemprice[i]=0;
        }
    }
}
void items::show(){
    cout<<"********* your bill **********"<<endl;
    for(int i=0;i<count;i++){
        cout<<itemcode[i]<<"  "<<itemprice[i];
    }
    displaysum();
}
int main(){
    items order;
    int x;
    order.geta();
    do{
        cout<<"1 for add item\n 2 for display sum \n 3 for delete item \n 4 for display all items\n 5 for quit"<<endl;
    cin>> x;
    switch(x){
        case 1 :order.getitem();break;
        case 2 :order.displaysum();break;
        case 3 :order.remove();break;
        case 4 :order.show(); break;
        case 5 :break;
    }
    }
    while(x!=5);
    return 0;
}