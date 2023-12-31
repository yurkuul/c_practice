/**
 * Write a complete function that is passed an array of integers 'arr' and its
 * length 'len'. It will return an integer containing the number of times the
 * most frequent value between -100 and +100 occurs, and it will ignore any
 * values outside that range.
 * 
 * i.e.
 * 'arr' = (0, -7, 102, -7, 5, 5,  -7, 3, 102, 102, -5, -5, 16, -73, 102, 0, 
 *          -73, 8, 8, 8)
 * will return 3 (since both -7 and 8 occur 3 times, and 102 is ignored).
 * 
 * Solution must be O(n) on the size of the array.
 * 
 * @source: COMP 2160 Sample Midterm Question 14 (6 marks)
 * @author: Lisa Zhu
*/

#include <stdio.h>
#include <stdlib.h>


const int MIN_VAL = -100;
const int MAX_VAL = 100;

int most_frequent_val(int arr[], int len) {
    int freq_len = abs(MIN_VAL) + abs(MAX_VAL) + 1;
    int freqs[freq_len];
    int most_freq = 0;

    int index = 0;
    for (int i = MIN_VAL; i < MAX_VAL+1; i++) {
        freqs[index] = 0;
        index++;
    }

    for (int i = 0; i < len; i++) {
        if (arr[i] >= MIN_VAL && arr[i] <= MAX_VAL) {
            if (arr[i] < 0) { //negative value
                freqs[abs(arr[i])]++;
            } else if (arr[i] > 0) { //positive value
                freqs[arr[i] + 100]++;
            }
        }
    }

    for (int i = 0; i < freq_len; i++) {
        if (most_freq < freqs[i]) {
            most_freq = freqs[i];
        }
    }

    return most_freq;
}

int main() {
    int arr[] = {0, -7, 102, -7, 5, 5,  -7, 3, 102, 102, -5, -5, 16, -73, 102, 0, -73, 8, 8, 8};
    int len = 20;

    int num = most_frequent_val(arr, len);

    printf("Array: \n[");

    for (int i = 0; i < len-1; i++) {
        printf("%d, ", arr[i]);
    }

    printf("%d]\n", arr[len-1]);

    printf("Most frequent appearance of a number: %d\n", num);

    return 1;
}