%{
    #include <stdio.h>
    int vowels = 0;
    int cons = 0;
%}

%%

[aeiouAEIOU]       { vowels++; }
[a-zA-Z]           { cons++; }
.                  {}
\n                 {}

%%

int yywrap() {
    return 1; 
}

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            perror("Error opening file");
            return 1;
        }
        yyin = file;
    }
    
    
    yylex();
    
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", cons);
    
    return 0;
}