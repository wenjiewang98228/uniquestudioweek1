#include<stdio.h>

int main(){
    char example[] = "(3+4)*5-6+1";

    char stack1[11];
    char stack2[11];

    int count1 = 0;
    int count2 = 0;

    for(int i = 0; i < 11; i++){
        stack1[i] = ' ';
        stack2[i] = ' ';
    }

    for(int i = 0; i < 11; i++){
        char ch = example[i];
        //printf("%c  ",ch);

        switch(ch){
        case '(':
                {
                //printf("c");
                stack1[count1] = ch;
                count1++;
                break;
                }
        case '*':
        case '/':
                {

                if(stack1[--count1] == '(' || count1 == -1){
                    stack1[++count1] = ch;
                    count1++;
                }
                else{
                    for(int m = --count1; m>=0; m--){
                        if(stack1[count1] == '+' || stack1[count1] == '-'){
                             stack1[++count1] = ch;
                             count1++;
                             break;
                        }else{
                            if(stack1[count1] == '*' || stack1[count1] == '/'){
                                stack2[count2++] = stack1[count1--];
                            }
                        }
                    }
                }
                break;

                }
        case '+':
        case '-':

                {
                count1--;

                while(count1 >= 0){
                    if(stack1[count1] != '('){
                        stack2[count2] = stack1[count1];
                        count2++;
                        count1--;
                       }
                    else{
                        /*stack1[++count1] = ch;
                        count1++;*/
                        break;
                    }
                    }

                stack1[++count1] = ch;
                count1++;

                break;

                }
        case ')':
                {

                count1--;
               while(stack1[count1] != '(' && count1 >= 0){
                    stack2[count2] = stack1[count1];
                    stack1[count1] = ' ';
                    count2++;
                    count1--;
               }
                if(stack1[count1] == '('){
                    stack1[count1] = ' ';
                   }
                break;

                }
        default:
                stack2[count2] = ch;
                count2++;
                break;

    }
    }

    for(int t = 10; t >= 0; t--){
        if(stack1[t] != ' ' && stack1[t] != '(' && stack1[t] != ')'){
            stack2[count2++] = stack1[t];
            stack1[t] = ' ';
        }
    }

    for(int s = 0; s < 11; s++){
        printf("%c ",stack2[s]);
    }
}
