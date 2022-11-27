# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>


int stack[40];
int top = -1;

void push(int e){
    top ++;
    stack[top] = e;
}

int pop(){
    top--;
    return stack[top + 1];
}

int main(void){
    int n;
    int a,b,result;
    printf("Length of expression : ");
    scanf("%i", &n);

    char *s = malloc(n + 1);

    printf("Valid expression : ");
    scanf("%s", s);

    for(int i = 0; i < n; i ++){
        if (isdigit(s[i])){
            push((int)(s[i] - '0'));
        }
        else{
            switch(s[i]){
                case '+':
                    a = pop();
                    if (top == -1){
                        break;
                    }
                    b = pop();
                    result = a + b;
                    push(result);
                    break;
                case '-':
                    a = pop();
                    if (top == -1){
                        break;
                    }
                    b = pop();
                    result = b - a;
                    push(result);
                    break;
                case '*':
                    a = pop();
                    if (top == -1){
                        break;
                    }
                    b = pop();
                    result = a * b;
                    push(result);
                    break;
                case '/':
                    a = pop();
                    if (top == -1){
                        break;
                    }
                    b = pop();
                    result = b / a;
                    push(result);
                    break;
            }
        }
    }

    printf("Result : %i\n", pop());
    return 0;
}