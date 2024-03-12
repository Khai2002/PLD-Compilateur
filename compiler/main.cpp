#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "antlr4-runtime.h"
#include "generated/ifccLexer.h"
#include "generated/ifccParser.h"
#include "generated/ifccBaseVisitor.h"

#include "CodeGenVisitor.h"
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

  VarCheckVisitor varCheckVisitor;
  varCheckVisitor.visit(tree);
  // cout << "nombre d'erreurs " << varCheckVisitor.getNumber_errors() << endl;
  if (varCheckVisitor.getNumber_errors() == 0)
  {
    // CodeGenVisitor v(varCheckVisitor.getAdrTable(), varCheckVisitor.getCurPointer());
    // v.visit(tree);
    IRVisitor irv;
    irv.visit(tree);
    
  }else{
    return 1 ; 
  }
  // cout << v.getVarMap().size()<< endl;
  // cout << v.getCurPointer() << endl;

  return 0;
}
