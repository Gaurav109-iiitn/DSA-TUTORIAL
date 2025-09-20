#include<iostream>
#include<cstring>
using namespace std;

const int IN=1;
const int out=0;

class book{
    char author[20];
    char title[20];
    int status;
    public:
    book(char* n,char* t,int s);
    int get_status(){
        return status;
    }
    void set_status(int s){
        status=s;
    }
    void show();
};

book::book(char* n,char* t,int s){
    strcpy(author,n);
    strcpy(title,t);
    status=s;
}

void book::show(){
cout<<title<<"by"<<author<<"\t";
cout<<"is\t";
if(status==IN){
    cout<<"in\n";
}
else cout<<"out\n";
}

int main(){
    book b1("twain","tom slayer",IN);
    book b2("ram","radha",out);
    b1.show();
    b2.show();
    return 0;
}