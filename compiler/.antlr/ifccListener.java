// Generated from /home/lnguyen/Bureau/Home_INSA/pld-comp/compiler/ifcc.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link ifccParser}.
 */
public interface ifccListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link ifccParser#axiom}.
	 * @param ctx the parse tree
	 */
	void enterAxiom(ifccParser.AxiomContext ctx);
	/**
	 * Exit a parse tree produced by {@link ifccParser#axiom}.
	 * @param ctx the parse tree
	 */
	void exitAxiom(ifccParser.AxiomContext ctx);
	/**
	 * Enter a parse tree produced by {@link ifccParser#prog}.
	 * @param ctx the parse tree
	 */
	void enterProg(ifccParser.ProgContext ctx);
	/**
	 * Exit a parse tree produced by {@link ifccParser#prog}.
	 * @param ctx the parse tree
	 */
	void exitProg(ifccParser.ProgContext ctx);
	/**
	 * Enter a parse tree produced by {@link ifccParser#stmt}.
	 * @param ctx the parse tree
	 */
	void enterStmt(ifccParser.StmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link ifccParser#stmt}.
	 * @param ctx the parse tree
	 */
	void exitStmt(ifccParser.StmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link ifccParser#var_decl}.
	 * @param ctx the parse tree
	 */
	void enterVar_decl(ifccParser.Var_declContext ctx);
	/**
	 * Exit a parse tree produced by {@link ifccParser#var_decl}.
	 * @param ctx the parse tree
	 */
	void exitVar_decl(ifccParser.Var_declContext ctx);
	/**
	 * Enter a parse tree produced by the {@code VarAss}
	 * labeled alternative in {@link ifccParser#var_ass}.
	 * @param ctx the parse tree
	 */
	void enterVarAss(ifccParser.VarAssContext ctx);
	/**
	 * Exit a parse tree produced by the {@code VarAss}
	 * labeled alternative in {@link ifccParser#var_ass}.
	 * @param ctx the parse tree
	 */
	void exitVarAss(ifccParser.VarAssContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ExprAss}
	 * labeled alternative in {@link ifccParser#var_ass}.
	 * @param ctx the parse tree
	 */
	void enterExprAss(ifccParser.ExprAssContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ExprAss}
	 * labeled alternative in {@link ifccParser#var_ass}.
	 * @param ctx the parse tree
	 */
	void exitExprAss(ifccParser.ExprAssContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ReturnVar}
	 * labeled alternative in {@link ifccParser#return_stmt}.
	 * @param ctx the parse tree
	 */
	void enterReturnVar(ifccParser.ReturnVarContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ReturnVar}
	 * labeled alternative in {@link ifccParser#return_stmt}.
	 * @param ctx the parse tree
	 */
	void exitReturnVar(ifccParser.ReturnVarContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ReturnExp}
	 * labeled alternative in {@link ifccParser#return_stmt}.
	 * @param ctx the parse tree
	 */
	void enterReturnExp(ifccParser.ReturnExpContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ReturnExp}
	 * labeled alternative in {@link ifccParser#return_stmt}.
	 * @param ctx the parse tree
	 */
	void exitReturnExp(ifccParser.ReturnExpContext ctx);
	/**
	 * Enter a parse tree produced by the {@code AndExpr}
	 * labeled alternative in {@link ifccParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterAndExpr(ifccParser.AndExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code AndExpr}
	 * labeled alternative in {@link ifccParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitAndExpr(ifccParser.AndExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code CharConst}
	 * labeled alternative in {@link ifccParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterCharConst(ifccParser.CharConstContext ctx);
	/**
	 * Exit a parse tree produced by the {@code CharConst}
	 * labeled alternative in {@link ifccParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitCharConst(ifccParser.CharConstContext ctx);
	/**
	 * Enter a parse tree produced by the {@code EqualExpr}
	 * labeled alternative in {@link ifccParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterEqualExpr(ifccParser.EqualExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code EqualExpr}
	 * labeled alternative in {@link ifccParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitEqualExpr(ifccParser.EqualExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code MultDivModExpr}
	 * labeled alternative in {@link ifccParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterMultDivModExpr(ifccParser.MultDivModExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code MultDivModExpr}
	 * labeled alternative in {@link ifccParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitMultDivModExpr(ifccParser.MultDivModExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code XorExpr}
	 * labeled alternative in {@link ifccParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterXorExpr(ifccParser.XorExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code XorExpr}
	 * labeled alternative in {@link ifccParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitXorExpr(ifccParser.XorExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Var}
	 * labeled alternative in {@link ifccParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterVar(ifccParser.VarContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Var}
	 * labeled alternative in {@link ifccParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitVar(ifccParser.VarContext ctx);
	/**
	 * Enter a parse tree produced by the {@code IntConst}
	 * labeled alternative in {@link ifccParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterIntConst(ifccParser.IntConstContext ctx);
	/**
	 * Exit a parse tree produced by the {@code IntConst}
	 * labeled alternative in {@link ifccParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitIntConst(ifccParser.IntConstContext ctx);
	/**
	 * Enter a parse tree produced by the {@code AddSubExpr}
	 * labeled alternative in {@link ifccParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterAddSubExpr(ifccParser.AddSubExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code AddSubExpr}
	 * labeled alternative in {@link ifccParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitAddSubExpr(ifccParser.AddSubExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code MoreLessExpr}
	 * labeled alternative in {@link ifccParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterMoreLessExpr(ifccParser.MoreLessExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code MoreLessExpr}
	 * labeled alternative in {@link ifccParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitMoreLessExpr(ifccParser.MoreLessExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code OrExpr}
	 * labeled alternative in {@link ifccParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterOrExpr(ifccParser.OrExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code OrExpr}
	 * labeled alternative in {@link ifccParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitOrExpr(ifccParser.OrExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link ifccParser#type}.
	 * @param ctx the parse tree
	 */
	void enterType(ifccParser.TypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link ifccParser#type}.
	 * @param ctx the parse tree
	 */
	void exitType(ifccParser.TypeContext ctx);
}