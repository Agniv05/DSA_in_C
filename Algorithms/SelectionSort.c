void selectionSort(int *A,int size){

  int minIndex=0,key;
  for (int i=0;i<=size-1;i++){ //Loop for each pass
    minIndex=A[i];
    for (int j=i;j<=size-1;j++){
      if (A[j]<minIndex){
        minIndex=A[j];
        key=j;
    }
  }
    A[i]=A[key]+A[i];//swap
    A[key]=A[i]-A[key];
    A[i]=A[i]-A[key];
 }
  
}
