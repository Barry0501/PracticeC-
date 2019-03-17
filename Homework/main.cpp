#include<iostream>
#include<fstream>
using namespace std;

typedef struct Node{
    int data;
    Node* link;
}NODE;

typedef struct List{
    NODE* first;
    NODE* last;
}LIST;

NODE* GetNode(int x){
    NODE *p;
    p = (NODE*)malloc(sizeof(NODE));
    
    if(p == NULL){
        cout<<"Khong du bo nho\n";
        exit(1);
    }
    
    p->data = x;
    p->link = NULL;
    
    return p;
}

void init(LIST &l){
    l.first = l.last = NULL;
}

void addLast(LIST &l,NODE* newNODE){
    if(l.first == NULL){
        l.first = newNODE;
        l.last = l.first;
    }else{
        l.last->link=newNODE;
        l.last=newNODE;
    }
}

void readData(ifstream &FileIn,LIST &l){
    int Temp;
    NODE *p;
    
    while (!FileIn.eof()) {
        FileIn >> Temp;
        p = GetNode(Temp);
        addLast(l, p);
    }
}

void printList(LIST l){
    NODE *p;
    p = l.first;
    while (p!=NULL) {
        cout<< " "<<p->data;
        p=p->link;
    }
    cout<<endl;
}

void quickSortList(LIST &l){
    NODE *X, *p;
    LIST l1, l2;
    
    if(l.first == l.last){
        return;
    }
    
    init(l1);
    init(l2);
    
    X = l.first;
    l.first = X->link;
    
    while(l.first != NULL){
        p = l.first;
        l.first=p->link;
        p->link = NULL;
        if(p->data<=X->data){
            addLast(l1, p);
        }else{
            addLast(l2, p);
        }
    }
    quickSortList(l1);
    quickSortList(l2);
    
    if(l1.first != NULL){
        l.first = l1.first;
        l1.last->link=X;
    }else{
        l.first = X;
    }
    if(l2.first != NULL){
        X->link = l2.first;
        l.last=l2.last;
    }else{
        l.last = X;
    }
}

int main()
{
    ifstream FileIn;
    LIST l;
    
    FileIn.open("INPUT.txt",ios_base::in);
    if(!FileIn){
        cout<<"Tap tin INPUT.txt khong ton tai\n";
        system("pause");
        return 0;
    }
    init(l);
    readData(FileIn, l);
    cout<<"Danh sach truoc khi sap xep: \n";
    printList(l);
    quickSortList(l);
    cout<<"\nMang luc sau:";
    printList(l);
    FileIn.close();
    system("pause");
    return 0;
}
