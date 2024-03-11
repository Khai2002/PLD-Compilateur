
// Generated from ifcc.g4 by ANTLR 4.7.2


#include "ifccVisitor.h"

#include "ifccParser.h"


using namespace antlrcpp;
using namespace antlr4;

ifccParser::ifccParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

ifccParser::~ifccParser() {
  delete _interpreter;
}

std::string ifccParser::getGrammarFileName() const {
  return "ifcc.g4";
}

const std::vector<std::string>& ifccParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& ifccParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- AxiomContext ------------------------------------------------------------------

ifccParser::AxiomContext::AxiomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ifccParser::ProgContext* ifccParser::AxiomContext::prog() {
  return getRuleContext<ifccParser::ProgContext>(0);
}

tree::TerminalNode* ifccParser::AxiomContext::EOF() {
  return getToken(ifccParser::EOF, 0);
}


size_t ifccParser::AxiomContext::getRuleIndex() const {
  return ifccParser::RuleAxiom;
}

antlrcpp::Any ifccParser::AxiomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitAxiom(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::AxiomContext* ifccParser::axiom() {
  AxiomContext *_localctx = _tracker.createInstance<AxiomContext>(_ctx, getState());
  enterRule(_localctx, 0, ifccParser::RuleAxiom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(16);
    prog();
    setState(17);
    match(ifccParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgContext ------------------------------------------------------------------

ifccParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ifccParser::Return_stmtContext* ifccParser::ProgContext::return_stmt() {
  return getRuleContext<ifccParser::Return_stmtContext>(0);
}

std::vector<ifccParser::StmtContext *> ifccParser::ProgContext::stmt() {
  return getRuleContexts<ifccParser::StmtContext>();
}

ifccParser::StmtContext* ifccParser::ProgContext::stmt(size_t i) {
  return getRuleContext<ifccParser::StmtContext>(i);
}


size_t ifccParser::ProgContext::getRuleIndex() const {
  return ifccParser::RuleProg;
}

antlrcpp::Any ifccParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::ProgContext* ifccParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 2, ifccParser::RuleProg);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(19);
    match(ifccParser::T__0);
    setState(20);
    match(ifccParser::T__1);
    setState(21);
    match(ifccParser::T__2);
    setState(22);
    match(ifccParser::T__3);
    setState(23);
    match(ifccParser::T__4);
    setState(27);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(24);
        stmt(); 
      }
      setState(29);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
    setState(30);
    return_stmt();
    setState(31);
    match(ifccParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

ifccParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ifccParser::Var_declContext* ifccParser::StmtContext::var_decl() {
  return getRuleContext<ifccParser::Var_declContext>(0);
}

ifccParser::Var_assContext* ifccParser::StmtContext::var_ass() {
  return getRuleContext<ifccParser::Var_assContext>(0);
}

ifccParser::Return_stmtContext* ifccParser::StmtContext::return_stmt() {
  return getRuleContext<ifccParser::Return_stmtContext>(0);
}


size_t ifccParser::StmtContext::getRuleIndex() const {
  return ifccParser::RuleStmt;
}

antlrcpp::Any ifccParser::StmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitStmt(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::StmtContext* ifccParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 4, ifccParser::RuleStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(36);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ifccParser::T__0:
      case ifccParser::T__8: {
        enterOuterAlt(_localctx, 1);
        setState(33);
        var_decl();
        break;
      }

      case ifccParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(34);
        var_ass();
        break;
      }

      case ifccParser::RETURN: {
        enterOuterAlt(_localctx, 3);
        setState(35);
        return_stmt();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_declContext ------------------------------------------------------------------

ifccParser::Var_declContext::Var_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ifccParser::TypeContext* ifccParser::Var_declContext::type() {
  return getRuleContext<ifccParser::TypeContext>(0);
}

tree::TerminalNode* ifccParser::Var_declContext::ID() {
  return getToken(ifccParser::ID, 0);
}

ifccParser::ExprContext* ifccParser::Var_declContext::expr() {
  return getRuleContext<ifccParser::ExprContext>(0);
}


size_t ifccParser::Var_declContext::getRuleIndex() const {
  return ifccParser::RuleVar_decl;
}

antlrcpp::Any ifccParser::Var_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitVar_decl(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::Var_declContext* ifccParser::var_decl() {
  Var_declContext *_localctx = _tracker.createInstance<Var_declContext>(_ctx, getState());
  enterRule(_localctx, 6, ifccParser::RuleVar_decl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(38);
    type();
    setState(39);
    match(ifccParser::ID);
    setState(42);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ifccParser::T__6) {
      setState(40);
      match(ifccParser::T__6);
      setState(41);
      expr(0);
    }
    setState(44);
    match(ifccParser::T__7);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_assContext ------------------------------------------------------------------

ifccParser::Var_assContext::Var_assContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ifccParser::Var_assContext::ID() {
  return getToken(ifccParser::ID, 0);
}

ifccParser::ExprContext* ifccParser::Var_assContext::expr() {
  return getRuleContext<ifccParser::ExprContext>(0);
}


size_t ifccParser::Var_assContext::getRuleIndex() const {
  return ifccParser::RuleVar_ass;
}

antlrcpp::Any ifccParser::Var_assContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitVar_ass(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::Var_assContext* ifccParser::var_ass() {
  Var_assContext *_localctx = _tracker.createInstance<Var_assContext>(_ctx, getState());
  enterRule(_localctx, 8, ifccParser::RuleVar_ass);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(46);
    match(ifccParser::ID);
    setState(47);
    match(ifccParser::T__6);
    setState(48);
    expr(0);
    setState(49);
    match(ifccParser::T__7);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Return_stmtContext ------------------------------------------------------------------

ifccParser::Return_stmtContext::Return_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ifccParser::Return_stmtContext::RETURN() {
  return getToken(ifccParser::RETURN, 0);
}

ifccParser::ExprContext* ifccParser::Return_stmtContext::expr() {
  return getRuleContext<ifccParser::ExprContext>(0);
}


size_t ifccParser::Return_stmtContext::getRuleIndex() const {
  return ifccParser::RuleReturn_stmt;
}

antlrcpp::Any ifccParser::Return_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitReturn_stmt(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::Return_stmtContext* ifccParser::return_stmt() {
  Return_stmtContext *_localctx = _tracker.createInstance<Return_stmtContext>(_ctx, getState());
  enterRule(_localctx, 10, ifccParser::RuleReturn_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(51);
    match(ifccParser::RETURN);
    setState(53);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ifccParser::T__2)
      | (1ULL << ifccParser::UNAIRE)
      | (1ULL << ifccParser::INT_CONST)
      | (1ULL << ifccParser::CHAR_CONST)
      | (1ULL << ifccParser::ID))) != 0)) {
      setState(52);
      expr(0);
    }
    setState(55);
    match(ifccParser::T__7);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

ifccParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ifccParser::ExprContext::getRuleIndex() const {
  return ifccParser::RuleExpr;
}

void ifccParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- AndExprContext ------------------------------------------------------------------

std::vector<ifccParser::ExprContext *> ifccParser::AndExprContext::expr() {
  return getRuleContexts<ifccParser::ExprContext>();
}

ifccParser::ExprContext* ifccParser::AndExprContext::expr(size_t i) {
  return getRuleContext<ifccParser::ExprContext>(i);
}

tree::TerminalNode* ifccParser::AndExprContext::AND() {
  return getToken(ifccParser::AND, 0);
}

ifccParser::AndExprContext::AndExprContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::AndExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitAndExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CharConstContext ------------------------------------------------------------------

tree::TerminalNode* ifccParser::CharConstContext::CHAR_CONST() {
  return getToken(ifccParser::CHAR_CONST, 0);
}

ifccParser::CharConstContext::CharConstContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::CharConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitCharConst(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EqualExprContext ------------------------------------------------------------------

std::vector<ifccParser::ExprContext *> ifccParser::EqualExprContext::expr() {
  return getRuleContexts<ifccParser::ExprContext>();
}

ifccParser::ExprContext* ifccParser::EqualExprContext::expr(size_t i) {
  return getRuleContext<ifccParser::ExprContext>(i);
}

tree::TerminalNode* ifccParser::EqualExprContext::EQ_NEQ() {
  return getToken(ifccParser::EQ_NEQ, 0);
}

ifccParser::EqualExprContext::EqualExprContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::EqualExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitEqualExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultDivModExprContext ------------------------------------------------------------------

std::vector<ifccParser::ExprContext *> ifccParser::MultDivModExprContext::expr() {
  return getRuleContexts<ifccParser::ExprContext>();
}

ifccParser::ExprContext* ifccParser::MultDivModExprContext::expr(size_t i) {
  return getRuleContext<ifccParser::ExprContext>(i);
}

tree::TerminalNode* ifccParser::MultDivModExprContext::MULT_DIV_MOD() {
  return getToken(ifccParser::MULT_DIV_MOD, 0);
}

ifccParser::MultDivModExprContext::MultDivModExprContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::MultDivModExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitMultDivModExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaireContext ------------------------------------------------------------------

tree::TerminalNode* ifccParser::UnaireContext::UNAIRE() {
  return getToken(ifccParser::UNAIRE, 0);
}

ifccParser::ExprContext* ifccParser::UnaireContext::expr() {
  return getRuleContext<ifccParser::ExprContext>(0);
}

ifccParser::UnaireContext::UnaireContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::UnaireContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitUnaire(this);
  else
    return visitor->visitChildren(this);
}
//----------------- XorExprContext ------------------------------------------------------------------

std::vector<ifccParser::ExprContext *> ifccParser::XorExprContext::expr() {
  return getRuleContexts<ifccParser::ExprContext>();
}

ifccParser::ExprContext* ifccParser::XorExprContext::expr(size_t i) {
  return getRuleContext<ifccParser::ExprContext>(i);
}

tree::TerminalNode* ifccParser::XorExprContext::XOR() {
  return getToken(ifccParser::XOR, 0);
}

ifccParser::XorExprContext::XorExprContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::XorExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitXorExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParExprContext ------------------------------------------------------------------

ifccParser::ExprContext* ifccParser::ParExprContext::expr() {
  return getRuleContext<ifccParser::ExprContext>(0);
}

ifccParser::ParExprContext::ParExprContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::ParExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitParExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VarContext ------------------------------------------------------------------

tree::TerminalNode* ifccParser::VarContext::ID() {
  return getToken(ifccParser::ID, 0);
}

ifccParser::VarContext::VarContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::VarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitVar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntConstContext ------------------------------------------------------------------

tree::TerminalNode* ifccParser::IntConstContext::INT_CONST() {
  return getToken(ifccParser::INT_CONST, 0);
}

ifccParser::IntConstContext::IntConstContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::IntConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitIntConst(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AddSubExprContext ------------------------------------------------------------------

std::vector<ifccParser::ExprContext *> ifccParser::AddSubExprContext::expr() {
  return getRuleContexts<ifccParser::ExprContext>();
}

ifccParser::ExprContext* ifccParser::AddSubExprContext::expr(size_t i) {
  return getRuleContext<ifccParser::ExprContext>(i);
}

tree::TerminalNode* ifccParser::AddSubExprContext::ADD_SUB() {
  return getToken(ifccParser::ADD_SUB, 0);
}

ifccParser::AddSubExprContext::AddSubExprContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::AddSubExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitAddSubExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MoreLessExprContext ------------------------------------------------------------------

std::vector<ifccParser::ExprContext *> ifccParser::MoreLessExprContext::expr() {
  return getRuleContexts<ifccParser::ExprContext>();
}

ifccParser::ExprContext* ifccParser::MoreLessExprContext::expr(size_t i) {
  return getRuleContext<ifccParser::ExprContext>(i);
}

tree::TerminalNode* ifccParser::MoreLessExprContext::MORE_LESS() {
  return getToken(ifccParser::MORE_LESS, 0);
}

ifccParser::MoreLessExprContext::MoreLessExprContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::MoreLessExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitMoreLessExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OrExprContext ------------------------------------------------------------------

std::vector<ifccParser::ExprContext *> ifccParser::OrExprContext::expr() {
  return getRuleContexts<ifccParser::ExprContext>();
}

ifccParser::ExprContext* ifccParser::OrExprContext::expr(size_t i) {
  return getRuleContext<ifccParser::ExprContext>(i);
}

tree::TerminalNode* ifccParser::OrExprContext::OR() {
  return getToken(ifccParser::OR, 0);
}

ifccParser::OrExprContext::OrExprContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ifccParser::OrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitOrExpr(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::ExprContext* ifccParser::expr() {
   return expr(0);
}

ifccParser::ExprContext* ifccParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ifccParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  ifccParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 12;
  enterRecursionRule(_localctx, 12, ifccParser::RuleExpr, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(67);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ifccParser::T__2: {
        _localctx = _tracker.createInstance<ParExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(58);
        match(ifccParser::T__2);
        setState(59);
        expr(0);
        setState(60);
        match(ifccParser::T__3);
        break;
      }

      case ifccParser::UNAIRE: {
        _localctx = _tracker.createInstance<UnaireContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(62);
        match(ifccParser::UNAIRE);
        setState(63);
        expr(4);
        break;
      }

      case ifccParser::ID: {
        _localctx = _tracker.createInstance<VarContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(64);
        match(ifccParser::ID);
        break;
      }

      case ifccParser::INT_CONST: {
        _localctx = _tracker.createInstance<IntConstContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(65);
        match(ifccParser::INT_CONST);
        break;
      }

      case ifccParser::CHAR_CONST: {
        _localctx = _tracker.createInstance<CharConstContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(66);
        match(ifccParser::CHAR_CONST);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(92);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(90);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultDivModExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(69);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(70);
          match(ifccParser::MULT_DIV_MOD);
          setState(71);
          expr(12);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddSubExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(72);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(73);
          match(ifccParser::ADD_SUB);
          setState(74);
          expr(11);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<MoreLessExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(75);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(76);
          match(ifccParser::MORE_LESS);
          setState(77);
          expr(10);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<EqualExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(78);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(79);
          match(ifccParser::EQ_NEQ);
          setState(80);
          expr(9);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<AndExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(81);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(82);
          match(ifccParser::AND);
          setState(83);
          expr(8);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<XorExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(84);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(85);
          match(ifccParser::XOR);
          setState(86);
          expr(7);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<OrExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(87);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(88);
          match(ifccParser::OR);
          setState(89);
          expr(6);
          break;
        }

        } 
      }
      setState(94);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

ifccParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ifccParser::TypeContext::getRuleIndex() const {
  return ifccParser::RuleType;
}

antlrcpp::Any ifccParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::TypeContext* ifccParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 14, ifccParser::RuleType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(95);
    _la = _input->LA(1);
    if (!(_la == ifccParser::T__0

    || _la == ifccParser::T__8)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool ifccParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 6: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ifccParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 11);
    case 1: return precpred(_ctx, 10);
    case 2: return precpred(_ctx, 9);
    case 3: return precpred(_ctx, 8);
    case 4: return precpred(_ctx, 7);
    case 5: return precpred(_ctx, 6);
    case 6: return precpred(_ctx, 5);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> ifccParser::_decisionToDFA;
atn::PredictionContextCache ifccParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ifccParser::_atn;
std::vector<uint16_t> ifccParser::_serializedATN;

std::vector<std::string> ifccParser::_ruleNames = {
  "axiom", "prog", "stmt", "var_decl", "var_ass", "return_stmt", "expr", 
  "type"
};

std::vector<std::string> ifccParser::_literalNames = {
  "", "'int'", "'main'", "'('", "')'", "'{'", "'}'", "'='", "';'", "'char'", 
  "", "", "", "", "'&'", "'^'", "'|'", "", "'return'"
};

std::vector<std::string> ifccParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "MULT_DIV_MOD", "ADD_SUB", "MORE_LESS", 
  "EQ_NEQ", "AND", "XOR", "OR", "UNAIRE", "RETURN", "INT_CONST", "CHAR_CONST", 
  "COMMENT", "DIRECTIVE", "ID", "WS"
};

dfa::Vocabulary ifccParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> ifccParser::_tokenNames;

ifccParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x1a, 0x64, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x1c, 
    0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x1f, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x27, 0xa, 0x4, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x2d, 0xa, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 
    0x7, 0x5, 0x7, 0x38, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x5, 0x8, 0x46, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x5d, 0xa, 0x8, 0xc, 0x8, 
    0xe, 0x8, 0x60, 0xb, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x2, 0x3, 0xe, 
    0xa, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x2, 0x3, 0x4, 0x2, 0x3, 
    0x3, 0xb, 0xb, 0x2, 0x6b, 0x2, 0x12, 0x3, 0x2, 0x2, 0x2, 0x4, 0x15, 
    0x3, 0x2, 0x2, 0x2, 0x6, 0x26, 0x3, 0x2, 0x2, 0x2, 0x8, 0x28, 0x3, 0x2, 
    0x2, 0x2, 0xa, 0x30, 0x3, 0x2, 0x2, 0x2, 0xc, 0x35, 0x3, 0x2, 0x2, 0x2, 
    0xe, 0x45, 0x3, 0x2, 0x2, 0x2, 0x10, 0x61, 0x3, 0x2, 0x2, 0x2, 0x12, 
    0x13, 0x5, 0x4, 0x3, 0x2, 0x13, 0x14, 0x7, 0x2, 0x2, 0x3, 0x14, 0x3, 
    0x3, 0x2, 0x2, 0x2, 0x15, 0x16, 0x7, 0x3, 0x2, 0x2, 0x16, 0x17, 0x7, 
    0x4, 0x2, 0x2, 0x17, 0x18, 0x7, 0x5, 0x2, 0x2, 0x18, 0x19, 0x7, 0x6, 
    0x2, 0x2, 0x19, 0x1d, 0x7, 0x7, 0x2, 0x2, 0x1a, 0x1c, 0x5, 0x6, 0x4, 
    0x2, 0x1b, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1f, 0x3, 0x2, 0x2, 0x2, 
    0x1d, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x1e, 
    0x20, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x20, 0x21, 
    0x5, 0xc, 0x7, 0x2, 0x21, 0x22, 0x7, 0x8, 0x2, 0x2, 0x22, 0x5, 0x3, 
    0x2, 0x2, 0x2, 0x23, 0x27, 0x5, 0x8, 0x5, 0x2, 0x24, 0x27, 0x5, 0xa, 
    0x6, 0x2, 0x25, 0x27, 0x5, 0xc, 0x7, 0x2, 0x26, 0x23, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0x24, 0x3, 0x2, 0x2, 0x2, 0x26, 0x25, 0x3, 0x2, 0x2, 0x2, 
    0x27, 0x7, 0x3, 0x2, 0x2, 0x2, 0x28, 0x29, 0x5, 0x10, 0x9, 0x2, 0x29, 
    0x2c, 0x7, 0x19, 0x2, 0x2, 0x2a, 0x2b, 0x7, 0x9, 0x2, 0x2, 0x2b, 0x2d, 
    0x5, 0xe, 0x8, 0x2, 0x2c, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2d, 0x3, 
    0x2, 0x2, 0x2, 0x2d, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2f, 0x7, 0xa, 
    0x2, 0x2, 0x2f, 0x9, 0x3, 0x2, 0x2, 0x2, 0x30, 0x31, 0x7, 0x19, 0x2, 
    0x2, 0x31, 0x32, 0x7, 0x9, 0x2, 0x2, 0x32, 0x33, 0x5, 0xe, 0x8, 0x2, 
    0x33, 0x34, 0x7, 0xa, 0x2, 0x2, 0x34, 0xb, 0x3, 0x2, 0x2, 0x2, 0x35, 
    0x37, 0x7, 0x14, 0x2, 0x2, 0x36, 0x38, 0x5, 0xe, 0x8, 0x2, 0x37, 0x36, 
    0x3, 0x2, 0x2, 0x2, 0x37, 0x38, 0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 0x3, 
    0x2, 0x2, 0x2, 0x39, 0x3a, 0x7, 0xa, 0x2, 0x2, 0x3a, 0xd, 0x3, 0x2, 
    0x2, 0x2, 0x3b, 0x3c, 0x8, 0x8, 0x1, 0x2, 0x3c, 0x3d, 0x7, 0x5, 0x2, 
    0x2, 0x3d, 0x3e, 0x5, 0xe, 0x8, 0x2, 0x3e, 0x3f, 0x7, 0x6, 0x2, 0x2, 
    0x3f, 0x46, 0x3, 0x2, 0x2, 0x2, 0x40, 0x41, 0x7, 0x13, 0x2, 0x2, 0x41, 
    0x46, 0x5, 0xe, 0x8, 0x6, 0x42, 0x46, 0x7, 0x19, 0x2, 0x2, 0x43, 0x46, 
    0x7, 0x15, 0x2, 0x2, 0x44, 0x46, 0x7, 0x16, 0x2, 0x2, 0x45, 0x3b, 0x3, 
    0x2, 0x2, 0x2, 0x45, 0x40, 0x3, 0x2, 0x2, 0x2, 0x45, 0x42, 0x3, 0x2, 
    0x2, 0x2, 0x45, 0x43, 0x3, 0x2, 0x2, 0x2, 0x45, 0x44, 0x3, 0x2, 0x2, 
    0x2, 0x46, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x47, 0x48, 0xc, 0xd, 0x2, 0x2, 
    0x48, 0x49, 0x7, 0xc, 0x2, 0x2, 0x49, 0x5d, 0x5, 0xe, 0x8, 0xe, 0x4a, 
    0x4b, 0xc, 0xc, 0x2, 0x2, 0x4b, 0x4c, 0x7, 0xd, 0x2, 0x2, 0x4c, 0x5d, 
    0x5, 0xe, 0x8, 0xd, 0x4d, 0x4e, 0xc, 0xb, 0x2, 0x2, 0x4e, 0x4f, 0x7, 
    0xe, 0x2, 0x2, 0x4f, 0x5d, 0x5, 0xe, 0x8, 0xc, 0x50, 0x51, 0xc, 0xa, 
    0x2, 0x2, 0x51, 0x52, 0x7, 0xf, 0x2, 0x2, 0x52, 0x5d, 0x5, 0xe, 0x8, 
    0xb, 0x53, 0x54, 0xc, 0x9, 0x2, 0x2, 0x54, 0x55, 0x7, 0x10, 0x2, 0x2, 
    0x55, 0x5d, 0x5, 0xe, 0x8, 0xa, 0x56, 0x57, 0xc, 0x8, 0x2, 0x2, 0x57, 
    0x58, 0x7, 0x11, 0x2, 0x2, 0x58, 0x5d, 0x5, 0xe, 0x8, 0x9, 0x59, 0x5a, 
    0xc, 0x7, 0x2, 0x2, 0x5a, 0x5b, 0x7, 0x12, 0x2, 0x2, 0x5b, 0x5d, 0x5, 
    0xe, 0x8, 0x8, 0x5c, 0x47, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x4a, 0x3, 0x2, 
    0x2, 0x2, 0x5c, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x50, 0x3, 0x2, 0x2, 
    0x2, 0x5c, 0x53, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x56, 0x3, 0x2, 0x2, 0x2, 
    0x5c, 0x59, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x60, 0x3, 0x2, 0x2, 0x2, 0x5e, 
    0x5c, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x5f, 0xf, 
    0x3, 0x2, 0x2, 0x2, 0x60, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x61, 0x62, 0x9, 
    0x2, 0x2, 0x2, 0x62, 0x11, 0x3, 0x2, 0x2, 0x2, 0x9, 0x1d, 0x26, 0x2c, 
    0x37, 0x45, 0x5c, 0x5e, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

ifccParser::Initializer ifccParser::_init;
