#pragma once

#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"
#include <unordered_map>
#include <vector>
#include "util.h"
#include "IR.h"
#include "util.h"
using namespace std;

/**
 * @file CheckVisitor.h
 *
 * @brief The `CheckVisitor` class, derived from `ifccBaseVisitor`, implements a visitor pattern
 * for processing and analyzing an ANTLR4 parse tree. Here the role of this class is to do a check
 * for all the variables (correctly declared ) and for the functions (correct number of parameters / doesn't assign a variable to a void function ).
 *
 * This class is used for traversing and transforming the parse tree into an Intermediate Representation (IR).
 * It contains methods to visit different kinds of nodes in the parse tree and generate corresponding IR instructions.
 */

class IRVisitor : public ifccBaseVisitor
{
public:
  IRVisitor() {}

  virtual antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override;
  virtual antlrcpp::Any visitFunc_decl(ifccParser::Func_declContext *ctx) override;
  virtual antlrcpp::Any visitLine(ifccParser::LineContext *ctx) override;
  virtual antlrcpp::Any visitVar_decl(ifccParser::Var_declContext *ctx) override;
  virtual antlrcpp::Any visitDeclareAssign(ifccParser::DeclareAssignContext *ctx) override;

  virtual antlrcpp::Any visitVar(ifccParser::VarContext *ctx) override;
  virtual antlrcpp::Any visitAddSubExpr(ifccParser::AddSubExprContext *ctx) override;
  virtual antlrcpp::Any visitMultDivModExpr(ifccParser::MultDivModExprContext *ctx) override;
  virtual antlrcpp::Any visitVar_Assignment(ifccParser::Var_AssignmentContext *ctx) override;
  virtual antlrcpp::Any visitReturn_stmt(ifccParser::Return_stmtContext *ctx) override;
  virtual antlrcpp::Any visitIntConst(ifccParser::IntConstContext *ctx) override;
  virtual antlrcpp::Any visitCharConst(ifccParser::CharConstContext *ctx) override;
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
  virtual antlrcpp::Any visitFunctionCall(ifccParser::FunctionCallContext *ctx) override;
  virtual antlrcpp::Any visitVarPostIncrement(ifccParser::VarPostIncrementContext *ctx) override;
  virtual antlrcpp::Any visitVarPostDecrement(ifccParser::VarPostDecrementContext *ctx) override;
  virtual antlrcpp::Any visitVarParPostIncrement(ifccParser::VarParPostIncrementContext *ctx) override;
  virtual antlrcpp::Any visitVarParPostDecrement(ifccParser::VarParPostDecrementContext *ctx) override;
  virtual antlrcpp::Any visitVarPreIncrement(ifccParser::VarPreIncrementContext *ctx) override;
  virtual antlrcpp::Any visitVarPreDecrement(ifccParser::VarPreDecrementContext *ctx) override;
  virtual antlrcpp::Any visitVarParPreIncrement(ifccParser::VarParPreIncrementContext *ctx) override;
  virtual antlrcpp::Any visitVarParPreDecrement(ifccParser::VarParPreDecrementContext *ctx) override;
  virtual antlrcpp::Any visitVarAdditionAssignment(ifccParser::VarAdditionAssignmentContext *ctx) override;
  virtual antlrcpp::Any visitVarSubstractionAssignment(ifccParser::VarSubstractionAssignmentContext *ctx) override;

  /**
   * Get the current Control Flow Graph (CFG).
   * @return A pointer to the current CFG.
   */
  CFG *getCurrentCFG() { return currentCFG; }

  /**
   * Get all Control Flow Graphs (CFGs).
   * @return A vector of pointers to CFGs.
   */
  vector<CFG *> getCFGS() { return cfgs; }

  /**
   * Check if a string represents a constant value.
   * @param s The string to check.
   * @return True if the string represents a constant, false otherwise.
   */
  bool isConstant(string s) { return isdigit(s[0]) || s[0] == '-'; }

protected:
  /**
   * A vector storing all the Control Flow Graphs (CFGs).
   */
  vector<CFG *> cfgs;

  /**
   * A pointer to the current Control Flow Graph (CFG).
   */
  CFG *currentCFG;

  /**
   * A map storing the functions and their corresponding types.
   */
  map<string, string> functionTypesMap;
};