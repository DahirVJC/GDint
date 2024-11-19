
// Generated from NewLexer/Lexer.g4 by ANTLR 4.13.2


#include "Lexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct LexerStaticData final {
  LexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  LexerStaticData(const LexerStaticData&) = delete;
  LexerStaticData(LexerStaticData&&) = delete;
  LexerStaticData& operator=(const LexerStaticData&) = delete;
  LexerStaticData& operator=(LexerStaticData&&) = delete;

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

::antlr4::internal::OnceFlag lexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<LexerStaticData> lexerLexerStaticData = nullptr;

void lexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (lexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(lexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<LexerStaticData>(
    std::vector<std::string>{
      "IDENTIFIER", "CONSTANT", "KEYWORD", "PUNCTUATION", "OPERATOR", "STRING", 
      "DIGIT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
    },
    std::vector<std::string>{
      "", "IDENTIFIER", "CONSTANT", "KEYWORD", "PUNCTUATION", "OPERATOR", 
      "STRING"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,6,112,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,1,0,1,0,5,0,18,8,0,10,0,12,0,21,9,0,1,1,3,1,24,8,1,1,1,4,1,27,8,1,11,
  	1,12,1,28,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,3,2,86,8,2,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,
  	4,1,4,1,4,3,4,100,8,4,1,5,1,5,5,5,104,8,5,10,5,12,5,107,9,5,1,5,1,5,1,
  	6,1,6,1,105,0,7,1,1,3,2,5,3,7,4,9,5,11,6,13,0,1,0,6,3,0,65,90,95,95,97,
  	122,2,0,43,43,45,45,1,0,48,57,5,0,10,10,32,32,34,35,40,41,44,44,4,0,42,
  	43,45,45,47,47,61,61,3,0,33,33,60,60,62,63,127,0,1,1,0,0,0,0,3,1,0,0,
  	0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,1,15,1,0,0,0,3,23,
  	1,0,0,0,5,85,1,0,0,0,7,87,1,0,0,0,9,99,1,0,0,0,11,101,1,0,0,0,13,110,
  	1,0,0,0,15,19,7,0,0,0,16,18,7,0,0,0,17,16,1,0,0,0,18,21,1,0,0,0,19,17,
  	1,0,0,0,19,20,1,0,0,0,20,2,1,0,0,0,21,19,1,0,0,0,22,24,7,1,0,0,23,22,
  	1,0,0,0,23,24,1,0,0,0,24,26,1,0,0,0,25,27,7,2,0,0,26,25,1,0,0,0,27,28,
  	1,0,0,0,28,26,1,0,0,0,28,29,1,0,0,0,29,4,1,0,0,0,30,31,5,115,0,0,31,86,
  	5,105,0,0,32,33,5,118,0,0,33,34,5,97,0,0,34,35,5,114,0,0,35,36,5,105,
  	0,0,36,37,5,97,0,0,37,38,5,98,0,0,38,39,5,108,0,0,39,86,5,101,0,0,40,
  	41,5,101,0,0,41,42,5,110,0,0,42,43,5,116,0,0,43,44,5,111,0,0,44,45,5,
  	110,0,0,45,46,5,99,0,0,46,47,5,101,0,0,47,86,5,115,0,0,48,49,5,115,0,
  	0,49,50,5,105,0,0,50,51,5,110,0,0,51,86,5,111,0,0,52,53,5,102,0,0,53,
  	54,5,105,0,0,54,55,5,110,0,0,55,56,5,115,0,0,56,86,5,105,0,0,57,58,5,
  	112,0,0,58,59,5,117,0,0,59,60,5,98,0,0,60,61,5,108,0,0,61,62,5,105,0,
  	0,62,63,5,99,0,0,63,64,5,97,0,0,64,86,5,114,0,0,65,66,5,111,0,0,66,67,
  	5,98,0,0,67,68,5,116,0,0,68,69,5,101,0,0,69,70,5,110,0,0,70,71,5,101,
  	0,0,71,86,5,114,0,0,72,73,5,99,0,0,73,74,5,97,0,0,74,75,5,109,0,0,75,
  	76,5,98,0,0,76,77,5,105,0,0,77,78,5,97,0,0,78,86,5,114,0,0,79,80,5,98,
  	0,0,80,81,5,111,0,0,81,82,5,114,0,0,82,83,5,114,0,0,83,84,5,97,0,0,84,
  	86,5,114,0,0,85,30,1,0,0,0,85,32,1,0,0,0,85,40,1,0,0,0,85,48,1,0,0,0,
  	85,52,1,0,0,0,85,57,1,0,0,0,85,65,1,0,0,0,85,72,1,0,0,0,85,79,1,0,0,0,
  	86,6,1,0,0,0,87,88,7,3,0,0,88,8,1,0,0,0,89,100,7,4,0,0,90,91,5,61,0,0,
  	91,100,5,61,0,0,92,93,5,42,0,0,93,100,5,42,0,0,94,95,5,124,0,0,95,100,
  	5,124,0,0,96,97,5,38,0,0,97,100,5,38,0,0,98,100,7,5,0,0,99,89,1,0,0,0,
  	99,90,1,0,0,0,99,92,1,0,0,0,99,94,1,0,0,0,99,96,1,0,0,0,99,98,1,0,0,0,
  	100,10,1,0,0,0,101,105,5,39,0,0,102,104,9,0,0,0,103,102,1,0,0,0,104,107,
  	1,0,0,0,105,106,1,0,0,0,105,103,1,0,0,0,106,108,1,0,0,0,107,105,1,0,0,
  	0,108,109,5,39,0,0,109,12,1,0,0,0,110,111,7,2,0,0,111,14,1,0,0,0,7,0,
  	19,23,28,85,99,105,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  lexerLexerStaticData = std::move(staticData);
}

}

Lexer::Lexer(CharStream *input) : Lexer(input) {
  Lexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *lexerLexerStaticData->atn, lexerLexerStaticData->decisionToDFA, lexerLexerStaticData->sharedContextCache);
}

Lexer::~Lexer() {
  delete _interpreter;
}

std::string Lexer::getGrammarFileName() const {
  return "Lexer.g4";
}

const std::vector<std::string>& Lexer::getRuleNames() const {
  return lexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& Lexer::getChannelNames() const {
  return lexerLexerStaticData->channelNames;
}

const std::vector<std::string>& Lexer::getModeNames() const {
  return lexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& Lexer::getVocabulary() const {
  return lexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView Lexer::getSerializedATN() const {
  return lexerLexerStaticData->serializedATN;
}

const atn::ATN& Lexer::getATN() const {
  return *lexerLexerStaticData->atn;
}




void Lexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  lexerLexerInitialize();
#else
  ::antlr4::internal::call_once(lexerLexerOnceFlag, lexerLexerInitialize);
#endif
}
