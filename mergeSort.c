#include<stdio.h>

void MergeSort(int arr[10],int n);
void mSort(int arr[],int left, int right);
void merge(int arr[],int leftPos,int rightPos, int rightEnd);

int main(){

    int arr[10] = {15,55,9,7,23,66,48,13,94,46};

	MergeSort(arr,10);

    for (int i = 0; i < 10; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
}


void MergeSort(int arr[],int n){

    mSort(arr,0,n-1);
}

void mSort(int arr[],int left, int right){
    int center;

    if(left<right) {
        center = (left+right)/2;
        mSort(arr,left,center);
        mSort(arr,center+1,right);
        merge(arr,left,center+1,right);
        }
}

void merge(int arr[],int leftPos,int rightPos, int rightEnd){

    int t[10];

    int tmpPos,leftEnd,index;

    tmpPos = leftPos;
    leftEnd = rightPos-1;
    index = leftPos;

    while(leftPos<=leftEnd && rightPos<=rightEnd) {
        if(arr[leftPos]<=arr[rightPos]) {
            t[tmpPos] = arr[leftPos];
            tmpPos++;
            leftPos++;
            }
        else {
            t[tmpPos] = arr[rightPos];
            tmpPos++;
            rightPos++;
            }
        }

    while(leftPos<=leftEnd) {
        t[tmpPos] = arr[leftPos];
        tmpPos++;
        leftPos++;
        }

    while(rightPos<=rightEnd) {
        t[tmpPos] = arr[rightPos];
        tmpPos++;
        rightPos++;
        }

    while(index<=rightEnd){
        arr[index] = t[index];
        index++;
        }
}
