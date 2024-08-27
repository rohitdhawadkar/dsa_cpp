#include <iostream>
#include <algorithm>

void mergeSort(int array[],int low,int high);
void merge(int array[],int low,int high,int mid);
int main(){
    int array[10] = {77,23,45,88,91,20,47,39,30,199};
    mergeSort(array,0,9);
    for(int i=0;i<10;i++){
        std::cout<<array[i]<<" ";
    }
    std::cout<<std::endl;
    return 0;
}


void mergeSort(int array[],int low,int high){
    if(low<high){
        int mid = low + (high - low)/2;
        mergeSort(array, low,mid);
        mergeSort(array,mid+1,high);
        merge(array,low,high,mid);
    }
}

void merge(int array[],int low,int high,int mid){
    int leftSize = mid - low+1;
    int rightSize = high - mid;

    int *leftArray= new int[leftSize];
    int *rightArray = new int[rightSize];
    for (int i = 0; i < leftSize; i++)
            leftArray[i] = array[low + i];
        for (int j = 0; j < rightSize; j++)
            rightArray[j] = array[mid + 1 + j];

    int i=0,j=0,k=low;

    while(i<leftSize && j<rightSize){
        if(leftArray[i]<rightArray[j]){
            array[k] = leftArray[i];
            i++;
            k++;
        }
        if(rightArray[j]<leftArray[i]){
            array[k]=rightArray[j];
            j++;
            k++;
        }
    }

    while(i<leftSize){
        array[k]=leftArray[i];
        i++;
        k++;
    }

while (j<rightSize) {
    array[k]=rightArray[j];
    j++;
    k++;
}
delete [] leftArray;
delete [] rightArray;

}
