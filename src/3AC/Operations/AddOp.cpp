#include "AddOp.h"

void AddOp::produceMips()
{
// TODO 
// Move code commont to all the operations or some of the operations of
// the same type to the parent class or some other method
//


	DescriptorTable& dTable = DescriptorTable::getInstance();
	MipsCode& mCode = MipsCode::getInstance();

	mCode.writeToTextSection( "# >>>>>>>>>>>>>>> AddOp Text Start", "" );

	// op1->operandType // TACOperandType enum

	// ID
	unsigned int op1Id = op1->getUniqueId();
	unsigned int op2Id = op2->getUniqueId();
	unsigned int op3Id = op3->getUniqueId();

	// Type
	Type* typeOfOp1 = op1->getType();
	Type* typeOfOp2 = op2->getType();
	Type* typeOfOp3 = op3->getType();

	// ID and Type
	MipsVariable opResult( typeOfOp1, op1Id );
	MipsVariable opArg2( typeOfOp2, op2Id );
	MipsVariable opArg3( typeOfOp3, op3Id );

	// reserve the memory
	mCode.writeToDataSection( opResult, "AddResult" );
	mCode.writeToDataSection( opArg2, "AddArgument1" );
	mCode.writeToDataSection( opArg3, "AddArgument2" );

	// 
	// Get the registers for these guys	
	//
	// ???????????????????????????????????????????????????????????????????? 
	// should getRegister() automatically load the register the opResult/opArg2/opArg3 lable 
	// ???????????????????????????????????????????????????????????????????? 
	// RegisterInfo r1 = dTable.getRegister( opResult, false );  // r1=Result so no need to load opResult before the operation(addition)
	RegisterInfo r1 = dTable.getRegister( opResult );
	RegisterInfo r2 = dTable.getRegister( opArg2   );
	RegisterInfo r3 = dTable.getRegister( opArg3   );

	// ???????????????????????????????????????????????????????????????????
	//
	// If new registers, need to load from the static global memory
	//
	// Should be done here or inside of getRegister ?
	//
	if ( r1.isNew() ) {
	}
	if ( r2.isNew() ) {
		mCode.writeToTextSection(
				"lw "+ r2.getRegister().toString()+","+ opArg2.toDLabel().toString(),
				"Loading data for register of first argument"
		);	
	}
	if ( r3.isNew() ) {
		mCode.writeToTextSection(
				"lw "+ r3.getRegister().toString()+","+ opArg3.toDLabel().toString(), 
				"Loading data for register of second argument"
		);	
	}

	int typeEnumOfOp1 = typeOfOp1->getType();

	// Do not allow casting
	// if (typeEnumOfOp1 != typeEnumOfOp2 ) {
	// 	throw "AddOp : Type Mismatch";	
	// }

	//
	// mips operation
	//
	std::string mipsOperation;

	// Addition
	if ( type == AdditiveExpressionNode::Add ) {
		switch (typeEnumOfOp1) {
			case Type::uChar:
				throw "Addop : this type not implemented ";
				break;
			case Type::uShort:
				throw "Addop : this type not implemented ";
				break;
			case Type::uInt:
				throw "Addop : this type not implemented ";
				break;
			case Type::uLong:
				throw "Addop : this type not implemented ";
				break;
			case Type::uLongLong:
				throw "Addop : this type not implemented ";
				break;
			case Type::Char:
				throw "Addop : this type not implemented ";
				break;
			case Type::Short:
				throw "Addop : this type not implemented ";
				break;
			case Type::Int:
				mipsOperation="add";
				break;
			case Type::Long:
				throw "Addop : this type not implemented ";
				break;
			case Type::LongLong:
				throw "Addop : this type not implemented ";
				break;
			case Type::Float:
				mipsOperation="add.s";
				break;
			case Type::Double:
				mipsOperation="add.d";
				break;
		}

	// Subtraction
	} else {
		switch (typeEnumOfOp1) {
			case Type::uChar:
				throw "Addop : this type not implemented ";
				break;
			case Type::uShort:
				throw "Addop : this type not implemented ";
				break;
			case Type::uInt:
				throw "Addop : this type not implemented ";
				break;
			case Type::uLong:
				throw "Addop : this type not implemented ";
				break;
			case Type::uLongLong:
				throw "Addop : this type not implemented ";
				break;
			case Type::Char:
				throw "Addop : this type not implemented ";
				break;
			case Type::Short:
				throw "Addop : this type not implemented ";
				break;
			case Type::Int:
				mipsOperation="sub";;
				break;
			case Type::Long:
				throw "Addop : this type not implemented ";
				break;
			case Type::LongLong:
				throw "Addop : this type not implemented ";
				break;
			case Type::Float:
				mipsOperation="sub.s";
				break;
			case Type::Double:
				mipsOperation="sub.d";
				break;
		}
			
	}

	// Convert Registers Obtained to Strings like "$5"
	std::string r1str = r1.getRegister().toString();
	std::string r2str = r2.getRegister().toString();
	std::string r3str = r3.getRegister().toString();

	mCode.writeToTextSection( 
			mipsOperation + " " + r1str + "," + r2str + "," + r3str, 
			"AddOp " 
	);
	dTable.store(r1.getRegister(), opResult, " AddOp: loading result to memory");

	mCode.writeToTextSection( "# <<<<<<<<<<<<<<< AddOp End ", "" );

}
