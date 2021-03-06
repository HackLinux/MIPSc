/*
 * LogicalOrExpressionNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef LOGICALOREXPRESSIONNODE_H_
#define LOGICALOREXPRESSIONNODE_H_

#include "LogicalAndExpressionNode.h"

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>

class LogicalAndExpressionNode;

class LogicalOrExpressionNode : public Node
{

public:


	LogicalOrExpressionNode( LogicalAndExpressionNode* _logicalAndExpression );

	LogicalOrExpressionNode( LogicalOrExpressionNode* _logicalOrExpression ,
			LogicalAndExpressionNode* _logicalAndExpression );

	ASTData* toOperations();
	std::string getNodeTypeAsString();

	LogicalOrExpressionNode* logicalOrExpression = 0;
	LogicalAndExpressionNode* logicalAndExpression = 0;

};


#endif /* LOGICALOREXPRESSIONNODE_H_ */
