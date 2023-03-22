#include <iostream>

using namespace std;

template <class T>

void print(T& vec , int n , string s){
    cout << s << ": [" << flush;
    for(int i = 0 ; i < n ; i++){
        cout << vec[i] << flush;
        if(i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}

void swap(int* x , int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}


// Quick Sort using INT_MAX or INFINITY
int partitionA(int A[] , int low , int high){
    int pivot = A[low];
    int i = low;
    int j = high;

    do{
        // increment i as long as elements are smaler/equal to pivot
        do{i++;}while(A[i] <= pivot);

        // decrement j as long as elments are larger than pivot
        do{j--;}while(A[j] > pivot);
        if(i < j){
            swap(&A[i], &A[j]);
        }
    }while(i < j);
    swap(&A[low] , &A[j]);
    return j;
}

void quickSortA(int A[] , int low , int high){
    if(low < high){
        int j = partitionA(A,  low,  high);
        quickSortA(A , low , j);
        quickSortA(A, j + 1,  high);
    }
}

// Last Element is pivot + without using INT_MAX or INFINITY

int partitionLast(int A[] , int low , int high){
    int pivot = A[high];
    int i = low -1;
    for(int j = low ; j <= high -1 ; j++){
        if(A[j] < pivot){
            i++;
            swap(&A[i] , &A[j]);
        }
    }
    swap(&A[i +1] , &A[high]);
    return i +1;
}

void quickSortLast(int A[] , int low , int high){
    if( low < high){
        int p = partitionLast(A, low, high);
        quickSortLast(A, low, p -1);
        quickSortLast(A, p +1, high);
    }
}


// First Element is pivot + without using INT_MAX or INFINITY
int partition(int A[] , int low , int high){
    int piovt = A[low];
    int i = low + 1;
    int j = high;
    while(true){
        while(i <= j && A[i] <= piovt){i++;}
        while(A[j] >= piovt && j >= i){j--;}
        if(j < i){
            break;
        }
        else{
            swap(&A[i] , &A[j]);
        }
    }
    swap(&A[low], &A[j]);
    return j;
}


void quickSort(int A[] , int low , int high){
    if(low < high){
        int p = partition(A, low, high);
        quickSort(A, low, p -1);
        quickSort(A, p +1, high);
    }
}


int main() {

    cout << "Using INT_MAX or Infinity" << endl;

    int A[] = {3 , 7 , 9 , 10 , 6 , 5 , 12 , 4 , 11 , 2 , 32767};
    int n = sizeof(A)/sizeof(A[0]);
    print(A , n -1 , "\t\tA");


    quickSortA(A, 0, n-1);
    print(A, n -1, "Sorted A");
    cout << endl;

    cout << "Last Element as pivot + w/o INT_MAX pr Infnity" << endl;
    int B[] = {11 , 13 , 7 ,12 , 16 , 9 , 24 , 5 , 10 , 3};
    print(B, sizeof(B)/sizeof(B[0]), "\t\tB");

    quickSortLast(B, 0, sizeof(B)/sizeof(B[0]) -1);
    print(B, sizeof(B)/sizeof(B[0]), "Sorted B");
    cout << endl;


    cout << "First Element as pivot + w/o INT_MAX or Infinity" << endl;
    int C[] = {11 , 13 , 7 , 12 , 16 , 9 , 24 , 5 , 10 , 3};
    print(C, sizeof(C)/sizeof(C[0]), "\t\tC");

    quickSort(C, 0, sizeof(C)/sizeof(C[0])-1);
    print(C, sizeof(C)/sizeof(C[0]), "Sorted C");







    return 0;
}