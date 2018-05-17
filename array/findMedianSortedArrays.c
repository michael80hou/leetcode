#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static inline int max(int i, int j) {
    return (i >= j ? i : j); 
}

static inline int min(int i, int j) {
    return (i >= j ? j : i); 
}

static inline int isOdd(int i) {
    return (i % 2);
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    assert(nums1 && nums1Size >= 0 && nums2 && nums2Size >= 0);
    assert(!(nums1Size == 0 && nums2Size == 0));

    int* a = nums1;
    int* b = nums2;    
    int m = nums1Size, n = nums2Size;
    int i = 0, j = 0;  
    double res = 0;
    double left_max = 0;
    double right_min = 0;

    //assume n >= m
    if(m > n) {
        return findMedianSortedArrays(b, n, a, m);
    }

    if(m == 0) {
        return isOdd(n) ? b[n/2] : ((b[n/2] + b[n/2 - 1]) / 2.0);        
    } 
    
    int range_left = 0, range_right = m;
    while(range_left <= range_right) {
        i = (range_left + range_right)/2;
        j = (n + m + 1) / 2 - i;

        if(i != 0 && i != m) {
            if(a[i] >= b[j - 1] && a[i - 1] <= b[j]) {
                left_max = max(a[i - 1], b[j - 1]);
                right_min = min(a[i], b[j]);
                res = isOdd(n + m) ? left_max : (left_max + right_min) / 2.0;
                break;
            } else if(a[i] < b[j - 1]) {
                range_left = i + 1;
            } else {
                range_right = i - 1;
            }            
        } else if(i == 0) {
            if(a[i] >= b[j - 1]) {
                left_max = b[j - 1];
                right_min = (j == n) ? a[i] : min(a[i], b[j]);
                res = isOdd(n + m) ? left_max : (left_max + right_min) / 2.0;
                break;
            } else {
                range_left = i + 1;
            }
            
        } else {
            //i == m
            if(a[i - 1] <= b[j]) {
                left_max = (j == 0) ? a[i - 1] : max(a[i - 1], b[j - 1]);
                right_min = b[j];
                res = isOdd(n + m) ? left_max : (left_max + right_min) / 2.0;
                break;
            } else {
                range_right = i - 1;
            }
        }     
        
    }
 
    return res;    
}

int main() {
    int nums1[] = {1, 2};
    int nums2[] = {3, 4};

    double res = 0.0;
    res = findMedianSortedArrays(nums1, sizeof(nums1)/sizeof(int), nums2, sizeof(nums2)/sizeof(int));

    printf("res %lf\n", res);
    
    return 0;
}


