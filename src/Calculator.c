#include "Calculator.h"
#include "Stack.h"
#include "Token.h"
#include <malloc.h>
#include "CException.h"
#include "Error.h"
void tryEvaluateOperatorOnStackThenPush(Stack *operatorStack,Stack *dataStack,OperatorToken *operator)
{
	
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