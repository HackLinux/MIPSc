/*
 * CompoundStatementNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "CompoundStatementNode.h"

CompoundStatementNode::CompoundStatementNode( DeclarationListNode* _declarationList )
	: declarationList( _declarationList )
{

}

CompoundStatementNode::CompoundStatementNode( StatementListNode* _statementList )
		: statementList( _statementList )
{

}

CompoundStatementNode::CompoundStatementNode( DeclarationListNode* _declarationList , StatementListNode* _statementList)
		: declarationList( _declarationList ), statementList( _statementList )
{

}

std::vector< Operation* >* CompoundStatementNode::toOperations()
{
	std::vector< Operation* >* operations;

	return operations;
}

std::string CompoundStatementNode::getNodeTypeAsString()
{

	return std::string( "compound statement" );

}
