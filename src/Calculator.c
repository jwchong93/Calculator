#include "Calculator.h"
#include "Stack.h"
#include "Token.h"
#include <malloc.h>
#include "CException.h"
#include "Error.h"
#include <stdio.h>

/*
	Evaluate expression and return the answer of the expression.
	
	Input:
		expression		contains an expression to be evaluated in text
	Return:
		the computerd result
	Throw:
		ERR_NO_EXPRESSION		exception if expression is an empty text of NULL
		ERR_INVALID_TOKEN		exception if encounter unknown token
		ERR_NOT_DATA			exception if encounter other than Number token
		ERR_NOT_OPERATOR		exception if encounter other than Operator token.
		
*/
int evaluate(char *expression)
{
	Stack *operatorStack = stackNew();
	Stack *dataStack = stackNew();
	Tokenizer *newTokenizer = tokenizerNew(expression);
	Token *tempToken = nextToken(newTokenizer);
	NumberToken *answerToken;
	while(tempToken!=NULL)
	{
		if(tempToken->type==NUMBER_TOKEN)
		{
			push(dataStack,tempToken);
		}
		else if (tempToken->type==OPERATOR_TOKEN)
		{
			tryEvaluateOperatorOnStackThenPush(operatorStack,dataStack,(OperatorToken*)tempToken);
		}
		tempToken = nextToken(newTokenizer);
	}
	evaluateAllOperatorsOnStack(operatorStack,dataStack);
	answerToken = (NumberToken*)pop(dataStack);
	printf("Completed with answer:%d\n",answerToken->value);
	return answerToken->value;
	
}

/*
	Evaluate all operators on the operator stack.
	
	Input:
		dataStack		the stack that carry the data.
		operatorStack	the stack that contain operators.
		
*/
void evaluateAllOperatorsOnStack(Stack *operatorStack,Stack *dataStack)
{
	OperatorToken *newToken =(OperatorToken*) pop(operatorStack);
	while(newToken!=NULL)
	{
		evaluateOperator(dataStack,newToken);
		newToken =(OperatorToken*) pop(operatorStack);
	}
	
}

/*
	Evaluate all operators on the operator stack that bigger precedence
	than the incoming operators.
	
	Input:
		operatorStack 	the stack that carry operators.
		dataStack		the stack that carry the data.
		operator		the operator of the expression.
		
*/
void tryEvaluateOperatorOnStackThenPush(Stack *operatorStack,Stack *dataStack,OperatorToken *operator)
{
	OperatorToken *newToken;
	newToken = (OperatorToken*)pop(operatorStack);
	if(newToken == NULL)
	{
		push(operatorStack,operator);
	}
	else
	{
				while(newToken!=NULL)
				{
					if(operator->precedence>newToken->precedence)
					{
						break;
					}
					else
					{
						evaluateOperator(dataStack,newToken);
					}
					newToken = (OperatorToken*)pop(operatorStack);
				}
				if(newToken!=NULL)
				{
				
					push(operatorStack,newToken);
					printf("operator(Unused):%s\n",newToken->name);
				}
				push(operatorStack,operator);
				printf("operator:%s\n",operator->name);
			
		
	}
	
}

/*
	Evaluate the first two number in dataStack with the input operator.
	Input:
		dataStack		the stack that carry the data.
		operator		the operator of the expression.
		
*/
void evaluateOperator(Stack *dataStack,OperatorToken *operator)
{
	NumberToken *num1;
	NumberToken *num2;
	NumberToken *answer;
	int result;
	num1 = (NumberToken *)pop(dataStack);
	num2 = (NumberToken *)pop(dataStack);
	switch(operator->name[0])
	{
		case '+':
		{
			result = num1->value+num2->value;
			break;
		}
		case '-':
		{
			result = num1->value-num2->value;
			break;
		}
		case '*':
		{
			result = num1->value*num2->value;
			break;
		}
		case '/':
		{
			result = num1->value/num2->value;
			break;
		}
		case '%':
		{
			result = num1->value%num2->value;
			break;
		}
		case '^':
		{
			result = num1->value^num2->value;
			break;
		}
		case '&':
		{
			result = num1->value&num2->value;
			break;
		}
		case '|':
		{
			result = num1->value|num2->value;
			break;
		}
		default:
		{
			Throw(ERR_NOT_OPERATOR);
		}
		
	}
	printf("answer:%d\n",result);
	answer =createNumberToken(result);
	push(dataStack,answer);
	free(num1);
	free(num2);
}