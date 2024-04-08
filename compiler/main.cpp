#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "antlr4-runtime.h"
#include "generated/ifccLexer.h"
#include "generated/ifccParser.h"
#include "generated/ifccBaseVisitor.h"

// #include "CodeGenVisitor.h"
#include "CheckVisitor.h"
#include "IRVisitor.h"

using namespace antlr4;
using namespace std;

int main(int argn, const char **argv)
{
  stringstream in;
  if (argn == 2)
  {
    ifstream lecture(argv[1]);
    in << lecture.rdbuf();
  }
  else
  {
    cerr << "usage: ifcc path/to/file.c" << endl;
    exit(1);
  }

  ANTLRInputStream input(in.str());

  ifccLexer lexer(&input);
  CommonTokenStream tokens(&lexer);

  tokens.fill();

  ifccParser parser(&tokens);
  tree::ParseTree *tree = parser.axiom();

  if (parser.getNumberOfSyntaxErrors() != 0)
  {
    cerr << "error: syntax error during parsing" << endl;
    exit(1);
  }

  CheckVisitor CheckVisitor;

  CheckVisitor.visit(tree);

  IRVisitor irv;
  irv.visit(tree);
  vector<CFG *> CFGS = irv.getCFGS();
  for (CFG *cfg : CFGS)
  {
    // cfg->printCFG();
    auto symbolIndex = cfg->getSymbolIndex();
    for (const auto &pair : symbolIndex)
    {
      // cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }

    // cfg->gen_asm(cout, cfg->getFuncName());
#ifdef __APPLE__
    cfg->gen_asm_arm64(cout);

#else
    cfg->gen_asm(cout, cfg->getFuncName());
#endif
  }

  // cout << v.getVarMap().size()<< endl;
  // cout << v.getCurPointer() << endl;

  return 0;
}
