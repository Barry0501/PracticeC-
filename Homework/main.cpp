#include<iostream>
#include<fstream>
using namespace std;

void REALLOC(int *&a, int oldSize,int newSize){
    int *b = new int[oldSize];
    for(int i = 0;i<oldSize;++i){
        b[i] = a[i];
    }
    
    delete [] a;
    
    a = new int[newSize];
    
    int Min = oldSize < newSize ? oldSize : newSize;
    
    for(int i = 0;i<Min;i++){
        a[i] = b[i];
    }
    
    delete [] b;
}

void addData(int *&a,int &n,int data){
    REALLOC(a, n, n + 1);
    a[n] = data;
    n++;
}

void readData(ifstream &FileIn,int *&a,int &count){
    int Temp;
    while(!FileIn.eof()){
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

void insertionSort(int *&a,int count){
    int j, key;
    for(int i = 1;i<count;++i){
        key = a[i];
        j = i - 1;
        
        while(j >= 0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

//int binarySearch(int *a,int key,int left,int right){
//    if(right <= left){
//        return (key > a[left]) ? (left + 1) : left;
//    }
//    int mid = (left + right) /2;
//    if(key == a[mid])
//        return mid + 1;
//    if(key > a[mid]){
//        return binarySearch(a, key, mid + 1, right);
//    }
//    return binarySearch(a, key, left, mid - 1);
//}
//
//void BinaryInsertionSort(int *&a,int count){
//    int j,key,loc;
//    for(int i = 1;i<count;++i){
//        key = a[i];
//        j = i - 1;
//
//        // find location where selected sould be inseretd
//        loc = binarySearch(a, key, 0, j);
//
//        // Move all elements after location to create space
//        while (j >= loc)
//        {
//            a[j+1] = a[j];
//            j--;
//        }
//        a[j+1] = key;
//    }
//}

int binarySearch(int *a,int key,int left,int right){
    if(right <= left)
        return (key > a[left]) ? (left + 1) : left;
    int mid = (left+right)/2;
    if(a[mid] == key)
        return (mid+1);
    if(key > a[mid]){
        return binarySearch(a, key, mid + 1, right);
    }
    return binarySearch(a, key, left, mid - 1);
}

void binaryInsertionSort(int *&a,int count){
    int j,key, loc;
    for(int i = 1;i<count;++i){
        key = a[i];
        j = i - 1;
        
        loc = binarySearch(a, key, 0, j);
        
        while(j >= loc){
            a[j+1] = a[j];
            j--;
        }
        
        a[j+1] = key;
    }
}

int main()
{
    int *a;
    int count = 0;
    
    ifstream FileIn;
    FileIn.open("INPUT.txt",ios_base::in);
    
    if(!FileIn){
        cout<<"Khong ton tai file INPUT.txt"<<endl;
        system("pause");
        return 0;
    }
    readData(FileIn, a, count);
    
    cout<<"Mang ban dau: \n";
    printArray(a, count);
    int luachon;
    cout<<"--------- Menu lua chon ---------\n";
    cout<<"1. Insertion sort"<<endl;
    cout<<"2. Binary Insertion sort"<<endl;
    cout<<"--------------------------------\n";
    cout<<"Nhap lua chon cua ban: ";
    cin >> luachon;
    if(luachon == 1){
        insertionSort(a,count);
        cout<<"Mang luc sau: \n";
        printArray(a, count);
    }
    else if(luachon == 2){
        binaryInsertionSort(a,count);
        cout<<"Mang luc sau: \n";
        printArray(a, count);
    }
    system("pause");
    return 0;
}
