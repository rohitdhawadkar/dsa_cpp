#include <iostream>
#include <cstdlib>

// Function prototypes
int* mergeSort(int* array, int start, int end);
int* merge(int* left, int leftSize, int* right, int rightSize);

int main() {
    int array[] = {5, 4, 3, 2, 1};
    int size = sizeof(array) / sizeof(array[0]);

    // Call mergeSort and store the result in ans
    int* ans = mergeSort(array, 0, size - 1);

    // Print the sorted array
    std::cout << "[";
    for (int i = 0; i < size; i++) {
        std::cout << ans[i];
        if (i < size - 1)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    // Free the allocated memory for the result array
    delete[] ans;

    return 0;
}

// MergeSort function
int* mergeSort(int* array, int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;

        int* left = mergeSort(array, start, mid);
        int leftSize = mid - start + 1;

        int* right = mergeSort(array, mid + 1, end);
        int rightSize = end - mid;

        return merge(left, leftSize, right, rightSize);
    } else {
        int* baseCase = new int[1];
        baseCase[0] = array[start];
        return baseCase;
    }
}

// Merge function
int* merge(int* left, int leftSize, int* right, int rightSize) {
    int* result = new int[leftSize + rightSize];
    int i = 0, j = 0, k = 0;

    while (i < leftSize && j < rightSize) {
        if (left[i] < right[j]) {
            result[k] = left[i];
            i++;
        } else {
            result[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        result[k] = left[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        result[k] = right[j];
        j++;
        k++;
    }

    delete[] left;
    delete[] right;

    return result;
}
