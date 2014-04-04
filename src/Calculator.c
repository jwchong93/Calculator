#include "Calculator.h"
#include "Stack.h"
#include "Token.h"
#include <malloc.h>
#include "CException.h"
#include "Error.h"


void evaluateAllOperatorsOnStack(Stack *operatorStack,Stack *dataStack)
{
	OperatorToken *newToken =(OperatorToken*) pop(operatorStack);
	while(newToken!=NULL)
	{
		evaluateOperator(dataStack,newToken);
		newToken =(OperatorToken*) pop(operatorStack);
	}
}

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
				}
				push(operatorStack,operator);
			
		
	}
	
}

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

	answer = createNumberToken(result);
	push(dataStack,answer);
	free(num1);
	free(num2);
}