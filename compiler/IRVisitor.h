#pragma once

#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"
#include <unordered_map>
#include <vector>
#include "util.h"
#include "IR.h"
using namespace std;

class IRVisitor : public ifccBaseVisitor
{
public:
  IRVisitor() {}

  virtual antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override;
  virtual antlrcpp::Any visitFunc_decl(ifccParser::Func_declContext *ctx) override;
  virtual antlrcpp::Any visitLine(ifccParser::LineContext *ctx) override;
  virtual antlrcpp::Any visitVar_decl(ifccParser::Var_declContext *ctx) override;
  virtual antlrcpp::Any visitVar(ifccParser::VarContext *ctx) override;
  virtual antlrcpp::Any visitAddSubExpr(ifccParser::AddSubExprContext *ctx) override;
  virtual antlrcpp::Any visitMultDivModExpr(ifccParser::MultDivModExprContext *ctx) override;
  virtual antlrcpp::Any visitVar_Assignment(ifccParser::Var_AssignmentContext *ctx) override;
  virtual antlrcpp::Any visitReturn_stmt(ifccParser::Return_stmtContext *ctx) override;
  virtual antlrcpp::Any visitIntConst(ifccParser::IntConstContext *ctx) override;
  virtual antlrcpp::Any visitCharConst(ifccParser::CharConstContext *ctx) override;
  virtual antlrcpp::Any visitBlock(ifccParser::BlockContext *ctx) override;
  virtual antlrcpp::Any visitIf_block(ifccParser::If_blockContext *ctx) override;
  virtual antlrcpp::Any visitElse_block(ifccParser::Else_blockContext *ctx) override;
  virtual antlrcpp::Any visitWhile_block(ifccParser::While_blockContext *ctx) override;
  virtual antlrcpp::Any visitStmt(ifccParser::StmtContext *ctx) override;
  virtual antlrcpp::Any visitAndExpr(ifccParser::AndExprContext *ctx) override;
  virtual antlrcpp::Any visitEqualExpr(ifccParser::EqualExprContext *ctx) override;
  virtual antlrcpp::Any visitUnaireExpr(ifccParser::UnaireExprContext *ctx) override;
  virtual antlrcpp::Any visitXorExpr(ifccParser::XorExprContext *ctx) override;
  virtual antlrcpp::Any visitParExpr(ifccParser::ParExprContext *ctx) override;
  virtual antlrcpp::Any visitMoreLessExpr(ifccParser::MoreLessExprContext *ctx) override;
  virtual antlrcpp::Any visitOrExpr(ifccParser::OrExprContext *ctx) override;
  virtual antlrcpp::Any visitPutchar(ifccParser::PutcharContext *ctx) override;
  virtual antlrcpp::Any visitGetchar(ifccParser::GetcharContext *ctx) override;
  virtual antlrcpp::Any visitFunctionCall(ifccParser::FunctionCallContext *ctx) override ; 
  // virtual antlrcpp::Any visitType(ifccParser::TypeContext *ctx) override;
  CFG *getCurrentCFG() { return currentCFG; }
  vector<CFG *> getCFGS(){return cfgs ; }

protected:
  vector<CFG *> cfgs;
  CFG *currentCFG;
};