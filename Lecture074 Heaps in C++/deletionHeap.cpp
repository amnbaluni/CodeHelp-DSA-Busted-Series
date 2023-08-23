void delete(){
  if(size == ){
    cout<<"nothing to delete"<<endl;
    return;
  }

  //step1 : swap first and last node
  arr[1] = arr[size];

  //step2 : remove last node
  size--;
  
  //step3: take root to its correct position
  int i = 1;
  while(i<size){
      int leftIndex = 2*i;
      int rightIndex = 2*i + 1;
      if(leftIndex < size && arr[i] < arr[leftIndex]){
          swap(arr[i], arr[leftIndex]);
          i = leftIndex;
      }
      else if(rightIndex < size && arr[i] < arr[rightIndex])
          swap(arr[i], arr[rightIndex]);
          i = rightIndex;
      }
      else{
          return;
      }
                     
  }
  

