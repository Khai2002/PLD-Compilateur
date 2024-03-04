// Generated from /home/lnguyen/Bureau/Home_INSA/pld-comp/compiler/ifcc.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue", "this-escape"})
public class ifccLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		MULT_DIV_MOD=10, ADD_SUB=11, MORE_LESS=12, EQ_NEQ=13, AND=14, XOR=15, 
		OR=16, RETURN=17, INT_CONST=18, CHAR_CONST=19, COMMENT=20, DIRECTIVE=21, 
		ID=22, WS=23;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
			"MULT_DIV_MOD", "ADD_SUB", "MORE_LESS", "EQ_NEQ", "AND", "XOR", "OR", 
			"RETURN", "INT_CONST", "CHAR_CONST", "COMMENT", "DIRECTIVE", "ID", "WS"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'int'", "'main'", "'('", "')'", "'{'", "'}'", "'='", "';'", "'char'", 
			null, null, null, null, "'&'", "'^'", "'|'", "'return'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, "MULT_DIV_MOD", 
			"ADD_SUB", "MORE_LESS", "EQ_NEQ", "AND", "XOR", "OR", "RETURN", "INT_CONST", 
			"CHAR_CONST", "COMMENT", "DIRECTIVE", "ID", "WS"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}


	public ifccLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "ifcc.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\u0004\u0000\u0017\u0094\u0006\uffff\uffff\u0002\u0000\u0007\u0000\u0002"+
		"\u0001\u0007\u0001\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002"+
		"\u0004\u0007\u0004\u0002\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002"+
		"\u0007\u0007\u0007\u0002\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002"+
		"\u000b\u0007\u000b\u0002\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e"+
		"\u0002\u000f\u0007\u000f\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011"+
		"\u0002\u0012\u0007\u0012\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014"+
		"\u0002\u0015\u0007\u0015\u0002\u0016\u0007\u0016\u0001\u0000\u0001\u0000"+
		"\u0001\u0000\u0001\u0000\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0002\u0001\u0002\u0001\u0003\u0001\u0003\u0001\u0004"+
		"\u0001\u0004\u0001\u0005\u0001\u0005\u0001\u0006\u0001\u0006\u0001\u0007"+
		"\u0001\u0007\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\t\u0001\t\u0001"+
		"\n\u0001\n\u0001\u000b\u0001\u000b\u0001\f\u0001\f\u0001\f\u0001\f\u0003"+
		"\fT\b\f\u0001\r\u0001\r\u0001\u000e\u0001\u000e\u0001\u000f\u0001\u000f"+
		"\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010"+
		"\u0001\u0010\u0001\u0011\u0004\u0011d\b\u0011\u000b\u0011\f\u0011e\u0001"+
		"\u0012\u0001\u0012\u0005\u0012j\b\u0012\n\u0012\f\u0012m\t\u0012\u0001"+
		"\u0012\u0001\u0012\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0005"+
		"\u0013u\b\u0013\n\u0013\f\u0013x\t\u0013\u0001\u0013\u0001\u0013\u0001"+
		"\u0013\u0001\u0013\u0001\u0013\u0001\u0014\u0001\u0014\u0005\u0014\u0081"+
		"\b\u0014\n\u0014\f\u0014\u0084\t\u0014\u0001\u0014\u0001\u0014\u0001\u0014"+
		"\u0001\u0014\u0001\u0015\u0001\u0015\u0005\u0015\u008c\b\u0015\n\u0015"+
		"\f\u0015\u008f\t\u0015\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016"+
		"\u0003kv\u0082\u0000\u0017\u0001\u0001\u0003\u0002\u0005\u0003\u0007\u0004"+
		"\t\u0005\u000b\u0006\r\u0007\u000f\b\u0011\t\u0013\n\u0015\u000b\u0017"+
		"\f\u0019\r\u001b\u000e\u001d\u000f\u001f\u0010!\u0011#\u0012%\u0013\'"+
		"\u0014)\u0015+\u0016-\u0017\u0001\u0000\u0007\u0003\u0000%%**//\u0002"+
		"\u0000++--\u0002\u0000<<>>\u0001\u000009\u0003\u0000AZ__az\u0004\u0000"+
		"09AZ__az\u0003\u0000\t\n\r\r  \u0099\u0000\u0001\u0001\u0000\u0000\u0000"+
		"\u0000\u0003\u0001\u0000\u0000\u0000\u0000\u0005\u0001\u0000\u0000\u0000"+
		"\u0000\u0007\u0001\u0000\u0000\u0000\u0000\t\u0001\u0000\u0000\u0000\u0000"+
		"\u000b\u0001\u0000\u0000\u0000\u0000\r\u0001\u0000\u0000\u0000\u0000\u000f"+
		"\u0001\u0000\u0000\u0000\u0000\u0011\u0001\u0000\u0000\u0000\u0000\u0013"+
		"\u0001\u0000\u0000\u0000\u0000\u0015\u0001\u0000\u0000\u0000\u0000\u0017"+
		"\u0001\u0000\u0000\u0000\u0000\u0019\u0001\u0000\u0000\u0000\u0000\u001b"+
		"\u0001\u0000\u0000\u0000\u0000\u001d\u0001\u0000\u0000\u0000\u0000\u001f"+
		"\u0001\u0000\u0000\u0000\u0000!\u0001\u0000\u0000\u0000\u0000#\u0001\u0000"+
		"\u0000\u0000\u0000%\u0001\u0000\u0000\u0000\u0000\'\u0001\u0000\u0000"+
		"\u0000\u0000)\u0001\u0000\u0000\u0000\u0000+\u0001\u0000\u0000\u0000\u0000"+
		"-\u0001\u0000\u0000\u0000\u0001/\u0001\u0000\u0000\u0000\u00033\u0001"+
		"\u0000\u0000\u0000\u00058\u0001\u0000\u0000\u0000\u0007:\u0001\u0000\u0000"+
		"\u0000\t<\u0001\u0000\u0000\u0000\u000b>\u0001\u0000\u0000\u0000\r@\u0001"+
		"\u0000\u0000\u0000\u000fB\u0001\u0000\u0000\u0000\u0011D\u0001\u0000\u0000"+
		"\u0000\u0013I\u0001\u0000\u0000\u0000\u0015K\u0001\u0000\u0000\u0000\u0017"+
		"M\u0001\u0000\u0000\u0000\u0019S\u0001\u0000\u0000\u0000\u001bU\u0001"+
		"\u0000\u0000\u0000\u001dW\u0001\u0000\u0000\u0000\u001fY\u0001\u0000\u0000"+
		"\u0000![\u0001\u0000\u0000\u0000#c\u0001\u0000\u0000\u0000%g\u0001\u0000"+
		"\u0000\u0000\'p\u0001\u0000\u0000\u0000)~\u0001\u0000\u0000\u0000+\u0089"+
		"\u0001\u0000\u0000\u0000-\u0090\u0001\u0000\u0000\u0000/0\u0005i\u0000"+
		"\u000001\u0005n\u0000\u000012\u0005t\u0000\u00002\u0002\u0001\u0000\u0000"+
		"\u000034\u0005m\u0000\u000045\u0005a\u0000\u000056\u0005i\u0000\u0000"+
		"67\u0005n\u0000\u00007\u0004\u0001\u0000\u0000\u000089\u0005(\u0000\u0000"+
		"9\u0006\u0001\u0000\u0000\u0000:;\u0005)\u0000\u0000;\b\u0001\u0000\u0000"+
		"\u0000<=\u0005{\u0000\u0000=\n\u0001\u0000\u0000\u0000>?\u0005}\u0000"+
		"\u0000?\f\u0001\u0000\u0000\u0000@A\u0005=\u0000\u0000A\u000e\u0001\u0000"+
		"\u0000\u0000BC\u0005;\u0000\u0000C\u0010\u0001\u0000\u0000\u0000DE\u0005"+
		"c\u0000\u0000EF\u0005h\u0000\u0000FG\u0005a\u0000\u0000GH\u0005r\u0000"+
		"\u0000H\u0012\u0001\u0000\u0000\u0000IJ\u0007\u0000\u0000\u0000J\u0014"+
		"\u0001\u0000\u0000\u0000KL\u0007\u0001\u0000\u0000L\u0016\u0001\u0000"+
		"\u0000\u0000MN\u0007\u0002\u0000\u0000N\u0018\u0001\u0000\u0000\u0000"+
		"OP\u0005=\u0000\u0000PT\u0005=\u0000\u0000QR\u0005!\u0000\u0000RT\u0005"+
		"=\u0000\u0000SO\u0001\u0000\u0000\u0000SQ\u0001\u0000\u0000\u0000T\u001a"+
		"\u0001\u0000\u0000\u0000UV\u0005&\u0000\u0000V\u001c\u0001\u0000\u0000"+
		"\u0000WX\u0005^\u0000\u0000X\u001e\u0001\u0000\u0000\u0000YZ\u0005|\u0000"+
		"\u0000Z \u0001\u0000\u0000\u0000[\\\u0005r\u0000\u0000\\]\u0005e\u0000"+
		"\u0000]^\u0005t\u0000\u0000^_\u0005u\u0000\u0000_`\u0005r\u0000\u0000"+
		"`a\u0005n\u0000\u0000a\"\u0001\u0000\u0000\u0000bd\u0007\u0003\u0000\u0000"+
		"cb\u0001\u0000\u0000\u0000de\u0001\u0000\u0000\u0000ec\u0001\u0000\u0000"+
		"\u0000ef\u0001\u0000\u0000\u0000f$\u0001\u0000\u0000\u0000gk\u0005\'\u0000"+
		"\u0000hj\t\u0000\u0000\u0000ih\u0001\u0000\u0000\u0000jm\u0001\u0000\u0000"+
		"\u0000kl\u0001\u0000\u0000\u0000ki\u0001\u0000\u0000\u0000ln\u0001\u0000"+
		"\u0000\u0000mk\u0001\u0000\u0000\u0000no\u0005\'\u0000\u0000o&\u0001\u0000"+
		"\u0000\u0000pq\u0005/\u0000\u0000qr\u0005*\u0000\u0000rv\u0001\u0000\u0000"+
		"\u0000su\t\u0000\u0000\u0000ts\u0001\u0000\u0000\u0000ux\u0001\u0000\u0000"+
		"\u0000vw\u0001\u0000\u0000\u0000vt\u0001\u0000\u0000\u0000wy\u0001\u0000"+
		"\u0000\u0000xv\u0001\u0000\u0000\u0000yz\u0005*\u0000\u0000z{\u0005/\u0000"+
		"\u0000{|\u0001\u0000\u0000\u0000|}\u0006\u0013\u0000\u0000}(\u0001\u0000"+
		"\u0000\u0000~\u0082\u0005#\u0000\u0000\u007f\u0081\t\u0000\u0000\u0000"+
		"\u0080\u007f\u0001\u0000\u0000\u0000\u0081\u0084\u0001\u0000\u0000\u0000"+
		"\u0082\u0083\u0001\u0000\u0000\u0000\u0082\u0080\u0001\u0000\u0000\u0000"+
		"\u0083\u0085\u0001\u0000\u0000\u0000\u0084\u0082\u0001\u0000\u0000\u0000"+
		"\u0085\u0086\u0005\n\u0000\u0000\u0086\u0087\u0001\u0000\u0000\u0000\u0087"+
		"\u0088\u0006\u0014\u0000\u0000\u0088*\u0001\u0000\u0000\u0000\u0089\u008d"+
		"\u0007\u0004\u0000\u0000\u008a\u008c\u0007\u0005\u0000\u0000\u008b\u008a"+
		"\u0001\u0000\u0000\u0000\u008c\u008f\u0001\u0000\u0000\u0000\u008d\u008b"+
		"\u0001\u0000\u0000\u0000\u008d\u008e\u0001\u0000\u0000\u0000\u008e,\u0001"+
		"\u0000\u0000\u0000\u008f\u008d\u0001\u0000\u0000\u0000\u0090\u0091\u0007"+
		"\u0006\u0000\u0000\u0091\u0092\u0001\u0000\u0000\u0000\u0092\u0093\u0006"+
		"\u0016\u0001\u0000\u0093.\u0001\u0000\u0000\u0000\u0007\u0000Sekv\u0082"+
		"\u008d\u0002\u0006\u0000\u0000\u0000\u0001\u0000";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}