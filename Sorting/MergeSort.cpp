
#include <iostream>


using namespace std;

void Merge(int A[], int low, int mid, int high){
    int i = low;
    int j = mid+1;
    int k = low;
    int B[high+1];
    while (i <= mid && j <= high){
        if (A[i] < A[j]){
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }
    while (i <= mid){
        B[k++] = A[i++];
    }
    while (j <= high){
        B[k++] = A[j++];
    }
    for (int i=low; i<=high; i++){
        A[i] = B[i];
    }
}

void MergeSort(int A[], int n){
    int l, mid, h, p;
    //first for loop for passes
    for( p = 2; p <=n;p = p * 2){
        //note that h = i+p-1, so h<n
        for(int i = 0;i+p-1<n;i=i+p){
            l = i;
            h = i+p-1;
            mid  = (h+l)/2;
            Merge(A, l, mid, h);
    }
    }
    if(p/2<n){
        Merge(A, 0, p/2, n-1);
    }
}

int main(){
    int A[]={2, 5, 8, 12, 3, 6, 7, 10};
    for(int i = 0; i < 8;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
     MergeSort(A, 8);
     for(int i = 0; i < 8;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
