
// Generated from ifcc.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "ifccVisitor.h"


/**
 * This class provides an empty implementation of ifccVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  ifccBaseVisitor : public ifccVisitor {
public:

  virtual std::any visitAxiom(ifccParser::AxiomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProg(ifccParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmt(ifccParser::StmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVar_decl(ifccParser::Var_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVar_ass(ifccParser::Var_assContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturn_stmt(ifccParser::Return_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAndExpr(ifccParser::AndExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCharConst(ifccParser::CharConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEqualExpr(ifccParser::EqualExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMultDivModExpr(ifccParser::MultDivModExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitXorExpr(ifccParser::XorExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVar(ifccParser::VarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIntConst(ifccParser::IntConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddSubExpr(ifccParser::AddSubExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMoreLessExpr(ifccParser::MoreLessExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOrExpr(ifccParser::OrExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType(ifccParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }


};

