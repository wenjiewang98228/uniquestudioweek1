#include<stdio.h>

void HeapSort(int arr[10],int n);
void maxHeapify(int arr[10], int i, int len);

int main(){

    int HeapSize;
    int arr[10] = {15,55,9,7,23,66,48,13,94,46};

	HeapSort(arr,10);

    for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}


void HeapSort(int arr[10],int n){

    int i;
    for(i = n/2-1; i>=0; i--) {
        maxHeapify(arr,i,n-1);
    }

    for (i = n-1; i >= 0; i--) {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            maxHeapify(arr, 0, i-1);
    }
}

void maxHeapify(int arr[], int i, int len){
    int temp, j;
    temp = arr[i];
    for (j = 2 * i; j < len; j *= 2) {
    if (j < len && arr[j] < arr[j + 1])
        ++j;
    if (temp >= arr[j])
        break;
        arr[i] = arr[j];
        i = j;
        }
    arr[i] = temp;
}
