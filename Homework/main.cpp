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
    REALLOC(a, n +1 , n);
    a[n]= data;
    n++;
}

void readData(ifstream &FileIn,int *&a,int &count){
    int Temp;
    while (!FileIn.eof()) {
        FileIn >> Temp;
        addData(a, count, Temp);
    }
}

void printArray(int *a,int count){
    for(int i = 0;i<count;++i){
        cout<<" "<<a[i];
    }
    cout<<endl;
}

void swap(int &a,int &b){
    int Temp = a;
    a = b;
    b = Temp;
}

void shakerSort(int *&a,int count){
    int left = 0;
    int right = count - 1;
    int k = 0;
    while (left < right) {
        for (int i = left; i < right; i++) {
            if(a[i] > a[i+1]){
                swap(a[i], a[i+1]);
                k = i;
            }
        }
        right = k;
        for(int i = right; i> left;i--){
            if(a[i] < a[i-1]){
                swap(a[i], a[i-1]);
                k = i;
            }
        }
        left = k;
    }
}

int main()
{
    ifstream FileIn;
    int *a;
    int count = 0;
    
    
    FileIn.open("INPUT.txt",ios_base::in);
    if(!FileIn){
        cout<<"Tap tin INPUT.txt khong ton tai"<<endl;
        system("pause");
        return 0;
    }
    readData(FileIn, a, count);
    cout<<"Mang ban dau chua sap xep: \n";
    printArray(a, count);
    shakerSort(a,count);
    cout<<"Mang sau khi sap xep: \n";
    printArray(a, count);
    
    system("pause");
    return 0;
}
