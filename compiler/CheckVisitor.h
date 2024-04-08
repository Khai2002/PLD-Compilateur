#pragma once

#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"
#include <string>
#include <unordered_map>
#include "util.h"

using namespace std;

/**
 * @file CheckVisitor.h
 *
 * @brief The `CheckVisitor` class, derived from `ifccBaseVisitor`, implements a visitor pattern
 * for processing and analyzing an ANTLR4 parse tree. Here the role of this class is to do a check
 * for all the variables (correctly declared ) and for the functions (correct number of parameters / doesn't assign a variable to a void function ).
 *
 *  The class maintains a table of variable declarations (`adrTable`), a table of function
 * declarations (`func_table`) and a count of warnings  (`number_warnings`).
 * It provides methods to insert and check parameters, and visit various nodes
 * of the parse tree such as program, function declarations, variable declarations, and more,
 * processing them according to the rules of the C language.
 */

class CheckVisitor : public ifccBaseVisitor
{
public:
        //----------------------------------------------------- Public Methods

        //----------------------------------------------------- Constructors

        /**
         * Default constructor. Initializes `number_warnings` to zero.
         */
        CheckVisitor() : number_warnings(0) {}

        /**
         * Constructor that initializes the address table with a given map.
         * @param adrTable An unordered_map mapping string to VariableInfo, used to initialize the address table.
         */
        CheckVisitor(unordered_map<string, VariableInfo> adrTable) : adrTable(adrTable), number_warnings(0) {}

        //----------------------------------------------------- Getters

        /**
         * Gets the address table containing information about variables.
         * @return An unordered_map mapping string to VariableInfo.
         */
        unordered_map<string, VariableInfo> getAdrTable() { return this->adrTable; }

        /**
         * Gets the number of warnings generated during the checking process.
         * @return An integer count of the number of warnings.
         */
        int getNumber_warnings() { return this->number_warnings; }

        //----------------------------------------------------- Methods

        /**
         * Inserts a new variable with the given name and type into the address table.
         * If the variable already exists in the table, an error is thrown.
         * @param name The name of the variable to be inserted.
         * @param type The type of the variable (e.g., "int", "char").
         */
        void insertParam(string name, string type);

        /**
         * Checks if the variable is in adrTable.
         *  If it's the case it increments the callcount of the variable
         * Otherwise it exits the program
         * @param name The name of the variable to be checked.
         */
        void checkVariableName(string name);

        //-----------------------------------------------------  Visitor nodes

        virtual antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override;
        virtual antlrcpp::Any visitFunc_decl(ifccParser::Func_declContext *ctx) override;
        virtual antlrcpp::Any visitVar_decl(ifccParser::Var_declContext *ctx) override;
        virtual antlrcpp::Any visitDeclareAssign(ifccParser::DeclareAssignContext *ctx) override;
        virtual antlrcpp::Any visitReturn_stmt(ifccParser::Return_stmtContext *ctx) override;

        /**
         * Important: Methods in the visitor pattern following visitReturn_stmt are designed to return the type of the expressions they encounter.
         * These types are restricted to either int or void at present.
         * The purpose of this design is to safeguard against incorrect operations involving mismatched types.
         */
        virtual antlrcpp::Any visitVar(ifccParser::VarContext *ctx) override;

        virtual antlrcpp::Any visitVar_Assignment(ifccParser::Var_AssignmentContext *ctx) override;

        virtual antlrcpp::Any visitUnaireExpr(ifccParser::UnaireExprContext *ctx) override;
        virtual antlrcpp::Any visitMultDivModExpr(ifccParser::MultDivModExprContext *ctx) override;
        virtual antlrcpp::Any visitAddSubExpr(ifccParser::AddSubExprContext *ctx) override;
        virtual antlrcpp::Any visitMoreLessExpr(ifccParser::MoreLessExprContext *ctx) override;
        virtual antlrcpp::Any visitEqualExpr(ifccParser::EqualExprContext *ctx) override;
        virtual antlrcpp::Any visitAndExpr(ifccParser::AndExprContext *ctx) override;
        virtual antlrcpp::Any visitXorExpr(ifccParser::XorExprContext *ctx) override;
        virtual antlrcpp::Any visitOrExpr(ifccParser::OrExprContext *ctx) override;

        virtual antlrcpp::Any visitPutchar(ifccParser::PutcharContext *ctx) override;
        virtual antlrcpp::Any visitGetchar(ifccParser::GetcharContext *ctx) override;
        virtual antlrcpp::Any visitParExpr(ifccParser::ParExprContext *ctx) override;
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

        virtual antlrcpp::Any visitIntConst(ifccParser::IntConstContext *ctx) override;
        virtual antlrcpp::Any visitCharConst(ifccParser::CharConstContext *ctx) override;

protected:
        //----------------------------------------------------- Protected Attributs
        /**
         * An unordered map to hold information about variables.
         * It maps variable names to their respective `VariableInfo` objects.
         */
        unordered_map<string, VariableInfo> adrTable;

        /**
         * An unordered map to hold information about functions.
         * It maps function names to their respective `Function_info` objects.
         */
        unordered_map<string, Function_info> func_table;

        /**
         * This is a count, represented as an integer,
         * that tallies the number of warnings issued during the process of checking variables.
         * It serves as a means to impose constraints on the C language.
         * For instance, if the objective is to avoid unused variables,
         * this count could be effectively utilized for that purpose.
         */
        int number_warnings;

        string INT_Type = "int";
        string VOID_Type = "void";
};