
// Generated from ifcc.g4 by ANTLR 4.13.1


#include "ifccLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct IfccLexerStaticData final {
  IfccLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  IfccLexerStaticData(const IfccLexerStaticData&) = delete;
  IfccLexerStaticData(IfccLexerStaticData&&) = delete;
  IfccLexerStaticData& operator=(const IfccLexerStaticData&) = delete;
  IfccLexerStaticData& operator=(IfccLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag ifcclexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
IfccLexerStaticData *ifcclexerLexerStaticData = nullptr;

void ifcclexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (ifcclexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(ifcclexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<IfccLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
      "MULT_DIV_MOD", "ADD_SUB", "MORE_LESS", "EQ_NEQ", "AND", "XOR", "OR", 
      "RETURN", "INT_CONST", "CHAR_CONST", "COMMENT", "DIRECTIVE", "ID", 
      "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'int'", "'main'", "'('", "')'", "'{'", "'}'", "'='", "';'", "'char'", 
      "", "", "", "", "'&'", "'^'", "'|'", "'return'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "MULT_DIV_MOD", "ADD_SUB", 
      "MORE_LESS", "EQ_NEQ", "AND", "XOR", "OR", "RETURN", "INT_CONST", 
      "CHAR_CONST", "COMMENT", "DIRECTIVE", "ID", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,23,148,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,3,1,3,1,
  	4,1,4,1,5,1,5,1,6,1,6,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,10,1,10,1,
  	11,1,11,1,12,1,12,1,12,1,12,3,12,84,8,12,1,13,1,13,1,14,1,14,1,15,1,15,
  	1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,17,4,17,100,8,17,11,17,12,17,101,
  	1,18,1,18,5,18,106,8,18,10,18,12,18,109,9,18,1,18,1,18,1,19,1,19,1,19,
  	1,19,5,19,117,8,19,10,19,12,19,120,9,19,1,19,1,19,1,19,1,19,1,19,1,20,
  	1,20,5,20,129,8,20,10,20,12,20,132,9,20,1,20,1,20,1,20,1,20,1,21,1,21,
  	5,21,140,8,21,10,21,12,21,143,9,21,1,22,1,22,1,22,1,22,3,107,118,130,
  	0,23,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,
  	27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,1,0,7,3,0,
  	37,37,42,42,47,47,2,0,43,43,45,45,2,0,60,60,62,62,1,0,48,57,3,0,65,90,
  	95,95,97,122,4,0,48,57,65,90,95,95,97,122,3,0,9,10,13,13,32,32,153,0,
  	1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,
  	0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,
  	23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,
  	0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,
  	0,0,45,1,0,0,0,1,47,1,0,0,0,3,51,1,0,0,0,5,56,1,0,0,0,7,58,1,0,0,0,9,
  	60,1,0,0,0,11,62,1,0,0,0,13,64,1,0,0,0,15,66,1,0,0,0,17,68,1,0,0,0,19,
  	73,1,0,0,0,21,75,1,0,0,0,23,77,1,0,0,0,25,83,1,0,0,0,27,85,1,0,0,0,29,
  	87,1,0,0,0,31,89,1,0,0,0,33,91,1,0,0,0,35,99,1,0,0,0,37,103,1,0,0,0,39,
  	112,1,0,0,0,41,126,1,0,0,0,43,137,1,0,0,0,45,144,1,0,0,0,47,48,5,105,
  	0,0,48,49,5,110,0,0,49,50,5,116,0,0,50,2,1,0,0,0,51,52,5,109,0,0,52,53,
  	5,97,0,0,53,54,5,105,0,0,54,55,5,110,0,0,55,4,1,0,0,0,56,57,5,40,0,0,
  	57,6,1,0,0,0,58,59,5,41,0,0,59,8,1,0,0,0,60,61,5,123,0,0,61,10,1,0,0,
  	0,62,63,5,125,0,0,63,12,1,0,0,0,64,65,5,61,0,0,65,14,1,0,0,0,66,67,5,
  	59,0,0,67,16,1,0,0,0,68,69,5,99,0,0,69,70,5,104,0,0,70,71,5,97,0,0,71,
  	72,5,114,0,0,72,18,1,0,0,0,73,74,7,0,0,0,74,20,1,0,0,0,75,76,7,1,0,0,
  	76,22,1,0,0,0,77,78,7,2,0,0,78,24,1,0,0,0,79,80,5,61,0,0,80,84,5,61,0,
  	0,81,82,5,33,0,0,82,84,5,61,0,0,83,79,1,0,0,0,83,81,1,0,0,0,84,26,1,0,
  	0,0,85,86,5,38,0,0,86,28,1,0,0,0,87,88,5,94,0,0,88,30,1,0,0,0,89,90,5,
  	124,0,0,90,32,1,0,0,0,91,92,5,114,0,0,92,93,5,101,0,0,93,94,5,116,0,0,
  	94,95,5,117,0,0,95,96,5,114,0,0,96,97,5,110,0,0,97,34,1,0,0,0,98,100,
  	7,3,0,0,99,98,1,0,0,0,100,101,1,0,0,0,101,99,1,0,0,0,101,102,1,0,0,0,
  	102,36,1,0,0,0,103,107,5,39,0,0,104,106,9,0,0,0,105,104,1,0,0,0,106,109,
  	1,0,0,0,107,108,1,0,0,0,107,105,1,0,0,0,108,110,1,0,0,0,109,107,1,0,0,
  	0,110,111,5,39,0,0,111,38,1,0,0,0,112,113,5,47,0,0,113,114,5,42,0,0,114,
  	118,1,0,0,0,115,117,9,0,0,0,116,115,1,0,0,0,117,120,1,0,0,0,118,119,1,
  	0,0,0,118,116,1,0,0,0,119,121,1,0,0,0,120,118,1,0,0,0,121,122,5,42,0,
  	0,122,123,5,47,0,0,123,124,1,0,0,0,124,125,6,19,0,0,125,40,1,0,0,0,126,
  	130,5,35,0,0,127,129,9,0,0,0,128,127,1,0,0,0,129,132,1,0,0,0,130,131,
  	1,0,0,0,130,128,1,0,0,0,131,133,1,0,0,0,132,130,1,0,0,0,133,134,5,10,
  	0,0,134,135,1,0,0,0,135,136,6,20,0,0,136,42,1,0,0,0,137,141,7,4,0,0,138,
  	140,7,5,0,0,139,138,1,0,0,0,140,143,1,0,0,0,141,139,1,0,0,0,141,142,1,
  	0,0,0,142,44,1,0,0,0,143,141,1,0,0,0,144,145,7,6,0,0,145,146,1,0,0,0,
  	146,147,6,22,1,0,147,46,1,0,0,0,7,0,83,101,107,118,130,141,2,6,0,0,0,
  	1,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  ifcclexerLexerStaticData = staticData.release();
}

}

ifccLexer::ifccLexer(CharStream *input) : Lexer(input) {
  ifccLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *ifcclexerLexerStaticData->atn, ifcclexerLexerStaticData->decisionToDFA, ifcclexerLexerStaticData->sharedContextCache);
}

ifccLexer::~ifccLexer() {
  delete _interpreter;
}

std::string ifccLexer::getGrammarFileName() const {
  return "ifcc.g4";
}

const std::vector<std::string>& ifccLexer::getRuleNames() const {
  return ifcclexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& ifccLexer::getChannelNames() const {
  return ifcclexerLexerStaticData->channelNames;
}

const std::vector<std::string>& ifccLexer::getModeNames() const {
  return ifcclexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& ifccLexer::getVocabulary() const {
  return ifcclexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ifccLexer::getSerializedATN() const {
  return ifcclexerLexerStaticData->serializedATN;
}

const atn::ATN& ifccLexer::getATN() const {
  return *ifcclexerLexerStaticData->atn;
}




void ifccLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  ifcclexerLexerInitialize();
#else
  ::antlr4::internal::call_once(ifcclexerLexerOnceFlag, ifcclexerLexerInitialize);
#endif
}
