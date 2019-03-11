#include<iostream>
#include<fstream>
using namespace std;

typedef struct Node {
    int data;
    struct Node *prev, *next;
} NODE;

typedef struct List{
    NODE* first;
    NODE* last;
} LIST;

void init(LIST &l){
    l.first = l.last = NULL;
}

NODE* getNode(int data){
    NODE* newNode = new NODE;
    
    if(newNode!= NULL){
        newNode->data = data;
        newNode->next=newNode->prev=NULL;
    }
    
    return newNode;
}

void addFirst(LIST &l,NODE *x){
    if(l.first == NULL){
        l.first = l.last =x;
    }else{
        x->next=l.first;
        l.first->prev = x;
        l.first = x;
    }
}

void swap(int &a,int &b){
    int t = a;
    a = b;
    b = t;
}

void printList(LIST l){
    NODE* p;
    p = l.first;
    while (p != NULL) {
        cout<<" "<<p->data;
        p = p->next;
    }
    cout<<endl;
}

void readData(ifstream &FileIn,LIST &l){
    NODE* p;
    int temp;
    while(!FileIn.eof()){
        FileIn >> temp;
        p = getNode(temp);
        addFirst(l, p);
    }
}

void shakerSort(LIST &l){
    NODE* k = NULL;
    NODE *left = l.first;
    NODE* right = l.last;
    
    while (left != right) {
        for(NODE* p = left;p!=right;p=p->next){
            if(p->data > p->next->data){
                swap(p->data,p->next->data);
                k = p;
            }
        }
        right = k;
        for (NODE* p = right; p != left; p = p->prev) {
            if(p->data < p ->prev->data){
                swap(p->data,p->prev->data);
                k = p;
            }
        }
        left = k;
    }
}

int main()
{
    ifstream FileIn;
    LIST l;
    
    FileIn.open("INPUT.txt", ios_base::in);
    
    if(!FileIn){
        cout<<"Khong ton tai file INPUT.txt. Vui long kiem tra lai\n";
        system("pause");
        return 0;
    }
    
    init(l);
    readData(FileIn, l);
    cout<<"Mang truoc khi sap xep: \n";
    printList(l);
    shakerSort(l);
    cout<<"Mang sau khi sap xep: \n";
    printList(l);
    
    system("pause");
    return 0;
}
