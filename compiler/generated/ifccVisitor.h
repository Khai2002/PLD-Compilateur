
// Generated from ifcc.g4 by ANTLR 4.7.2

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
    virtual antlrcpp::Any visitAxiom(ifccParser::AxiomContext *context) = 0;

    virtual antlrcpp::Any visitProg(ifccParser::ProgContext *context) = 0;

    virtual antlrcpp::Any visitStmt(ifccParser::StmtContext *context) = 0;

    virtual antlrcpp::Any visitFunc_decl(ifccParser::Func_declContext *context) = 0;

    virtual antlrcpp::Any visitVar_decl(ifccParser::Var_declContext *context) = 0;

    virtual antlrcpp::Any visitVar_ass(ifccParser::Var_assContext *context) = 0;

    virtual antlrcpp::Any visitReturn_stmt(ifccParser::Return_stmtContext *context) = 0;

    virtual antlrcpp::Any visitAndExpr(ifccParser::AndExprContext *context) = 0;

    virtual antlrcpp::Any visitCharConst(ifccParser::CharConstContext *context) = 0;

    virtual antlrcpp::Any visitEqualExpr(ifccParser::EqualExprContext *context) = 0;

    virtual antlrcpp::Any visitMultDivModExpr(ifccParser::MultDivModExprContext *context) = 0;

    virtual antlrcpp::Any visitUnaire(ifccParser::UnaireContext *context) = 0;

    virtual antlrcpp::Any visitXorExpr(ifccParser::XorExprContext *context) = 0;

    virtual antlrcpp::Any visitParExpr(ifccParser::ParExprContext *context) = 0;

    virtual antlrcpp::Any visitVar(ifccParser::VarContext *context) = 0;

    virtual antlrcpp::Any visitIntConst(ifccParser::IntConstContext *context) = 0;

    virtual antlrcpp::Any visitAddSubExpr(ifccParser::AddSubExprContext *context) = 0;

    virtual antlrcpp::Any visitMoreLessExpr(ifccParser::MoreLessExprContext *context) = 0;

    virtual antlrcpp::Any visitOrExpr(ifccParser::OrExprContext *context) = 0;

    virtual antlrcpp::Any visitType(ifccParser::TypeContext *context) = 0;


};

