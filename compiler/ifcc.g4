grammar ifcc;

axiom : prog EOF ;

prog : 'int' 'main' '(' ')' '{' stmt* return_stmt '}';

stmt : var_decl | return_stmt ;

var_decl : type ID ('=' expr)? ';' ;

return_stmt: RETURN (expr)? ';' ;

expr : expr MULT_DIV_MOD expr           # MultDivModExpr
    | expr ADD_SUB expr                 # AddSubExpr
    | expr MORE_LESS expr               # MoreLessExpr
    | expr EQ_NEQ expr                  # EqualExpr
    | expr AND expr                     # AndExpr
    | expr XOR expr                     # XorExpr
    | expr OR expr                      # OrExpr
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
RETURN : 'return' ; 
INT_CONST : [0-9]+ ;
CHAR_CONST : '\'' .*? '\'' ; 
COMMENT : '/*' .*? '*/' -> skip ;
DIRECTIVE : '#' .*? '\n' -> skip ;

ID : [a-zA-Z_][a-zA-Z_0-9]* ;
WS    : [ \t\r\n] -> channel(HIDDEN);

