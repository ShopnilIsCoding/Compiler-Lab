%{
    int count=0;
%}
%%
[0-9]*[.][0-9]+ count++;
.
\n {return 0;}
%%

int yywrap(){}
int main(){
    yylex();
    if(count!=0)
    printf("valid Float\n");
    else
    printf("invalid Float\n");
    return 0;
}