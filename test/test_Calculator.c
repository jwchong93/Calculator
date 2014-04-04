#include "unity.h"
#include "Calculator.h"
#include "mock_Stack.h"
#include "CException.h"
#include "mock_Token.h"
void setUp(void)
{
}

void tearDown(void)
{
}

void xtest_tryEvaluateOperatorOnStackThenPush_will_push_the_token_if_the_stack_is_empty(void)
{
	Stack *operatorStack;
	Stack *dataStack;
	OperatorToken *operator;
	pop_ExpectAndReturn(operatorStack,NULL);
	push_Expect(operatorStack,operator);
	tryEvaluateOperatorOnStackThenPush(operatorStack,dataStack,operator);
}


void test_evaluateOperator_calculate_12_plus_3_(void)
{
	Stack *dataStack;
	OperatorToken operator={.type=OPERATOR_TOKEN,.name ="+",.precedence = 70};
	NumberToken num[]={{.type = NUMBER_TOKEN,.value = 12},{.type = NUMBER_TOKEN,.value = 3}};
	NumberToken answer = {.type = NUMBER_TOKEN,.value = 15};
	pop_ExpectAndReturn(dataStack,&num[0]);
	pop_ExpectAndReturn(dataStack,&num[1]);
	createNumberToken_ExpectAndReturn(15,&answer);
	push_Expect(dataStack,&answer);
	evaluateOperator(dataStack,&operator);
	
}

void test_evaluateOperator_calculate_15_minus_3_(void)
{
	Stack *dataStack;
	OperatorToken operator={.type=OPERATOR_TOKEN,.name ="-",.precedence = 70};
	NumberToken num[]={{.type = NUMBER_TOKEN,.value = 15},{.type = NUMBER_TOKEN,.value = 3}};
	NumberToken answer = {.type = NUMBER_TOKEN,.value = 12};
	pop_ExpectAndReturn(dataStack,&num[0]);
	pop_ExpectAndReturn(dataStack,&num[1]);
	createNumberToken_ExpectAndReturn(12,&answer);
	push_Expect(dataStack,&answer);
	evaluateOperator(dataStack,&operator);
	
}


void test_evaluateOperator_calculate_2_multiply_3_(void)
{
	Stack *dataStack;
	OperatorToken operator={.type=OPERATOR_TOKEN,.name ="*",.precedence = 100};
	NumberToken num[]={{.type = NUMBER_TOKEN,.value = 2},{.type = NUMBER_TOKEN,.value = 3}};
	NumberToken answer = {.type = NUMBER_TOKEN,.value = 6};
	pop_ExpectAndReturn(dataStack,&num[0]);
	pop_ExpectAndReturn(dataStack,&num[1]);
	createNumberToken_ExpectAndReturn(6,&answer);
	push_Expect(dataStack,&answer);
	evaluateOperator(dataStack,&operator);
	
}

void test_evaluateOperator_calculate_9_divide_3_(void)
{
	Stack *dataStack;
	OperatorToken operator={.type=OPERATOR_TOKEN,.name ="/",.precedence = 100};
	NumberToken num[]={{.type = NUMBER_TOKEN,.value = 9},{.type = NUMBER_TOKEN,.value = 3}};
	NumberToken answer = {.type = NUMBER_TOKEN,.value = 3};
	pop_ExpectAndReturn(dataStack,&num[0]);
	pop_ExpectAndReturn(dataStack,&num[1]);
	createNumberToken_ExpectAndReturn(3,&answer);
	push_Expect(dataStack,&answer);
	evaluateOperator(dataStack,&operator);
	
}

void test_evaluateOperator_calculate_15_modulus_4_(void)
{
	Stack *dataStack;
	OperatorToken operator={.type=OPERATOR_TOKEN,.name ="%",.precedence = 100};
	NumberToken num[]={{.type = NUMBER_TOKEN,.value = 15},{.type = NUMBER_TOKEN,.value = 4}};
	NumberToken answer = {.type = NUMBER_TOKEN,.value = 3};
	pop_ExpectAndReturn(dataStack,&num[0]);
	pop_ExpectAndReturn(dataStack,&num[1]);
	createNumberToken_ExpectAndReturn(3,&answer);
	push_Expect(dataStack,&answer);
	evaluateOperator(dataStack,&operator);
	
}

void test_evaluateOperator_calculate_15_XOR_4_(void)
{
	Stack *dataStack;
	OperatorToken operator={.type=OPERATOR_TOKEN,.name ="^",.precedence = 50};
	NumberToken num[]={{.type = NUMBER_TOKEN,.value = 15},{.type = NUMBER_TOKEN,.value = 4}};
	NumberToken answer = {.type = NUMBER_TOKEN,.value = 11};
	pop_ExpectAndReturn(dataStack,&num[0]);
	pop_ExpectAndReturn(dataStack,&num[1]);
	createNumberToken_ExpectAndReturn(11,&answer);
	push_Expect(dataStack,&answer);
	evaluateOperator(dataStack,&operator);
	
}

void test_evaluateOperator_calculate_15_AND_4_(void)
{
	Stack *dataStack;
	OperatorToken operator={.type=OPERATOR_TOKEN,.name ="&",.precedence = 20};
	NumberToken num[]={{.type = NUMBER_TOKEN,.value = 15},{.type = NUMBER_TOKEN,.value = 4}};
	NumberToken answer = {.type = NUMBER_TOKEN,.value = 4};
	pop_ExpectAndReturn(dataStack,&num[0]);
	pop_ExpectAndReturn(dataStack,&num[1]);
	createNumberToken_ExpectAndReturn(4,&answer);
	push_Expect(dataStack,&answer);
	evaluateOperator(dataStack,&operator);
	
}

void test_evaluateOperator_calculate_15_OR_4_(void)
{
	Stack *dataStack;
	OperatorToken operator={.type=OPERATOR_TOKEN,.name ="|",.precedence = 10};
	NumberToken num[]={{.type = NUMBER_TOKEN,.value = 15},{.type = NUMBER_TOKEN,.value = 4}};
	NumberToken answer = {.type = NUMBER_TOKEN,.value = 15};
	pop_ExpectAndReturn(dataStack,&num[0]);
	pop_ExpectAndReturn(dataStack,&num[1]);
	createNumberToken_ExpectAndReturn(15,&answer);
	push_Expect(dataStack,&answer);
	evaluateOperator(dataStack,&operator);
	
}







