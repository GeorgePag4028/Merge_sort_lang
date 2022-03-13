class merge_sort {
    void merge(int array[], int begin , int mid, int end){
      int left_array_size = mid - begin +1;
      int right_array_size = end - (mid +1) +1;

      int left_array[] = new int[left_array_size];
      int right_array[] = new int[right_array_size];


      for (int i =0 ; i<left_array_size;i++) left_array[i] = array[begin+i];
      for (int j =0 ; j<right_array_size;j++) right_array[j] = array[mid+1+j];


      int i = 0, j = 0;
      int k = begin;

      while (i < left_array_size && j < right_array_size) {
            if (left_array[i] <= right_array[j]) {
                array[k] = left_array[i];
                i++;
            }
            else {
                array[k] = right_array[j];
                j++;
            }
            k++;
        }
  
        while (i < left_array_size) {
            array[k] = left_array[i];
            i++;
            k++;
        }
  
        while (j < right_array_size) {
            array[k] = right_array[j];
            j++;
            k++;
        }
    }
    void mergeSort(int array[], int begin ,int end){
      if (begin >= end) return;
    
      int mid = begin + (end-begin)/2;

      mergeSort(array,begin, mid);
      mergeSort(array,mid+1,end);
      merge(array,begin,mid,end);
    }
    
    static void printArray(int arr[])
    {
        int n = arr.length;
        for (int i = 0; i < n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }

    public static void main(String[] args) {
        int array[] = { 12, 11, 13, 5, 6, 7 };
  
        System.out.println("Given Array");
        printArray(array);
  
        merge_sort ob = new merge_sort();
        ob.mergeSort(array, 0, array.length - 1);
  
        System.out.println("\nSorted array");
        printArray(array);
    }
}
