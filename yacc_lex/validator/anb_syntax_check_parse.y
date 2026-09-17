%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(const char *s);
%}

%token A B

%%


start: S '\n' { 
            printf("Valid string\n"); 
            exit(0); 
       }
     ;

S: A S
 | A B
 ;

%%

void yyerror(const char *s) {
    printf("Error : Not a valid string, learn better\n");
    exit(1);
}

int main() {
    yyparse();
    return 0;
}