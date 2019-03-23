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

void readData(ifstream &FileIn,LIST &l,int &n){
    NODE* p;
    int temp;
    while(!FileIn.eof()){
        FileIn >> temp;
        p = getNode(temp);
        addFirst(l, p);
        n++;
    }
}

int findLocation(LIST l, int n, int x) {
	NODE* p = new NODE;
	p = l.first;
	int count = 0;
	while(p->data!= x) {
		count++;
		p = p->next;
		if (count > n)
		{
			return -1;
		}
	}
	return count;
}

int min(int a, int b) {
	// if (a <= b)
	// 	return a;
	// return b;
    return a <= b ? a : b;
}

void merge(LIST &l, int temp1[], int n1, int temp2[], int n2, int k)
{
	int i1, i2, i;
	int k1, k2;
	int j1, j2;
	i = i1 = i2 = 0;
	j1 = j2 = 0;
	NODE* p = new NODE;
	p = l.first;
	while (n2 > 0 && n2 > 0)
	{
		// xác định độ dài từng dãy
		k1 = min(k, n1);
		k2 = min(k, n2);

		// xét và trộn dãy con vào dãy
		if (temp1[i1 + j1] < temp2[i2 + j2])
		{
			l.first->data = temp1[i1 + j1];
			j1++;
			l.first = l.first->next;
			// trộn dãy con còn lại vào dãy
			if (j1 == k1)
			{
				for (; j2 < k2; j2++) {
					l.first->data = temp2[i2 + j2];
					l.first = l.first->next;
				}
				i1 += k1; i2 += k2;
				j1 = j2 = 0;
				n1 -= k1; n2 -= k2;
			}
		}
		else
		{
			l.first->data = temp2[i2 + j2];
			j2++;
			l.first = l.first->next;
			// trộn dãy con còn lại vào dãy
			if (j2 == k2)
			{
				for (; j1 < k1; j1++) {
					l.first->data = temp1[i1 + j1];
					l.first = l.first->next;
				}
				i1 += k1; i2 += k2;
				j1 = j2 = 0;
				n1 -= k1; n2 -= k2;
			}
		}
	}
	l.first = p;
}

void mergeSort(LIST &l,int n)
{
	int n1, n2;
	int i;
	int k;
	int ik;
	int *temp1 = new int[n];
	int *temp2 = new int[n];
	k = 1;
	NODE* p = new NODE;
	do
	{
		i = n1 = n2 = 0;
		p = l.first;
		// chia mảng ra 2 mảng phụ
		while (i < n)
		{
			ik = 0;

			while (ik < k && i < n)
			{
				if (p != NULL) {
					temp1[n1++] = p->data;
					p = p->next;
				}
				ik++;
				i++;
			}

			ik = 0;

			while (ik < k && i < n)
			{
				if (p != NULL) {
					temp2[n2++] = p->data;
					p = p->next;
				}
				i++;
				ik++;
			}
		}

		merge(l,temp1, n1, temp2, n2, k);

		// tăng độ lớn tối đa dãy con
		k *= 2;
	} while (k < n);

	delete[] temp1;
	delete[] temp2;
}


int main()
{
    ifstream FileIn;
    LIST l;
    int n = 0;
    
    FileIn.open("INPUT.txt", ios_base::in);
    
    if(!FileIn){
        cout<<"Khong ton tai file INPUT.txt. Vui long kiem tra lai\n";
        system("pause");
        return 0;
    }
    
    init(l);
    readData(FileIn, l, n);
    cout<<"Mang truoc khi sap xep: \n";
    printList(l);
    mergeSort(l,n);
    cout<<"Mang sau khi sap xep: \n";
    printList(l);
    FileIn.close();
    system("pause");
    return 0;
}
