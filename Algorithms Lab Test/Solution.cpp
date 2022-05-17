
#include <bits/stdc++.h>
using namespace std;
 //=========================================================================================================
// Merge two subarrays L and M into arr
void merge(int arr[], const int p,const int q,const int r) {

    // Create L ← A[p..q] and M ← A[q+1..r]
    const int n1 = q - p + 1;
    const int n2 = r - q;

    int* L = new int[n1];
    int* M = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}
 //=========================================================================================================
 
// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // m is the point where the array is divided into two subarrays
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted subarrays
        merge(arr, l, m, r);
    }
}

 //=========================================================================================================
 
// Print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

 //=========================================================================================================
 
 int getPairsCount(int arr[], int n, int k)
{
    int x = 0, c = 0, y, z;
    for (int i = 0; i < n - 1; i++) {
        x = k - arr[i];
       
        // Lower bound from i+1
        int y = lower_bound(arr + i + 1,
                            arr + n, x) - arr;
         
        // Upper bound from i+1
        int z = upper_bound(arr + i + 1,
                            arr + n, x) - arr;
        c = c + z - y;
    }
    return c;
}


 //=========================================================================================================


int main() {
    int arr[] = { 10 , 3 , 5 , 10 , 7 , 4 , 9 };
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, size - 1);
    
    for (int i = 0; i < size-1; i++)
    {
        int summ=arr[i];
        for (int j = i+1; j < size; j++){ 
            cout<<"The pair " <<"{"<< summ <<","<< arr[j] << "}";
            int pair_sum = summ + arr[j];
            cout <<" is repeated "<< getPairsCount(arr, size, pair_sum)<< " times"<<" and there sum is "<<pair_sum<<endl;
    }
    }

}
