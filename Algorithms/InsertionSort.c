#include <stdio.h>

void printArray(int arr[]){
}

void InsertionSort(int *A, int n){
  int key,j;
  for (int i=0;i<=n-1;i++){     //Loop for each pass
    key=A[i];
    j=i-1;
    while (j>=0 && A[j]<key){   //Loop for passes
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=key;
  }
}

int main(){
}
