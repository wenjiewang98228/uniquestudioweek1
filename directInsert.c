#include<stdio.h>
#include<malloc.h>

int main(){
	int n,temp,i,j;

	printf("请输入要排序的数字个数：");
	scanf("%d\n",&n);

    int *array = (int*)malloc(sizeof(int)*(n+1));

	for(i = 0; i < n; i++){
        scanf("%d",array+i);
	}

	for(i = 0; i < n; i++){
        temp = *(array + i);
        for(j = i; j > 0 && *(array+j-1) > temp; j--){
            *(array+j) = *(array+j-1);
            *(array+j-1) = temp;
            }
        }

    for(i = 0; i < n; i++){
        printf("%d\t",*(array+i));
    }
    printf("\n");
}
