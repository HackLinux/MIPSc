/*
 * RelationalExpressionNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef RELATIONALEXPRESSIONNODE_H_
#define RELATIONALEXPRESSIONNODE_H_

#include "ShiftExpressionNode.h"

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>

class ShiftExpressionNode;

class RelationalExpressionNode : public Node
{

public:

	enum RelationalExpressionType
	{
		Less,
		Greater,
		LessEqual,
		GreaterEqual
	};

	RelationalExpressionNode( ShiftExpressionNode* _shiftExpression );
	RelationalExpressionNode( RelationalExpressionNode* _relationalExpression ,
			ShiftExpressionNode* _shiftExpression ,
			RelationalExpressionType _type
			);
	std::vector< Operation* >* toOperations();
	std::string getNodeTypeAsString();

	RelationalExpressionNode* relationalExpression;
	ShiftExpressionNode* shiftExpression;
	RelationalExpressionType type;

};


#endif /* RELATIONALEXPRESSIONNODE_H_ */