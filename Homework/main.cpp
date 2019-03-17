#include<iostream>
#include<fstream>
using namespace std;

void REALLOC(int *&a,int NewSize,int OldSize){
    int *b = new int[OldSize];
    for(int i = 0;i<OldSize;++i){
        b[i] = a[i];
    }
    
    delete [] a;
    
    a = new int[NewSize];
    
    int Min = OldSize < NewSize ? OldSize : NewSize;
    
    for(int i = 0;i<Min;++i){
        a[i] = b[i];
    }
    
    delete [] b;
}

void addData(int *&a,int &count,int data){
    REALLOC(a, count + 1, count);
    a[count] = data;
    count++;
}

void readData(ifstream &FileIn,int *&a,int &count){
    FileIn.open("INPUT.txt",ios_base::in);
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

int getMax(int *a,int n){
    int max = a[0];
    
    for(int i=1;i<n;++i){
        if(a[i] > max)
            max = a[i];
    }
    return max;
}

void countSort(int *&a,int n,int exp){
    int output[10];
    int count[10] = {0};
    
    for(int i = 0;i<n;++i){
        count[(a[i]/exp)%10]++;
    }
    
    for(int i = 1;i<10;i++){
        count[i]+=count[i-1];
    }
    
    for(int i = n - 1;i>=0;i--){
        output[count[(a[i]/exp)%10]-1] = a[i];
        count[(a[i] / exp)%10]--;
    }
    
    for(int i = 0;i<n;++i){
        a[i] = output[i];
    }
}

void radixSort(int *&a,int n){
    int max = getMax(a, n);
    for(int i = 1;max/i > 0;i*=10){
        countSort(a, n, i);
    }
}

int main()
{
    ifstream FileIn;
    int *a;
    int count = 0;
    if(!FileIn){
        cout<<"Tap tin file INPUT.txt khong ton tai"<<endl;
        system("pause");
        return 0;
    }
    readData(FileIn, a, count);
    cout<<"Mang truoc khi sap xep: \n";
    printArray(a, count);
    radixSort(a, count);
    cout<<"Mang sau khi sap xep: \n";
    printArray(a, count);
    
    FileIn.close();
    delete [] a;
    system("pause");
    return 0;
}
