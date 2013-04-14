/*
 * SelectionStatementNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef SELECTIONSTATEMENTNODE_H_
#define SELECTIONSTATEMENTNODE_H_

#include "ExpressionNode.h"
#include "StatementNode.h"

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>

class StatementNode;

class SelectionStatementNode : public Node
{

public:

	enum SelectionStatementType
	{
		If,
		IfElse,
		Switch
	};

	SelectionStatementNode( ExpressionNode* _condition , StatementNode* _statement, SelectionStatementType _type );

	SelectionStatementNode( ExpressionNode* _condition , StatementNode* _statement, StatementNode* _elseStatement );

	std::vector< Operation* >* toOperations();

	std::string getNodeTypeAsString();

	ExpressionNode* condition;

	StatementNode* statement;

	StatementNode* elseStatement;

	SelectionStatementType type;

};


#endif /* SELECTIONSTATEMENTNODE_H_ */