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

int findPosition(List  l, int  x) {
    int i = 0;
    NODE* p = l.first;
    while (p != NULL && p->data != x) {
        i = i + 1;
        p = p->next;
    }
    return i;
}

NODE* findMiddle(List l, int begin ,int end)
{
    int vitriphantu = (begin + end)/2;
    NODE* middle = l.first;
    for (int i = 0; i < vitriphantu; i++) {
        middle = middle->next;
    }
    return middle;
}


void  binaryInsertionSort(List &l)
{
    NODE* begin;
    NODE* end;
    NODE* middle;
    int value;
    begin = l.first;
    for (NODE* p=l.first->next; p !=NULL; p= p->next)
    {
        value = p->data;
        begin = l.first;
        end = p->prev;
        int vitribegin = findPosition(l, begin->data);
        int vitriend = findPosition(l, end->data);
        int vitrij = findPosition(l, p->prev->data);
        while (vitribegin <= vitriend) {
            middle = findMiddle(l ,vitribegin, vitriend);
            int vitrimiddle = findPosition(l, middle->data);
            if (value < middle->data) {
                end = middle->prev;
                vitriend = vitrimiddle - 1;
            }
            else {
                begin = middle->next;
                vitribegin = vitrimiddle + 1;
            }
        }
        
        Node* j;
        j = p->prev;
        while (vitrij >= vitribegin) {
            vitrij = vitrij - 1;
            j->next->data = j->data;
            j = j->prev;
        }
        begin->data = value;
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
    binaryInsertionSort(l);
    cout<<"Mang sau khi sap xep: \n";
    printList(l);
    FileIn.close();
    system("pause");
    return 0;
}
