#include<iostream>
#include<fstream>
using namespace std;

void REALLOC(int *&a,int newSize,int oldSize){
    int *b = new int[oldSize];
    
    for(int i = 0;i<oldSize;++i){
        b[i] = a[i];
    }
    
    delete []a;
    
    int Min = oldSize < newSize ? oldSize : newSize;
    
    a = new int[newSize];
    
    for(int i = 0;i<Min;++i){
        a[i] = b[i];
    }
    
    delete [] b;
}


void addData(int *&a,int &n,int data){
    REALLOC(a, n+1, n);
    a[n] = data;
    n++;
}

void readData(ifstream &FileIn ,int *&a,int &count){
    FileIn.open("INPUT.txt",ios_base::in);
    int Temp;
    while (!FileIn.eof()) {
        FileIn >> Temp;
        addData(a, count, Temp);
    }
}

void printArray(int *a,int count){
    for(int i = 0;i<count;++i){
        cout<< " "<<a[i];
    }
    cout<<endl;
}

void swap(int &a,int &b){
    int Temp = a;
    a = b;
    b = Temp;
}

void shift(int *&a,int l,int r){
    int x,i,j;
    i = l;
    j = 2*i;
    x = a[i];
    while (j<=r) {
        if(j<r){
            if(a[j] > a[j+1]){
                j++;
            }
            if(a[j] > x){
                break;
            }else{
                swap(a[i], a[j]);
                i++;
                j = 2*i;
                x = a[i];
            }
        }else{
            if(a[j] < x){
                swap(a[i], a[j]);
                i++;
                j = 2*i;
                x=a[i];
            }else{
                i++;
                j = 2*i;
                x=a[i];
            }
        }
    }
}

void createHeap(int *&a,int n){
    int l= n/2;
    
    while(l >= 0){
        shift(a, l, n);
        l-=1;
    }
}

void heapSort(int *&a,int n){
    int r;
    createHeap(a, n);
    r = n -1;
    while(r >= 0){
        createHeap(a, r);
        swap(a[0], a[r]);
        r--;
    }
}

int main()
{
    ifstream FileIn;
    int *a;
    int count = 0;
    
    if(!FileIn){
        cout<<"Tap tin INPUT.txt khong ton tai. Xin kiem tra lai!!";
        system("pause");
        return 0;
    }
    readData(FileIn, a, count);
    
    cout<<"Mang truoc khi sap xep: \n";
    printArray(a, count);
    heapSort(a,count);
    cout<<"Mang sau khi sap xep: \n";
    printArray(a, count);
    FileIn.close();
    system("pause");
    return 0;
}
