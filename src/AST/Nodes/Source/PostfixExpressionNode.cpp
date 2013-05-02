/*
 * PostfixExpressionNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "PostfixExpressionNode.h"

#include "ArrayType.h"

//Primary Expression
PostfixExpressionNode::PostfixExpressionNode( PrimaryExpressionNode* _primaryExpression )
	: primaryExpression( _primaryExpression )
{
	type = PrimaryExpression;
}

//Array Access
PostfixExpressionNode::PostfixExpressionNode( PostfixExpressionNode* _postfixExpression , ExpressionNode* arrayExpression )
	: postfixExpression( _postfixExpression )
{
	type = ArrayAccess;
}

//Function Call, No arguments =OR= Increment =OR= Dcrement
PostfixExpressionNode::PostfixExpressionNode( PostfixExpressionNode* _postfixExpression , PostfixExpressionType _type )
	: postfixExpression( _postfixExpression ), type(_type)
{

}

//Function Call, w/ arguments
PostfixExpressionNode::PostfixExpressionNode( PostfixExpressionNode* _postfixExpression , ArgExpressionListNode* _argExpressionList )
	: postfixExpression( _postfixExpression ), argExpressionList( _argExpressionList )
{
	type = FunctionCall;
}

//Direct Member Access
PostfixExpressionNode::PostfixExpressionNode( PostfixExpressionNode* _postfixExpression , IdentifierNode* _memberIdentifier , PostfixExpressionType _type )
	: postfixExpression( _postfixExpression ), memberIdentifier( _memberIdentifier ), type( _type )
{
	type = DirectMemberAccess;
}

ASTData* PostfixExpressionNode::toOperations()
{
	ASTData* data = new ASTData();

	std::vector< Operation* >* operations = new std::vector< Operation* >();

	if( type ==  PrimaryExpression )

		return primaryExpression->toOperations();

	if( type == ArrayAccess )
	{
		//Various errors will be thrown here (eg: accessing a non-array type)
		ASTData* arrayData = postfixExpression->toOperations();

		Symbol* arrayId = arrayData->result;

		Type* arrayType = arrayId->symbolType;

		ArrayType* array = (ArrayType*) arrayType;

		// TODO: finish this...

	}

	if( type == FunctionCall )
	{
		//TODO: Implement function calls
		return data;

	}

	if( type == DirectMemberAccess )
	{



	}

	if( type == PointerMemberAccess )
	{



	}

	if( type == Increment )
	{



	}

	if( type == Decrement )
	{



	}

	return data;
}

std::string PostfixExpressionNode::getNodeTypeAsString()
{

	return std::string( "postfix expression" );

}

