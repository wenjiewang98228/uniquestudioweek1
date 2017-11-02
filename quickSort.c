#include<stdio.h>
#include<malloc.h>

void qSort(int arr[],int l,int r);

int main(){
	int arr[10] = {13,75,48,57,74,26,42,18,49,85};

	int l = 0;
	int r = 9;

	qSort(arr,l,r);

	for(int i = 0; i<10; i++){
        printf("%d\t",arr[i]);
	}
}

void qSort(int arr[],int l,int r){
    int i = l;
    int j = r;
    int x = arr[l];


    while(j>i) {

       while(j>i&&arr[j]>=x)
        j--;

        if(arr[j]<=x) {
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i]=temp;
            }

        while(j>i&&arr[i]<=x)
            i++;

        if(arr[i]>=x) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            }

		}
    if(i>l) qSort(arr,l,j-1);
    if(j<r) qSort(arr,i+1,r);

}
