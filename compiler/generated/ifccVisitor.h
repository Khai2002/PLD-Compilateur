
// Generated from ifcc.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "ifccParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by ifccParser.
 */
class  ifccVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ifccParser.
   */
    virtual std::any visitAxiom(ifccParser::AxiomContext *context) = 0;

    virtual std::any visitProg(ifccParser::ProgContext *context) = 0;

    virtual std::any visitStmt(ifccParser::StmtContext *context) = 0;

    virtual std::any visitVar_decl(ifccParser::Var_declContext *context) = 0;

    virtual std::any visitVar_ass(ifccParser::Var_assContext *context) = 0;

    virtual std::any visitReturn_stmt(ifccParser::Return_stmtContext *context) = 0;

    virtual std::any visitAndExpr(ifccParser::AndExprContext *context) = 0;

    virtual std::any visitCharConst(ifccParser::CharConstContext *context) = 0;

    virtual std::any visitEqualExpr(ifccParser::EqualExprContext *context) = 0;

    virtual std::any visitMultDivModExpr(ifccParser::MultDivModExprContext *context) = 0;

    virtual std::any visitXorExpr(ifccParser::XorExprContext *context) = 0;

    virtual std::any visitVar(ifccParser::VarContext *context) = 0;

    virtual std::any visitIntConst(ifccParser::IntConstContext *context) = 0;

    virtual std::any visitAddSubExpr(ifccParser::AddSubExprContext *context) = 0;

    virtual std::any visitMoreLessExpr(ifccParser::MoreLessExprContext *context) = 0;

    virtual std::any visitOrExpr(ifccParser::OrExprContext *context) = 0;

    virtual std::any visitType(ifccParser::TypeContext *context) = 0;


};

