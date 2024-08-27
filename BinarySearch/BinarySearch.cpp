#include <iostream>

int BinarySearch(int target, int array[], int size);
int AgnosticBinarySearch(int target,int array[],int size);

int RecursiveBinarySearch(int target,int array[],int low,int high);

int AgnosticRecursiveBinarySearch(int target,int array[],int low,int high);

int main() {
    int array[] = {17, 21, 37, 53, 91, 105, 201, 255, 377, 405};
    int array2[] = {100,97,77,63,57,49,39,31,25,17};
    int size = sizeof(array) / sizeof(array[0]);
    int answer = BinarySearch(105, array, size);
    int answer2 = RecursiveBinarySearch(11,array,0,size-1);
    int answer3 = AgnosticBinarySearch( 255, array,  size);
    int answer4 = AgnosticBinarySearch(39,array2,10);
    int answer5 = AgnosticRecursiveBinarySearch(39,array2,0,size-1);
    std::cout << answer << std::endl;
    std::cout << answer2 << std::endl;
    std::cout << answer3 << std::endl;
    std::cout << answer4 <<std::endl;
    std::cout<< answer5<<std::endl;
    return 0;
}

int BinarySearch(int target, int array[], int size) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (target == array[mid]) {
            return mid;
        } else if (target > array[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int RecursiveBinarySearch(int target,int array[],int low,int high){
    if(low>high){
        return -1;
    }
    int mid = low + (high-low)/2;

    if(target==array[mid]){
        return mid;
    }else if(target>array[mid]){
            return RecursiveBinarySearch(target,array,mid+1,high);
    }else{
            return RecursiveBinarySearch(target,array,low,mid-1);
     }


}

int AgnosticBinarySearch(int target,int array[],int size){
    int low = 0;
    int high = size - 1;
    if(array[low]<array[high]){
        while(low<=high){
            int mid = low + (high-low)/2;
            if(target==array[mid]){
                return mid;
            }else if(target>array[mid]){
                low = mid + 1;
            }else {
                high = mid - 1;
            }
        }

    }

    if(array[low]>array[high]){
        while(low<=high){
            int mid = low+ (high-low)/2;
            if(target==array[mid]){
                return mid;
            }else if(target>array[mid]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
    }
    return -1;

}

int AgnosticRecursiveBinarySearch(int target, int array[], int low, int high) {
    if (low > high) {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (target == array[mid]) {
        return mid;
    }

    if (array[low] < array[high]) { // Ascending order
        if (target < array[mid]) {
            return AgnosticRecursiveBinarySearch(target, array, low, mid - 1);
        } else {
            return AgnosticRecursiveBinarySearch(target, array, mid + 1, high);
        }
    } else { // Descending order
        if (target > array[mid]) {
            return AgnosticRecursiveBinarySearch(target, array, low, mid - 1);
        } else {
            return AgnosticRecursiveBinarySearch(target, array, mid + 1, high);
        }
    }
}
