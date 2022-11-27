# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>

void push(char c);
char pop();
int isempty();
int precedence(char c);

char stack[40];
int top = -1;
int main(void){
    int n;
    printf("Length of expression(including brackets) : ");
    scanf("%i", &n);

    char* s = malloc(n + 1);

    printf("Expression : ");
    scanf("%s", s);

    char c;
    char current;
    int p;

    for(int i = 0; i < n; i++){
        if (isdigit(s[i]))
            printf("%c ", s[i]);

        else if (s[i] == '('){
            push(s[i]);
        }
        else if (s[i] == ')'){
            while(1){
                if (stack[top] != '('){
                    printf("%c ",pop());
                }
                else{
                    p = pop();
                    break;
                }
            }
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
            current = s[i];
            if (isempty() || stack[top] == '('){
                push(current);
            }
            else if (precedence(s[i]) > precedence(stack[top]))
                push(current);
            else if (precedence(s[i]) <= precedence(stack[top])){     //ALTER THIS PART
                printf("%c ",pop());
                while(1){
                    if (stack[top] == '(' || top == -1 || precedence(s[i]) > precedence(stack[top])){
                        push(current);
                        break;
                    }
                    else if (precedence(s[i]) <= precedence(stack[top])){
                        printf("%c ",pop());
                        continue;
                    }
                }
            }
        }
    }
    while(top != -1){
        printf("%c ", pop());
    }
    printf("\n");
    return 0;
}
int precedence(char c){
    if (c == '/' || c == '*')
        return 2;
    else
        return 1;
}
void push(char c){
    top ++;
    stack[top] = c;
}
int isempty(){
    return top == -1;
}
char pop(){
    top --;
    return stack[top + 1];
}