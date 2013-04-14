/*
 * CharConstantNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "CharConstantNode.h"

CharConstantNode::CharConstantNode( char _value ) : value( _value )
{

}

char CharConstantNode::getValue()
{
	return value;
}

std::vector< Operation* >* CharConstantNode::toOperations()
{
	std::vector< Operation* >* operations;

	return operations;
}

std::string CharConstantNode::getNodeTypeAsString()
{

	return std::string( "char constant" );

}
