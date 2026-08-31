%{
    #include "y.tab.h"
    
%}

%%

[a-zA-Z1-9]+        {return OPERAND; }
[\-+*/=]             {return yytext[0]; }
\n                  {return '\n'; }
[ \t]               {}
.                   { return yytext[0]; }

%%

int yywrap() {
    return 1;
}  