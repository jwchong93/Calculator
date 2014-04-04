#include "unity.h"
#include "Calculator.h"
#include "mock_Stack.h"
#include "CException.h"
#include "mock_Token.h"
#include "Error.h"

void setUp(void)
{
}

void tearDown(void)
{
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

void test_evaluateOperator_will_throw_error_while_meet_an_unknown_operator(void)
{
	Stack *dataStack;
	ErrorCode exception;
	OperatorToken operator={.type=OPERATOR_TOKEN,.name ="@",.precedence = 10};
	NumberToken num[]={{.type = NUMBER_TOKEN,.value = 15},{.type = NUMBER_TOKEN,.value = 4}};
	pop_ExpectAndReturn(dataStack,&num[0]);
	pop_ExpectAndReturn(dataStack,&num[1]);
	Try
	{
		evaluateOperator(dataStack,&operator);
	}
	Catch(exception)
	{
		TEST_ASSERT_EQUAL(ERR_NOT_OPERATOR,exception);
	}
}

void test_tryEvaluateOperatorOnStackThenPush_will_push_the_token_if_the_stack_is_empty(void)
{
	Stack *operatorStack;
	Stack *dataStack;
	OperatorToken *operator;
	pop_ExpectAndReturn(operatorStack,NULL);
	push_Expect(operatorStack,operator);
	tryEvaluateOperatorOnStackThenPush(operatorStack,dataStack,operator);
}

void test_tryEvaluateOperatorOnStackThenPush_will_push_the_token_if_the_top_operator_of_the_stack_have_a_smaller_precedence(void)
{
	Stack *operatorStack;
	Stack *dataStack;
	OperatorToken operator[]={{.type=OPERATOR_TOKEN,.name ="*",.precedence = 100},{.type=OPERATOR_TOKEN,.name ="+",.precedence = 70}};
	pop_ExpectAndReturn(operatorStack,&operator[1]);
	push_Expect(operatorStack,&operator[1]);
	push_Expect(operatorStack,&operator[0]);
	tryEvaluateOperatorOnStackThenPush(operatorStack,dataStack,&operator[0]);
}

void test_tryEvaluateOperatorOnStackThenPush_will_evaluate_if_the_top_operator_of_the_stack_have_a_bigger_precedence(void)
{
	Stack *operatorStack;
	Stack *dataStack;
	OperatorToken operator[]={{.type=OPERATOR_TOKEN,.name ="+",.precedence = 70},{.type=OPERATOR_TOKEN,.name ="*",.precedence = 100}};
	NumberToken num[]={{.type = NUMBER_TOKEN,.value = 15},{.type = NUMBER_TOKEN,.value = 4}};
	NumberToken answer = {.type = NUMBER_TOKEN,.value = 60};
	pop_ExpectAndReturn(operatorStack,&operator[1]);
	pop_ExpectAndReturn(dataStack,&num[0]);
	pop_ExpectAndReturn(dataStack,&num[1]);
	createNumberToken_ExpectAndReturn(60,&answer);
	push_Expect(dataStack,&answer);
	pop_ExpectAndReturn(operatorStack,NULL);
	push_Expect(operatorStack,&operator[0]);
	tryEvaluateOperatorOnStackThenPush(operatorStack,dataStack,&operator[0]);
}

void test_tryEvaluateOperatorOnStackThenPush_will_evaluate_if_the_top_operator_of_the_stack_have_a_same_precedence(void)
{
	Stack *operatorStack;
	Stack *dataStack;
	OperatorToken operator[]={{.type=OPERATOR_TOKEN,.name ="+",.precedence = 70},{.type=OPERATOR_TOKEN,.name ="+",.precedence = 100}};
	NumberToken num[]={{.type = NUMBER_TOKEN,.value = 15},{.type = NUMBER_TOKEN,.value = 4}};
	NumberToken answer = {.type = NUMBER_TOKEN,.value = 19};
	pop_ExpectAndReturn(operatorStack,&operator[1]);
	pop_ExpectAndReturn(dataStack,&num[0]);
	pop_ExpectAndReturn(dataStack,&num[1]);
	createNumberToken_ExpectAndReturn(19,&answer);
	push_Expect(dataStack,&answer);
	pop_ExpectAndReturn(operatorStack,NULL);
	push_Expect(operatorStack,&operator[0]);
	tryEvaluateOperatorOnStackThenPush(operatorStack,dataStack,&operator[0]);
}

void test_tryEvaluateOperatorOnStackThenPush_will_evaluate_all_the_operation_inside_the_stack_which_have_higher_precedence(void)
{
	//3*4*5+6
	Stack *operatorStack;
	Stack *dataStack;
	OperatorToken operator[]={{.type=OPERATOR_TOKEN,.name ="*",.precedence = 100},{.type=OPERATOR_TOKEN,.name ="*",.precedence = 100},{.type=OPERATOR_TOKEN,.name ="+",.precedence = 70}};
	NumberToken num[]={{.type = NUMBER_TOKEN,.value = 3},{.type = NUMBER_TOKEN,.value = 4},{.type = NUMBER_TOKEN,.value = 5},{.type = NUMBER_TOKEN,.value = 6}};
	NumberToken answer[] ={ {.type = NUMBER_TOKEN,.value =12 }, {.type = NUMBER_TOKEN,.value =60 }};
	pop_ExpectAndReturn(operatorStack,&operator[0]); //for compare purpose
	
	pop_ExpectAndReturn(dataStack,&num[0]); //inside the function
	pop_ExpectAndReturn(dataStack,&num[1]);	//pop out for calculate
	createNumberToken_ExpectAndReturn(12,&answer[0]);
	push_Expect(dataStack,&answer[0]);
	
	pop_ExpectAndReturn(operatorStack,&operator[1]);
	
	pop_ExpectAndReturn(dataStack,&answer[0]);
	pop_ExpectAndReturn(dataStack,&num[2]);
	createNumberToken_ExpectAndReturn(60,&answer[1]);
	push_Expect(dataStack,&answer[1]);
	
	pop_ExpectAndReturn(operatorStack,NULL);
	push_Expect(operatorStack,&operator[2]);
	
	tryEvaluateOperatorOnStackThenPush(operatorStack,dataStack,&operator[2]);
}


void test_tryEvaluateOperatorOnStackThenPush_will_evaluate_the_operations_inside_the_stack_until_lower_precedence_been_met(void)
{
	//3&4*5+6
	Stack *operatorStack;
	Stack *dataStack;
	OperatorToken operator[]={{.type=OPERATOR_TOKEN,.name ="*",.precedence = 100},{.type=OPERATOR_TOKEN,.name ="&",.precedence =10 },{.type=OPERATOR_TOKEN,.name ="+",.precedence = 70}};
	NumberToken num[]={{.type = NUMBER_TOKEN,.value = 3},{.type = NUMBER_TOKEN,.value = 4},{.type = NUMBER_TOKEN,.value = 5},{.type = NUMBER_TOKEN,.value = 6}};
	NumberToken answer[] ={ {.type = NUMBER_TOKEN,.value =20 }, {.type = NUMBER_TOKEN,.value =60 }};
	pop_ExpectAndReturn(operatorStack,&operator[0]); //for compare purpose
	
	pop_ExpectAndReturn(dataStack,&num[1]); //inside the function
	pop_ExpectAndReturn(dataStack,&num[2]);	//pop out for calculate
	createNumberToken_ExpectAndReturn(20,&answer[0]);
	push_Expect(dataStack,&answer[0]);
	
	pop_ExpectAndReturn(operatorStack,&operator[1]);
	push_Expect(operatorStack,&operator[1]);
	push_Expect(operatorStack,&operator[2]);
	
	tryEvaluateOperatorOnStackThenPush(operatorStack,dataStack,&operator[2]);
}

void test_tryEvaluateOperatorOnStackThenPush_will_evaluate_the_operations_inside_the_stack_until_lower_precedence_been_met_for_different_combination(void)
{
	//3^21%5+6
	Stack *operatorStack;
	Stack *dataStack;
	OperatorToken operator[]={{.type=OPERATOR_TOKEN,.name ="%",.precedence = 100},{.type=OPERATOR_TOKEN,.name ="^",.precedence =50 },{.type=OPERATOR_TOKEN,.name ="+",.precedence = 70}};
	NumberToken num[]={{.type = NUMBER_TOKEN,.value = 3},{.type = NUMBER_TOKEN,.value = 21},{.type = NUMBER_TOKEN,.value = 5},{.type = NUMBER_TOKEN,.value = 6}};
	NumberToken answer[] ={ {.type = NUMBER_TOKEN,.value =1 }, {.type = NUMBER_TOKEN,.value =60 }};
	pop_ExpectAndReturn(operatorStack,&operator[0]); //for compare purpose
	
	pop_ExpectAndReturn(dataStack,&num[1]); //inside the function
	pop_ExpectAndReturn(dataStack,&num[2]);	//pop out for calculate
	createNumberToken_ExpectAndReturn(1,&answer[0]);
	push_Expect(dataStack,&answer[0]);
	
	pop_ExpectAndReturn(operatorStack,&operator[1]);
	push_Expect(operatorStack,&operator[1]);
	push_Expect(operatorStack,&operator[2]);
	
	tryEvaluateOperatorOnStackThenPush(operatorStack,dataStack,&operator[2]);
}


void test_evaluateAllOperatorsOnStack_will_evaluate_untill_the_end_of_the_operator_stack(void)
{
	//2+3
	Stack *operatorStack;
	Stack *dataStack;
	OperatorToken operator[]={{.type=OPERATOR_TOKEN,.name ="+",.precedence = 70}};
	NumberToken num[]={{.type = NUMBER_TOKEN,.value = 2},{.type = NUMBER_TOKEN,.value = 3}};
	NumberToken answer[] ={ {.type = NUMBER_TOKEN,.value =5 }};
	pop_ExpectAndReturn(operatorStack,&operator[0]);
	
	pop_ExpectAndReturn(dataStack,&num[0]); //inside the function
	pop_ExpectAndReturn(dataStack,&num[1]);	//pop out for calculate
	createNumberToken_ExpectAndReturn(5,&answer[0]);
	push_Expect(dataStack,&answer[0]);
	pop_ExpectAndReturn(operatorStack,NULL);
	evaluateAllOperatorsOnStack(operatorStack,dataStack);
}

void test_evaluateAllOperatorsOnStack_will_evaluate_untill_the_end_of_the_operator_stack_for_longer_expression(void)
{
	//2*4/10+10-1+100
	Stack *operatorStack;
	Stack *dataStack;
	OperatorToken operator[]={{.type=OPERATOR_TOKEN,.name ="*",.precedence = 100},{.type=OPERATOR_TOKEN,.name ="/",.precedence = 100},
								{.type=OPERATOR_TOKEN,.name ="+",.precedence = 70},{.type=OPERATOR_TOKEN,.name ="-",.precedence = 70},
								{.type=OPERATOR_TOKEN,.name ="+",.precedence = 70}};
	NumberToken num[]={{.type = NUMBER_TOKEN,.value = 2},{.type = NUMBER_TOKEN,.value = 4},
						{.type = NUMBER_TOKEN,.value = 10},{.type = NUMBER_TOKEN,.value = 10},
						{.type = NUMBER_TOKEN,.value = 1},{.type = NUMBER_TOKEN,.value = 100}};
	NumberToken answer[] ={ {.type = NUMBER_TOKEN,.value =8},{.type = NUMBER_TOKEN,.value =0},
							{.type = NUMBER_TOKEN,.value =10},{.type = NUMBER_TOKEN,.value =9},
							{.type = NUMBER_TOKEN,.value =109}};
	pop_ExpectAndReturn(operatorStack,&operator[0]);
	
	pop_ExpectAndReturn(dataStack,&num[0]); //inside the function
	pop_ExpectAndReturn(dataStack,&num[1]);	//pop out for calculate
	createNumberToken_ExpectAndReturn(8,&answer[0]);
	push_Expect(dataStack,&answer[0]);
	
	pop_ExpectAndReturn(operatorStack,&operator[1]);
	
	pop_ExpectAndReturn(dataStack,&answer[0]); //inside the function
	pop_ExpectAndReturn(dataStack,&num[2]);	//pop out for calculate
	createNumberToken_ExpectAndReturn(0,&answer[1]);
	push_Expect(dataStack,&answer[1]);
	
	pop_ExpectAndReturn(operatorStack,&operator[2]);
	
	pop_ExpectAndReturn(dataStack,&answer[1]); //inside the function
	pop_ExpectAndReturn(dataStack,&num[3]);	//pop out for calculate
	createNumberToken_ExpectAndReturn(10,&answer[2]);
	push_Expect(dataStack,&answer[2]);
	
	pop_ExpectAndReturn(operatorStack,&operator[3]);
	
	pop_ExpectAndReturn(dataStack,&answer[2]); //inside the function
	pop_ExpectAndReturn(dataStack,&num[4]);	//pop out for calculate
	createNumberToken_ExpectAndReturn(9,&answer[3]);
	push_Expect(dataStack,&answer[3]);
	
	pop_ExpectAndReturn(operatorStack,&operator[4]);
	
	pop_ExpectAndReturn(dataStack,&answer[3]); //inside the function
	pop_ExpectAndReturn(dataStack,&num[5]);	//pop out for calculate
	createNumberToken_ExpectAndReturn(109,&answer[4]);
	push_Expect(dataStack,&answer[4]);
	
	
	pop_ExpectAndReturn(operatorStack,NULL);
	evaluateAllOperatorsOnStack(operatorStack,dataStack);
}























