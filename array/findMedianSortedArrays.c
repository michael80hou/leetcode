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
    assert(nums1 && nums1Size > 0 && nums2 && nums2Size > 0);

    if(nums1Size == 0 && nums2Size == 0) {
        return 0;
    } else if(nums1Size == 0) {
        if(isOdd(nums2Size)) {
            return nums2[nums2Size/2];
        } else {
            return (nums2[nums2Size/2] + nums2[nums2Size/2 - 1]) / 2.0;
        }
    } else if(nums2Size == 0){
        if(isOdd(nums1Size)) {
            return nums1[nums1Size/2];
        } else {
            return (nums1[nums1Size/2] + nums1[nums1Size/2 - 1]) / 2.0;
        }

    }
    
    int* a = NULL;
    int *b = NULL;
    //assume n >= m
    int m = 0, n = 0;
    int i = 0, j = 0, range_left = 0, range_right = 0;
    double res = 0;
    double left_max = 0;
    double right_min = 0;

    if(nums1Size >= nums2Size) {
        a = nums2;
        m = nums2Size;
        b = nums1;
        n = nums1Size;
    } else {
        a = nums1;
        m = nums1Size;
        b = nums2;
        n = nums2Size;
    }

    for(range_left = 0, range_right = m; ; ) {
        // value range [0, m], edge case i = 0 or i = m
        i = (range_left + range_right)/2;
        // value range [0, n], edge case j = 0 or j = n
        j = (n + m + 1) / 2 - i;

        printf("range left %d range_right %d i %d j %d\n",range_left, range_right, i, j);

        if(i != 0 && i != m) {
            if(a[i] >= b[j - 1] && a[i - 1] <= b[j]) {
                break;
            } else if(a[i] < b[j - 1]) {
                if(range_left == i) {
                    range_left = range_right;
                } else {
                    range_left = i;
                }
            } else {
                range_right = i;
            }
        } else if(i == 0) {
            if(a[i] >= b[j - 1]) {
                break;
            } else {
                range_left = range_right;
            }
        } else {
            if(a[i - 1] <= b[j]) {
                break;
            }
        }
      
    }

    

    if(isOdd(n + m)) {
        if(i == 0) {
            res = b[j - 1];
        } else if(j == 0){
            res = a[i - 1];
        } else {
            res = max (a[i -1], b[j - 1]);
        }
    } else {
        if(i == 0) {
            left_max = b[j - 1];
        } else if(j == 0){
            left_max = a[i - 1];
        } else {
            left_max = max(a[i - 1], b[j - 1]);
        }

        if(i == m)
        {
            right_min = b[j];
        } else if( j == n){
            right_min = a[i];
        } else {
            right_min = min(a[i], b[j]);
        }

        res = (left_max + right_min) / 2.0;
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


