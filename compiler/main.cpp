#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "antlr4-runtime.h"
#include "generated/ifccLexer.h"
#include "generated/ifccParser.h"
#include "generated/ifccBaseVisitor.h"

// #include "CodeGenVisitor.h"
#include "VarCheckVisitor.h"
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
  // cout << "I'm coming 1" << endl;
  VarCheckVisitor varCheckVisitor;

  varCheckVisitor.visit(tree);

  int temp = 0;
  temp = varCheckVisitor.getNumber_errors();

  // cout << "#nombre d'erreurs  :" << varCheckVisitor.getNumber_errors() << endl;
  if (temp == 0)
  {
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
      cfg->gen_asm(cout, cfg->getFuncName());
      map<string, int> test = cfg->getSymbolIndex();
      map<string, int>::iterator it;
      for (it = test.begin(); it != test.end(); ++it) {
        cout << "Key: " << it->first << ", Value: " << it->second << endl;
    }
    }
  }
  else
  {
    return 1;
  }

  // cout << v.getVarMap().size()<< endl;
  // cout << v.getCurPointer() << endl;

  return 0;
}
