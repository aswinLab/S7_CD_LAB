%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(const char *s);
%}

%token OPERAND

%left '='
%left '+' '-'
%left '*' '/'

%%

start: S '\n' {
    printf("Valid operation, good job\n");
    return 1;

}
;

S:
    S '+' T
    | S '-' T
    | T
    ;
    
T:
    T '*' F
    | T '/' F
    | F
    ;
    
F:
    OPERAND
    | '(' S ')'
    ;

%%

void yyerror(const char *s) {
    printf("Error : Not a valid expression, learn better\n");
    exit(1);
}


int main() {
    yyparse();
    return 0;
}