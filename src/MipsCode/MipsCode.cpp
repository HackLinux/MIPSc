#include "MipsCode.h"
#include <iostream>
#include "IndentInfo.h"
#include <sstream>
#include <vector>
#include <algorithm>
#include "MipsData.h"
#include "MipsError.h"
#include <fstream>


// ---------------------------------------------------------------------------
// Manifest
//
//		MipsCode
//		MipsCode::Data
//		MipsCode::Text
//		MipsCode::Misc

// ---------------------------------------------------------------------------
// MipsCode

void MipsCode::dump(std::string filename)
// see dump()
{
	using namespace std;
	std::ofstream ofs(filename);
	if (!ofs) {
		std::cerr << filename << " cannot be opened." << std::endl;
	}
	else {
		std::ostringstream oss;
		oss << ".data" << endl;
		for (auto dataEntry : dataSection ) {
			if( dataEntry.kind.kind != DKind::Label )
				oss << dataEntry.toString() << endl;
		}

		// Divider
		oss << "# --------------------------------------------" << endl;	

		// Text Section
		oss << ".text" << endl;
		for (size_t index = 0; index < textSection.size(); index++) {
			oss << textSection[index].toString() << endl;
		}
		ofs << oss.str();
	}
	ofs.close();
}



std::vector<DLabel> MipsCode::allLabels;

MipsCode::MipsCode()
{}
void MipsCode::
writeToDataSection(MipsVariable mipsVar, MipsComment com) // write data entry without initialization
{
	DLabel label = mipsVar.toDLabel();
	DKind kind = mipsVar.toDKind();

	// TODO Check if lable is not duplicate Label
	// Error if the label already exists 
	typedef std::vector<DLabel>::iterator Iter;
	Iter iter = std::find( allLabels.begin(), allLabels.end(), label) ;
	if ( iter != MipsCode::allLabels.end() ) {
		// throw MipsError( "Same Label Generated in MIPS" );
		std::cout << "MipsWarn( Same Label Generated in MIPS ) " << std::endl;
	} else {
		allLabels.push_back(label);
		dataSection.push_back( Data( label, kind , com ));
	}
}

/*
void MipsCode::
writeToDataSection(DLabel label, DKind kind, DInit init, Comment com) // write data entry
{
	// TODO : check label does not exist 
	DKindInit dkindinit(kind, init);
	dataSection.push_back( Data( label, dkindinit, com ) );
}
*/

/*
void MipsCode::
writeToDataSection(DLabel label, DKind kind, Comment com) // write data entry
{
	// Error if the label already exists 
	// TODO : Merge with above code : identical
	typedef std::vector<DLabel>::iterator Iter;
	Iter iter = std::find( MipsCode::allLabels.begin(), MipsCode::allLabels.end(), label) ;
	if ( iter != allLabels.end() ) {
		throw MipsError( "Same Label Generated in MIPS" );
	}
	allLabels.push_back(label);

	// TODO : check label does not exist 
	dataSection.push_back( Data( label, kind, com ) );
}
*/

void MipsCode::
writeToTextSection(Code code, MipsComment com) // write text entry
{
	textSection.push_back(Text(code, com));
}

void MipsCode::dump() // Dump MIPS code
{
	using namespace std;
	ostringstream oss;

	// TODO
	// push back extra indent info here

	// 
	// Data Section
	//
	oss << ".data" << endl;
	for (auto dataEntry : dataSection ) {
		oss << dataEntry.toString() << endl;
	}

	// Devider
	oss << "--------------------------------------------" << endl;	

	// 
	// Text Section
	//
	oss << ".text" << endl;
	// size_t tabs = 0;
	// size_t curIndentInfoIndex = 0;
	for (size_t index = 0; index < textSection.size(); index++) {

		// update indent
		// if (index == iss[curIndentInfoIndex].textIndex) {
		// 	tabs+=iss[curIndentInfoIndex].getIndent();
		// 	curIndentInfoIndex++; // TODO seg fault unless push back extra IndentInfo
		// }

		// indent
		// for (size_t i = 0; i<tabs; i++) oss << "\t";

		// text
		oss << textSection[index].toString() << endl;
	}

	std::cout << oss.str();
}



// ---------------------------------------------------------------------------
// Data

MipsCode::Data::Data(DLabel label, DKind kind, MipsComment com)
	: label(label), kind(kind), com(com)
{}

MipsCode::Data::Data(DLabel label, DKindInit kindInit, MipsComment com)
	: label(label), kind(kindInit.getKind()), init(kindInit.getInit()), com(com)
{}

std::string MipsCode::Data::toString()
{
	std::ostringstream oss;
	oss << label.toString() 
		<< ": "
		<< kind.toString()
		<< " # "
		<< com;
	return oss.str();
}

// ---------------------------------------------------------------------------
// Text
MipsCode::Text::Text(Code code, MipsComment com)
	: code(code), com(com)
{}

std::string MipsCode::Text::toString()
{
	std::ostringstream oss;
	oss << code << " # " << com;
	return oss.str();
}

// ---------------------------------------------------------------------------
// Misc

void MipsCode::clear()
{
	indentLevel = 0;
	allLabels  .clear();
	dataSection.clear();
	textSection.clear();
}
