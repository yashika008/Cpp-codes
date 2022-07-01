#include<iostream>
using namespace std;
void swap(int *a, int* b){
    int temp = *a;
       *a = *b;
       *b = temp;
}
//choosing first element as pivot
int Partition(int A[], int l, int h){
    int pivot = A[l];
    int i = l;
    int j = h;
    do{
        //increment i as long as the elements are smaller thean pivot
    do{i++;}while( A[i]<=pivot);
    //Decrement j as long as the elements are larger than pivot
    do{j--;} while(A[j]>pivot);
    if(i<j) swap(&A[i], &A[j]);}
    while (i < j);
 
    swap(&A[l], &A[j]);
    return j;
}
 
void QuickSort(int A[],int low, int high){
if(low < high){
    int j = Partition(A, low, high);
    QuickSort(A, low,j);
    QuickSort(A, j+1, high);
}
}

int main(){
    int A[]={9,8,1,3,6,8,3};
    int n = sizeof(A)/sizeof(A[0]);
    for(int i = 0;i < n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    QuickSort(A, 0, n);
    for(int i = 0;i < n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}