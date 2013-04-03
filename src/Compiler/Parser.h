// Generated by Bisonc++ V4.01.00 on Tue, 26 Feb 2013 14:54:58 -0800

//AST Stuff
#include "Node.h"

// $insert baseclass
#include "Parserbase.h"
#include "Scanner.h"
#include "SymbolTable.h"

// #include "BuiltinType.h"
#include "ArrayType.h"
#include "EnumType.h"
#include "PointerType.h"
#include "StructType.h"
#include "TypedefType.h"
#include "UnionType.h"

#include "Declaration.h"

#ifndef Parser_h_included
#define Parser_h_included

#undef Parser
class Parser: public ParserBase
{
		
	
	public:
		int parse();

		Parser( Scanner& s, SymbolTable* table ) 
			: scanner(&s), symbolTable(table)
		{

			declarationMode = true;

		}

		LTYPE__* getLocationStruct()
		{

			return &d_loc__;

		}

		//As the parser encounters things like 'void' 'float' 'char' they accumulate here
		std::vector< std::string > currentTypeSpecifiers;

		void configDebugPrint(
			std::ostream& os, std::string prefix="", std::string postfix="");


	private:
		void error(char const *msg);	// called on (syntax) errors
		int lex();						// returns the next token from the
										// lexical scanner. 
		void print();					// use, e.g., d_token, d_loc
		void debugPrint(std::string);

		struct ParserDebug {
			ParserDebug() 
				: debugOutput(false), debugOutputStream(std::cout.rdbuf())
			{}

			bool debugOutput;
			std::string debugOutputPrefix;
			std::string debugOutputPostfix;
			std::ostream debugOutputStream;
		};

		ParserDebug debug;
		Scanner* scanner;
		SymbolTable* symbolTable;

		Symbol* currentIdentifier;

		Declaration decl;

		int token;

		bool declarationMode;

	private : // functions

		//
		//      Declaration Related
		//
		// 	TODO : create another class for this?
		//		
		void beginDeclarationSection();
		void beginLookupSection();
		void declare();
		void determineType();
		void initializeArray();
		void addValueToArray();
		void pushIdentifier();
		void setDeclarationLocation();;
		void addStorageSpecifier();
		void addTypeSpecifier();
		void setConst();
		void setVolitle();
		void specifyArray();
		void specifyFunction();
		void specifyFunctionCall();
		bool isDeclarationMode();



		bool isUseless(int token);	

		// support functions for parse():
			void executeAction(int ruleNr);
			void errorRecovery();
			int lookup(bool recovery);
			void nextToken();
			void print__();
};


#endif
