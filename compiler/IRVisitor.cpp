#include "IRVisitor.h"

using namespace std;

antlrcpp::Any IRVisitor::visitProg(ifccParser::ProgContext *ctx) 
{
    // Naive function to interate through all functions listed
    for (auto func_ctx :  ctx->func_decl()) {
        // Only execute main
        if(func_ctx->ID()->getText() != "main") continue;
        visit(func_ctx);
    }

    return 0;
}

antlrcpp::Any IRVisitor::visitFunc_decl(ifccParser::Func_declContext *ctx)
{
    cout << "pooping..." << endl;
    for (auto stmt : ctx->stmt()) {
            visit(stmt);
        }

    if (ctx->return_stmt()) {
        visit(ctx->return_stmt());
    }
    
    return 0;
}