#include<stdio.h>
#include<malloc.h>

int main(){
	int n,temp,i,j;

	printf("������Ҫ��������ָ�����");
	scanf("%d\n",&n);

    int *array = (int*)malloc(sizeof(int)*(n+1));

	for(i = 0; i < n; i++){
        scanf("%d",array+i);
	}

	int count = 1;

	for(temp = n; temp > 0; temp = temp/2){
        printf("��%d������Ϊ%d\n",count,temp);

        for(j = 0; j + temp < n; j++){
            if(*(array+j) > *(array+j+temp)){
                int p;
                p = *(array+j);
                *(array+j) = *(array+j+temp);
                *(array+j+temp) = p;
            }
        }

        count++;
	}

	printf("�����");
    for(i = 0; i < n; i++){
        printf("%d\t",*(array+i));
    }
    printf("\n");
}

