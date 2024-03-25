grammar ifcc;

axiom : prog EOF ;

prog: func_decl*;


func_decl : type ID '(' ')' '{' line* return_stmt '}';

line : stmt
    | expr ';'
    | if_block 
    | while_block 
    ;



if_block : 'if' '(' expr ')' (line | block) else_block? ;

else_block : 'else' (line | block) ;

while_block : 'while' '(' expr ')' (line | block);

block : '{' line* '}' ;

stmt : var_decl |  return_stmt ;

var_decl : type ID (',' ID)* ';' ;

return_stmt: RETURN (expr)? ';' ;

expr : 
    UNAIRE=('-'|'!') expr               # UnaireExpr
    | expr MULT_DIV_MOD expr            # MultDivModExpr
    | expr ADD_SUB=('+' | '-') expr     # AddSubExpr
    | expr MORE_LESS expr               # MoreLessExpr
    | expr EQ_NEQ expr                  # EqualExpr
    | expr AND expr                     # AndExpr
    | expr XOR expr                     # XorExpr
    | expr OR expr                      # OrExpr 
    | ID '=' expr                       # Var_Assignment
    |'putchar''('expr')'                # putchar
    |'getchar()'                        # getchar
    |'(' expr ')'                       # ParExpr
    | ID                                # Var
    | INT_CONST                         # IntConst
    | CHAR_CONST                        # CharConst
    | ID'('')'                          # FunctionCall
    
;

type : 'int' | 'char' | 'void' ;

MULT_DIV_MOD : '*'|'/'|'%' ;
MORE_LESS : '>'| '<';
EQ_NEQ : '==' | '!=';
AND : '&';
XOR : '^';
OR : '|';
UNAIRE : '!' | '-';
RETURN : 'return' ; 
INT_CONST : [0-9]+ ;
CHAR_CONST : '\'' . '\'' ; 
BLOC_COMMENT : '/*' .*? '*/' -> skip ;
LINE_COMMENT : '//' .*? '\n' -> skip ;
DIRECTIVE : '#' .*? '\n' -> skip ;

ID : [a-zA-Z_][a-zA-Z_0-9]* ;
WS    : [ \t\r\n] -> channel(HIDDEN);
