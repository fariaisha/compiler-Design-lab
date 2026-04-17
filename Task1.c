#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char *str) {
    char *keywords[] = {"int", "float", "char", "double", "return", "if", "else"};
    int n = 7;
    for(int i = 0; i < n; i++) {
        if(strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=');
}

int main() {
    char str[] = "This is a int sum = 10; and a + b = 20";
    int i = 0;

    printf("Tokens and their types:\n\n");

    while(str[i] != '\0') {

        // Skip spaces
        if(str[i] == ' ') {
            i++;
            continue;
        }

        // Identifier or Keyword
        if(isalpha(str[i])) {
            char buffer[50];
            int j = 0;

            while(isalnum(str[i])) {
                buffer[j++] = str[i++];
            }
            buffer[j] = '\0';

            if(isKeyword(buffer))
                printf("%s --> Keyword\n", buffer);
            else
                printf("%s --> Identifier\n", buffer);
        }

        // Number
        else if(isdigit(str[i])) {
            char buffer[50];
            int j = 0;

            while(isdigit(str[i])) {
                buffer[j++] = str[i++];
            }
            buffer[j] = '\0';

            printf("%s --> Number\n", buffer);
        }

        // Operator
        else if(isOperator(str[i])) {
            printf("%c --> Operator\n", str[i]);
            i++;
        }

        // Punctuation
        else if(str[i] == ';') {
            printf("%c --> Punctuation\n", str[i]);
            i++;
        }

        else {
            i++;
        }
    }

    return 0;
}