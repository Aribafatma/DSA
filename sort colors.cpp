#include <iostream>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortColors(int arr[], int n) {
    int low = 0;
    int high = n - 1;
    int mid = 0;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(&arr[low], &arr[mid]);
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else {
            swap(&arr[mid], &arr[high]);
            high--;
        }
    }
}

int main() {
    // Example 1 input
    int nums1[] = {2, 0, 2, 1, 1, 0};
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    sortColors(nums1, n1);
    std::cout << "Example 1 Output: [";
    for (int i = 0; i < n1; ++i) {
        std::cout << nums1[i] << (i == n1 - 1 ? "" : ",");
    }
    std::cout << "]" << std::endl;

    // Example 2 input
    int nums2[] = {2, 0, 1};
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    sortColors(nums2, n2);
    std::cout << "Example 2 Output: [";
    for (int i = 0; i < n2; ++i) {
        std::cout << nums2[i] << (i == n2 - 1 ? "" : ",");
    }
    std::cout << "]" << std::endl;

    return 0;
}