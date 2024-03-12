grammar ifcc;

axiom : prog EOF ;

prog : 'int' 'main' '(' ')' '{' line* return_stmt '}' ;

line : stmt 
    | expr ';' 
    | if_block 
    | while_block 
    ;

    
if_block : 'if' '(' expr ')' (line | block) else_block? ;

else_block : 'else' (line | block | if_block) ;

while_block : 'while' '(' expr ')' (line | block);

block : '{' line* '}' ;


stmt : var_decl | var_ass | return_stmt ;

var_decl : type ID ('=' expr)? ';' ;

var_ass: ID '=' expr ';' ; 

return_stmt: RETURN (expr)? ';' ;

expr :  '(' expr ')'                    # ParExpr
    | expr MULT_DIV_MOD expr            # MultDivModExpr
    | expr ADD_SUB expr                 # AddSubExpr
    | expr MORE_LESS expr               # MoreLessExpr
    | expr EQ_NEQ expr                  # EqualExpr
    | expr AND expr                     # AndExpr
    | expr XOR expr                     # XorExpr
    | expr OR expr                      # OrExpr
    | UNAIRE expr                       # Unaire
    | ID                                # Var
    | INT_CONST                         # IntConst
    | CHAR_CONST                        # CharConst
    ;

type : 'int' | 'char' ;

MULT_DIV_MOD : '*'|'/'|'%' ;
ADD_SUB : '+'|'-';
MORE_LESS : '>'| '<';
EQ_NEQ : '==' | '!=';
AND : '&';
XOR : '^';
OR : '|';
UNAIRE : '!' | '-';
RETURN : 'return' ; 
INT_CONST : [0-9]+ ;
CHAR_CONST : '\'' .*? '\'' ; 
BLOCK_COMMENT : '/*' .*? '*/' -> skip ;
SINGLE_COMMENT: '//' .*? '\n' -> skip;
DIRECTIVE : '#' .*? '\n' -> skip ;

ID : [a-zA-Z_][a-zA-Z_0-9]* ;
WS    : [ \t\r\n] -> channel(HIDDEN);

