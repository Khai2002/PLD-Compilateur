#ifndef AST_H
#define AST_H

#include <string>
#include <vector>

using namespace std;


class Node {
public:
    Node() {}
    Node(int line) {}
    virtual ~Node() = default;
    const int getLine() const {return line;}
    
protected:
    int line;

};

class Stmt : public Node {
public:
    Stmt() {}
    Stmt(int line) : Node(line) {}
    virtual ~Stmt() = default;

protected:
};

class ReturnStmt : public Stmt {
public:
    ReturnStmt() {}
    ReturnStmt(int line) : Stmt(line) {}
    virtual ~ReturnStmt() = default;

protected:
};

class Expr : public Node {
public:
    Expr() {}
    Expr(int line) : Node(line) {};
    virtual ~Expr() = default;

protected:
};

class IntConst : public Expr {
public:
    IntConst(int value) : value(value) {};
    IntConst(int value, int line) : Expr(line), value(value) {};
protected:
    int value;
};

class CharConst : public Expr {
public:
    CharConst(char value) : value(value) {};
    CharConst(char value, int line) : Expr(line), value(value) {};
protected:
    char value;
};

class Type {
public:
    Type() {}
    Type(string &name) : name(name) {}
protected:
    string name;
};

class VarDecl : public Stmt {
public:
    VarDecl() {}
    VarDecl(string &id, Type* type, Expr* expr) : id(id), type(type), expr(expr) {}
    VarDecl(string &id, Type* type, Expr* expr, int line) : Stmt(line), id(id), type(type), expr(expr) {}
    virtual ~VarDecl() = default;
    const string getId() const { return id; }
    const Type *getType() const { return type; }
    const Expr *getExpr() const { return expr; }
protected:
    string id;
    Type* type;
    Expr* expr;
};


#endif