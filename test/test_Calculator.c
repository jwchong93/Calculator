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
	Stack dataStack;
	OperatorToken operator={.type=OPERATOR_TOKEN,.name ="+",.precedence = 70};
	NumberToken num[]={{.type = NUMBER_TOKEN,.value = 12},{.type = NUMBER_TOKEN,.value = 3}};
	NumberToken answer = {.type = NUMBER_TOKEN,.value = 15};
	pop_ExpectAndReturn(&dataStack,&num[0]);
	pop_ExpectAndReturn(&dataStack,&num[1]);
	createNumberToken_ExpectAndReturn(15,&answer);
	push_Expect(&dataStack,&answer);
	evaluateOperator(&dataStack,&operator);
	
}

void test_evaluateOperator_calculate_15_minus_3_(void)
{
	Stack dataStack;
	OperatorToken operator={.type=OPERATOR_TOKEN,.name ="-",.precedence = 70};
	NumberToken num[]={{.type = NUMBER_TOKEN,.value = 15},{.type = NUMBER_TOKEN,.value = 3}};
	NumberToken answer = {.type = NUMBER_TOKEN,.value = 12};
	pop_ExpectAndReturn(&dataStack,&num[1]);
	pop_ExpectAndReturn(&dataStack,&num[0]);
	createNumberToken_ExpectAndReturn(12,&answer);
	push_Expect(&dataStack,&answer);
	evaluateOperator(&dataStack,&operator);
	
}


void test_evaluateOperator_calculate_2_multiply_3_(void)
{
	Stack dataStack;
	OperatorToken operator={.type=OPERATOR_TOKEN,.name ="*",.precedence = 100};
	NumberToken num[]={{.type = NUMBER_TOKEN,.value = 2},{.type = NUMBER_TOKEN,.value = 3}};
	NumberToken answer = {.type = NUMBER_TOKEN,.value = 6};
	pop_ExpectAndReturn(&dataStack,&num[1]);
	pop_ExpectAndReturn(&dataStack,&num[0]);
	createNumberToken_ExpectAndReturn(6,&answer);
	push_Expect(&dataStack,&answer);
	evaluateOperator(&dataStack,&operator);
	
}

void test_evaluateOperator_calculate_9_divide_3_(void)
{
	Stack dataStack;
	OperatorToken operator={.type=OPERATOR_TOKEN,.name ="/",.precedence = 100};
	NumberToken num[]={{.type = NUMBER_TOKEN,.value = 9},{.type = NUMBER_TOKEN,.value = 3}};
	NumberToken answer = {.type = NUMBER_TOKEN,.value = 3};
	pop_ExpectAndReturn(&dataStack,&num[1]);
	pop_ExpectAndReturn(&dataStack,&num[0]);
	createNumberToken_ExpectAndReturn(3,&answer);
	push_Expect(&dataStack,&answer);
	evaluateOperator(&dataStack,&operator);
	
}

void test_evaluateOperator_calculate_15_modulus_4_(void)
{
	Stack dataStack;
	OperatorToken operator={.type=OPERATOR_TOKEN,.name ="%",.precedence = 100};
	NumberToken num[]={{.type = NUMBER_TOKEN,.value = 15},{.type = NUMBER_TOKEN,.value = 4}};
	NumberToken answer = {.type = NUMBER_TOKEN,.value = 3};
	pop_ExpectAndReturn(&dataStack,&num[1]);
	pop_ExpectAndReturn(&dataStack,&num[0]);
	createNumberToken_ExpectAndReturn(3,&answer);
	push_Expect(&dataStack,&answer);
	evaluateOperator(&dataStack,&operator);
	
}

void test_evaluateOperator_calculate_15_XOR_4_(void)
{
	Stack dataStack;
	OperatorToken operator={.type=OPERATOR_TOKEN,.name ="^",.precedence = 50};
	NumberToken num[]={{.type = NUMBER_TOKEN,.value = 15},{.type = NUMBER_TOKEN,.value = 4}};
	NumberToken answer = {.type = NUMBER_TOKEN,.value = 11};
	pop_ExpectAndReturn(&dataStack,&num[1]);
	pop_ExpectAndReturn(&dataStack,&num[0]);
	createNumberToken_ExpectAndReturn(11,&answer);
	push_Expect(&dataStack,&answer);
	evaluateOperator(&dataStack,&operator);
	
}

void test_evaluateOperator_calculate_15_AND_4_(void)
{
	Stack dataStack;
	OperatorToken operator={.type=OPERATOR_TOKEN,.name ="&",.precedence = 20};
	NumberToken num[]={{.type = NUMBER_TOKEN,.value = 15},{.type = NUMBER_TOKEN,.value = 4}};
	NumberToken answer = {.type = NUMBER_TOKEN,.value = 4};
	pop_ExpectAndReturn(&dataStack,&num[1]);
	pop_ExpectAndReturn(&dataStack,&num[0]);
	createNumberToken_ExpectAndReturn(4,&answer);
	push_Expect(&dataStack,&answer);
	evaluateOperator(&dataStack,&operator);
	
}

void test_evaluateOperator_calculate_15_OR_4_(void)
{
	Stack dataStack;
	OperatorToken operator={.type=OPERATOR_TOKEN,.name ="|",.precedence = 10};
	NumberToken num[]={{.type = NUMBER_TOKEN,.value = 15},{.type = NUMBER_TOKEN,.value = 4}};
	NumberToken answer = {.type = NUMBER_TOKEN,.value = 15};
	pop_ExpectAndReturn(&dataStack,&num[1]);
	pop_ExpectAndReturn(&dataStack,&num[0]);
	createNumberToken_ExpectAndReturn(15,&answer);
	push_Expect(&dataStack,&answer);
	evaluateOperator(&dataStack,&operator);
	
}

void test_evaluateOperator_will_throw_error_while_meet_an_unknown_operator(void)
{
	Stack dataStack;
	ErrorCode exception;
	OperatorToken operator={.type=OPERATOR_TOKEN,.name ="@",.precedence = 10};
	NumberToken num[]={{.type = NUMBER_TOKEN,.value = 15},{.type = NUMBER_TOKEN,.value = 4}};
	pop_ExpectAndReturn(&dataStack,&num[1]);
	pop_ExpectAndReturn(&dataStack,&num[0]);
	Try
	{
		evaluateOperator(&dataStack,&operator);
	}
	Catch(exception)
	{
		TEST_ASSERT_EQUAL(ERR_NOT_OPERATOR,exception);
	}
}

void test_tryEvaluateOperatorOnStackThenPush_will_push_the_token_if_the_stack_is_empty(void)
{
	Stack operatorStack;
	Stack dataStack;
	OperatorToken operator;
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&operatorStack,&operator);
	tryEvaluateOperatorOnStackThenPush(&operatorStack,&dataStack,&operator);
}

void test_tryEvaluateOperatorOnStackThenPush_will_push_the_token_if_the_top_operator_of_the_stack_have_a_smaller_precedence(void)
{
	Stack operatorStack;
	Stack dataStack;
	OperatorToken operator[]={{.type=OPERATOR_TOKEN,.name ="*",.precedence = 100},{.type=OPERATOR_TOKEN,.name ="+",.precedence = 70}};
	pop_ExpectAndReturn(&operatorStack,&operator[1]);
	push_Expect(&operatorStack,&operator[1]);
	push_Expect(&operatorStack,&operator[0]);
	tryEvaluateOperatorOnStackThenPush(&operatorStack,&dataStack,&operator[0]);
}

void test_tryEvaluateOperatorOnStackThenPush_will_evaluate_if_the_top_operator_of_the_stack_have_a_bigger_precedence(void)
{
	Stack operatorStack;
	Stack dataStack;
	OperatorToken operator[]={{.type=OPERATOR_TOKEN,.name ="+",.precedence = 70},{.type=OPERATOR_TOKEN,.name ="*",.precedence = 100}};
	NumberToken num[]={{.type = NUMBER_TOKEN,.value = 15},{.type = NUMBER_TOKEN,.value = 4}};
	NumberToken answer = {.type = NUMBER_TOKEN,.value = 60};
	pop_ExpectAndReturn(&operatorStack,&operator[1]);
	pop_ExpectAndReturn(&dataStack,&num[1]);
	pop_ExpectAndReturn(&dataStack,&num[0]);
	createNumberToken_ExpectAndReturn(60,&answer);
	push_Expect(&dataStack,&answer);
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&operatorStack,&operator[0]);
	tryEvaluateOperatorOnStackThenPush(&operatorStack,&dataStack,&operator[0]);
}

void test_tryEvaluateOperatorOnStackThenPush_will_evaluate_if_the_top_operator_of_the_stack_have_a_same_precedence(void)
{
	Stack operatorStack;
	Stack dataStack;
	OperatorToken operator[]={{.type=OPERATOR_TOKEN,.name ="+",.precedence = 70},{.type=OPERATOR_TOKEN,.name ="+",.precedence = 100}};
	NumberToken num[]={{.type = NUMBER_TOKEN,.value = 15},{.type = NUMBER_TOKEN,.value = 4}};
	NumberToken answer = {.type = NUMBER_TOKEN,.value = 19};
	pop_ExpectAndReturn(&operatorStack,&operator[1]);
	pop_ExpectAndReturn(&dataStack,&num[1]);
	pop_ExpectAndReturn(&dataStack,&num[0]);
	createNumberToken_ExpectAndReturn(19,&answer);
	push_Expect(&dataStack,&answer);
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&operatorStack,&operator[0]);
	tryEvaluateOperatorOnStackThenPush(&operatorStack,&dataStack,&operator[0]);
}

void test_tryEvaluateOperatorOnStackThenPush_will_evaluate_all_the_operation_inside_the_stack_which_have_higher_precedence(void)
{
	//3*4*5+6
	Stack operatorStack;
	Stack dataStack;
	OperatorToken operator[]={{.type=OPERATOR_TOKEN,.name ="*",.precedence = 100},{.type=OPERATOR_TOKEN,.name ="*",.precedence = 100},{.type=OPERATOR_TOKEN,.name ="+",.precedence = 70}};
	NumberToken num[]={{.type = NUMBER_TOKEN,.value = 3},{.type = NUMBER_TOKEN,.value = 4},{.type = NUMBER_TOKEN,.value = 5},{.type = NUMBER_TOKEN,.value = 6}};
	NumberToken answer[] ={ {.type = NUMBER_TOKEN,.value =12 }, {.type = NUMBER_TOKEN,.value =60 }};
	pop_ExpectAndReturn(&operatorStack,&operator[0]); //for compare purpose
	
	pop_ExpectAndReturn(&dataStack,&num[1]); //inside the function
	pop_ExpectAndReturn(&dataStack,&num[0]);	//pop out for calculate
	createNumberToken_ExpectAndReturn(12,&answer[0]);
	push_Expect(&dataStack,&answer[0]);
	
	pop_ExpectAndReturn(&operatorStack,&operator[1]);
	
	pop_ExpectAndReturn(&dataStack,&num[2]);
	pop_ExpectAndReturn(&dataStack,&answer[0]);
	createNumberToken_ExpectAndReturn(60,&answer[1]);
	push_Expect(&dataStack,&answer[1]);
	
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&operatorStack,&operator[2]);
	
	tryEvaluateOperatorOnStackThenPush(&operatorStack,&dataStack,&operator[2]);
}


void test_tryEvaluateOperatorOnStackThenPush_will_evaluate_the_operations_inside_the_stack_until_lower_precedence_been_met(void)
{
	//3&4*5+6
	Stack operatorStack;
	Stack dataStack;
	OperatorToken operator[]={{.type=OPERATOR_TOKEN,.name ="*",.precedence = 100},{.type=OPERATOR_TOKEN,.name ="&",.precedence =10 },{.type=OPERATOR_TOKEN,.name ="+",.precedence = 70}};
	NumberToken num[]={{.type = NUMBER_TOKEN,.value = 3},{.type = NUMBER_TOKEN,.value = 4},{.type = NUMBER_TOKEN,.value = 5},{.type = NUMBER_TOKEN,.value = 6}};
	NumberToken answer[] ={ {.type = NUMBER_TOKEN,.value =20 }, {.type = NUMBER_TOKEN,.value =60 }};
	pop_ExpectAndReturn(&operatorStack,&operator[0]); //for compare purpose
	
	pop_ExpectAndReturn(&dataStack,&num[2]); //inside the function
	pop_ExpectAndReturn(&dataStack,&num[1]);	//pop out for calculate
	createNumberToken_ExpectAndReturn(20,&answer[0]);
	push_Expect(&dataStack,&answer[0]);
	
	pop_ExpectAndReturn(&operatorStack,&operator[1]);
	push_Expect(&operatorStack,&operator[1]);
	push_Expect(&operatorStack,&operator[2]);
	
	tryEvaluateOperatorOnStackThenPush(&operatorStack,&dataStack,&operator[2]);
}

void test_tryEvaluateOperatorOnStackThenPush_will_evaluate_the_operations_inside_the_stack_until_lower_precedence_been_met_for_different_combination(void)
{
	//3^21%5+6
	Stack operatorStack;
	Stack dataStack;
	OperatorToken operator[]={{.type=OPERATOR_TOKEN,.name ="%",.precedence = 100},{.type=OPERATOR_TOKEN,.name ="^",.precedence =50 },{.type=OPERATOR_TOKEN,.name ="+",.precedence = 70}};
	NumberToken num[]={{.type = NUMBER_TOKEN,.value = 3},{.type = NUMBER_TOKEN,.value = 21},{.type = NUMBER_TOKEN,.value = 5},{.type = NUMBER_TOKEN,.value = 6}};
	NumberToken answer[] ={ {.type = NUMBER_TOKEN,.value =1 }, {.type = NUMBER_TOKEN,.value =60 }};
	pop_ExpectAndReturn(&operatorStack,&operator[0]); //for compare purpose
	
	pop_ExpectAndReturn(&dataStack,&num[2]); //inside the function
	pop_ExpectAndReturn(&dataStack,&num[1]);	//pop out for calculate
	createNumberToken_ExpectAndReturn(1,&answer[0]);
	push_Expect(&dataStack,&answer[0]);
	
	pop_ExpectAndReturn(&operatorStack,&operator[1]);
	push_Expect(&operatorStack,&operator[1]);
	push_Expect(&operatorStack,&operator[2]);
	
	tryEvaluateOperatorOnStackThenPush(&operatorStack,&dataStack,&operator[2]);
}


void test_evaluateAllOperatorsOnStack_will_evaluate_untill_the_end_of_the_operator_stack(void)
{
	//2+3
	Stack operatorStack;
	Stack dataStack;
	OperatorToken operator[]={{.type=OPERATOR_TOKEN,.name ="+",.precedence = 70}};
	NumberToken num[]={{.type = NUMBER_TOKEN,.value = 2},{.type = NUMBER_TOKEN,.value = 3}};
	NumberToken answer[] ={ {.type = NUMBER_TOKEN,.value =5 }};
	pop_ExpectAndReturn(&operatorStack,&operator[0]);
	
	pop_ExpectAndReturn(&dataStack,&num[1]); //inside the function
	pop_ExpectAndReturn(&dataStack,&num[0]);	//pop out for calculate
	createNumberToken_ExpectAndReturn(5,&answer[0]);
	push_Expect(&dataStack,&answer[0]);
	pop_ExpectAndReturn(&operatorStack,NULL);
	evaluateAllOperatorsOnStack(&operatorStack,&dataStack);
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
	
	pop_ExpectAndReturn(dataStack,&num[1]); //inside the function
	pop_ExpectAndReturn(dataStack,&num[0]);	//pop out for calculate
	createNumberToken_ExpectAndReturn(8,&answer[0]);
	push_Expect(dataStack,&answer[0]);
	
	pop_ExpectAndReturn(operatorStack,&operator[1]);
	
	pop_ExpectAndReturn(dataStack,&num[2]); //inside the function
	pop_ExpectAndReturn(dataStack,&answer[0]);	//pop out for calculate
	createNumberToken_ExpectAndReturn(0,&answer[1]);
	push_Expect(dataStack,&answer[1]);
	
	pop_ExpectAndReturn(operatorStack,&operator[2]);
	
	pop_ExpectAndReturn(dataStack,&num[3]); //inside the function
	pop_ExpectAndReturn(dataStack,&answer[1]);	//pop out for calculate
	createNumberToken_ExpectAndReturn(10,&answer[2]);
	push_Expect(dataStack,&answer[2]);
	
	pop_ExpectAndReturn(operatorStack,&operator[3]);
	
	pop_ExpectAndReturn(dataStack,&num[4]); //inside the function
	pop_ExpectAndReturn(dataStack,&answer[2]);	//pop out for calculate
	createNumberToken_ExpectAndReturn(9,&answer[3]);
	push_Expect(dataStack,&answer[3]);
	
	pop_ExpectAndReturn(operatorStack,&operator[4]);
	
	pop_ExpectAndReturn(dataStack,&num[5]); //inside the function
	pop_ExpectAndReturn(dataStack,&answer[3]);	//pop out for calculate
	createNumberToken_ExpectAndReturn(109,&answer[4]);
	push_Expect(dataStack,&answer[4]);
	
	
	pop_ExpectAndReturn(operatorStack,NULL);
	evaluateAllOperatorsOnStack(operatorStack,dataStack);
}

void test_evaluate_should_return_5_for_2_plus_3(void)
{
	//2+3
	Tokenizer newTokenizer;
	Stack operatorStack;
	Stack dataStack;
	int result;
	OperatorToken operator[]={{.type=OPERATOR_TOKEN,.name ="+",.precedence = 70}};
	NumberToken num[]={{.type = NUMBER_TOKEN,.value = 2},{.type = NUMBER_TOKEN,.value = 3}};
	NumberToken answer[] ={ {.type = NUMBER_TOKEN,.value =5 }};

	stackNew_ExpectAndReturn(&operatorStack); 
	stackNew_ExpectAndReturn(&dataStack); 
	tokenizerNew_ExpectAndReturn("2+3",&newTokenizer);
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&num[0]);
	push_Expect(&dataStack,&num[0]);
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&operator[0]);
	pop_ExpectAndReturn(&operatorStack,NULL);       //Function try
	push_Expect(&operatorStack,&operator[0]);	//This one also
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&num[1]);
	push_Expect(&dataStack,&num[1]);
	nextToken_ExpectAndReturn(&newTokenizer,NULL);
	
	pop_ExpectAndReturn(&operatorStack,&operator[0]);
	
	pop_ExpectAndReturn(&dataStack,&num[1]); //inside the function
	pop_ExpectAndReturn(&dataStack,&num[0]);	//pop out for calculate
	createNumberToken_ExpectAndReturn(5,&answer[0]);
	push_Expect(&dataStack,&answer[0]);
	pop_ExpectAndReturn(&operatorStack,NULL);
	pop_ExpectAndReturn(&dataStack,&answer[0]);
	result = evaluate("2+3");
	TEST_ASSERT_EQUAL(5,result);
}

void test_evaluate_should_return_12_for_4_multiply_3(void)
{
	//4*3
	Tokenizer newTokenizer;
	Stack operatorStack;
	Stack dataStack;
	int result;
	OperatorToken operator[]={{.type=OPERATOR_TOKEN,.name ="*",.precedence = 70}};
	NumberToken num[]={{.type = NUMBER_TOKEN,.value = 4},{.type = NUMBER_TOKEN,.value = 3}};
	NumberToken answer[] ={ {.type = NUMBER_TOKEN,.value =12 }};

	stackNew_ExpectAndReturn(&operatorStack); 
	stackNew_ExpectAndReturn(&dataStack); 
	tokenizerNew_ExpectAndReturn("4*3",&newTokenizer);
	
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&num[0]);
	push_Expect(&dataStack,&num[0]);
	
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&operator[0]);
	pop_ExpectAndReturn(&operatorStack,NULL);       //Function try
	push_Expect(&operatorStack,&operator[0]);	//This one also
	
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&num[1]);
	push_Expect(&dataStack,&num[1]);
	nextToken_ExpectAndReturn(&newTokenizer,NULL);
	
	pop_ExpectAndReturn(&operatorStack,&operator[0]);
	
	pop_ExpectAndReturn(&dataStack,&num[1]); //inside the function
	pop_ExpectAndReturn(&dataStack,&num[0]);	//pop out for calculate
	createNumberToken_ExpectAndReturn(12,&answer[0]);
	push_Expect(&dataStack,&answer[0]);
	pop_ExpectAndReturn(&operatorStack,NULL);
	pop_ExpectAndReturn(&dataStack,&answer[0]);
	result = evaluate("4*3");
	TEST_ASSERT_EQUAL(12,result);
}

//Haven't completed, unknown case.
void test_evaluate_for_3_plus_4_plus_5_minus_6(void)
{
	//3+4+5-6
	Tokenizer newTokenizer;
	Stack operatorStack;
	Stack dataStack;
	int result;
	OperatorToken operator[]={{.type=OPERATOR_TOKEN,.name ="+",.precedence = 70},
							{.type=OPERATOR_TOKEN,.name ="+",.precedence = 70},
							{.type=OPERATOR_TOKEN,.name ="-",.precedence = 70}};
	NumberToken num[]={{.type = NUMBER_TOKEN,.value = 3},{.type = NUMBER_TOKEN,.value = 4},
							{.type = NUMBER_TOKEN,.value = 5},{.type = NUMBER_TOKEN,.value = 6}};
	NumberToken answer ={.type = NUMBER_TOKEN,.value =7 };
	NumberToken answer2 ={.type = NUMBER_TOKEN,.value =12 };
	NumberToken answer3 ={.type = NUMBER_TOKEN,.value =6 };
	
	stackNew_ExpectAndReturn(&operatorStack); 
	stackNew_ExpectAndReturn(&dataStack); 
	tokenizerNew_ExpectAndReturn("3+4+5-6",&newTokenizer);
	
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&num[0]);	//3
	push_Expect(&dataStack,&num[0]);
	
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&operator[0]);	//+
	pop_ExpectAndReturn(&operatorStack,NULL);       //Function try
	push_Expect(&operatorStack,&operator[0]);	//This one also
	
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&num[1]);	//4
	push_Expect(&dataStack,&num[1]);
	
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&operator[1]);//+
	pop_ExpectAndReturn(&operatorStack,&operator[0]);       //Function try
	pop_ExpectAndReturn(&dataStack,&num[1]);
	pop_ExpectAndReturn(&dataStack,&num[0]);
	createNumberToken_ExpectAndReturn(7,&answer);
	push_Expect(&dataStack,&answer);
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&operatorStack,&operator[1]);
	
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&num[2]); //5
	push_Expect(&dataStack,&num[2]);

	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&operator[2]);//-
	pop_ExpectAndReturn(&operatorStack,&operator[1]);       //Function try
	pop_ExpectAndReturn(&dataStack,&num[2]);
	pop_ExpectAndReturn(&dataStack,&answer);
	createNumberToken_ExpectAndReturn(12,&answer2);
	push_Expect(&dataStack,&answer2);
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&operatorStack,&operator[2]);
	
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&num[3]); //6
	push_Expect(&dataStack,&num[3]);
	
	nextToken_ExpectAndReturn(&newTokenizer,NULL); //End
	
	pop_ExpectAndReturn(&operatorStack,&operator[2]);
	
	pop_ExpectAndReturn(&dataStack,&num[3]); //inside the function
	pop_ExpectAndReturn(&dataStack,&answer2);	//pop out for calculate
	createNumberToken_ExpectAndReturn(6,&answer3);
	push_Expect(&dataStack,&answer3);
	pop_ExpectAndReturn(&operatorStack,NULL);
	pop_ExpectAndReturn(&dataStack,&answer3);

	result = evaluate("3+4+5-6");
	TEST_ASSERT_EQUAL(6,result);
}

void xtest_evaluate_should_return_12_for_111_divide_12_plus_13_OR_14(void)
{
	Tokenizer newTokenizer;
	Stack operatorStack;
	Stack dataStack;
	int result;
	NumberToken number111 = {.type=NUMBER_TOKEN,.value=111};
	NumberToken number12 = {.type=NUMBER_TOKEN,.value=12};
	NumberToken number13 = {.type=NUMBER_TOKEN,.value=13};
	NumberToken number14 = {.type=NUMBER_TOKEN,.value=14};
	NumberToken number9 = {.type=NUMBER_TOKEN,.value=9};
	NumberToken number22 = {.type=NUMBER_TOKEN,.value=22};
	NumberToken number6 = {.type=NUMBER_TOKEN,.value=6};
	
	OperatorToken operatorAND={.type=OPERATOR_TOKEN,.name="&",.precedence=20};
	OperatorToken operatorADD={.type=OPERATOR_TOKEN,.name="+",.precedence=70};
	OperatorToken operatorDIV={.type=OPERATOR_TOKEN,.name="/",.precedence=100};
	
	stackNew_ExpectAndReturn(&operatorStack); 
	stackNew_ExpectAndReturn(&dataStack); 
	tokenizerNew_ExpectAndReturn("111/12+13&14",&newTokenizer);
	
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&number111);
	push_Expect(&dataStack,&number111);
	
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&operatorDIV); 
	pop_ExpectAndReturn(&operatorStack,NULL);       
	push_Expect(&operatorStack,&operatorDIV);
	
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&number12);
	push_Expect(&dataStack,&number12);
	
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&operatorADD);
	pop_ExpectAndReturn(&operatorStack,&operatorDIV);
	pop_ExpectAndReturn(&dataStack,&number12);
	pop_ExpectAndReturn(&dataStack,&number111);
	createNumberToken_ExpectAndReturn(9,&number9);
	push_Expect(&dataStack,&number9);
/*	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&operatorStack,&operatorADD);
	
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&number13);
	push_Expect(&dataStack,&number13);
	
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&operatorAND);
	pop_ExpectAndReturn(&operatorStack,&operatorADD);
	pop_ExpectAndReturn(&dataStack,&number13);
	pop_ExpectAndReturn(&dataStack,&number9);
	createNumberToken_ExpectAndReturn(22,&number22);
	push_Expect(&dataStack,&number22);
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&operatorStack,&operatorAND);
	
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&number14);
	push_Expect(&dataStack,&number14);
	
	nextToken_ExpectAndReturn(&newTokenizer,NULL);
	
	pop_ExpectAndReturn(&operatorStack,&operatorAND);
	pop_ExpectAndReturn(&dataStack,&number14);
	pop_ExpectAndReturn(&dataStack,&number22);
	createNumberToken_ExpectAndReturn(6,&number6);
	push_Expect(&dataStack,&number6);
	pop_ExpectAndReturn(&operatorStack,NULL);
	
	pop_ExpectAndReturn(&dataStack,&number6);
	*/
	result = evaluate("111/12+13&14");
	TEST_ASSERT_EQUAL(6,result);
}

void test_evaluate_should_calculate_the_complex_expression()
{
	//211&22^23+24*25
	Tokenizer newTokenizer;
	Stack operatorStack;
	Stack dataStack;
	int result;
	NumberToken number211 = {.type=NUMBER_TOKEN,.value=211};
	NumberToken number22 = {.type=NUMBER_TOKEN,.value=22};
	NumberToken number23 = {.type=NUMBER_TOKEN,.value=23};
	NumberToken number24 = {.type=NUMBER_TOKEN,.value=24};
	NumberToken number25 = {.type=NUMBER_TOKEN,.value=25};
	NumberToken number600 = {.type=NUMBER_TOKEN,.value=600};
	NumberToken number623 = {.type=NUMBER_TOKEN,.value=623};
	NumberToken number633 = {.type=NUMBER_TOKEN,.value=633};
	NumberToken number81 = {.type=NUMBER_TOKEN,.value=81};
	
	OperatorToken operatorAND={.type=OPERATOR_TOKEN,.name="&",.precedence=20};
	OperatorToken operatorXOR={.type=OPERATOR_TOKEN,.name="^",.precedence=50};
	OperatorToken operatorADD={.type=OPERATOR_TOKEN,.name="+",.precedence=70};
	OperatorToken operatorMUL={.type=OPERATOR_TOKEN,.name="*",.precedence=100};
	stackNew_ExpectAndReturn(&operatorStack); 
	stackNew_ExpectAndReturn(&dataStack); 
	tokenizerNew_ExpectAndReturn("211&22^23+24*25",&newTokenizer);
	
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&number211);
	push_Expect(&dataStack,&number211);
	
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&operatorAND); 
	pop_ExpectAndReturn(&operatorStack,NULL);       
	push_Expect(&operatorStack,&operatorAND);
	
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&number22);
	push_Expect(&dataStack,&number22);
	
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&operatorXOR);//+
	pop_ExpectAndReturn(&operatorStack,&operatorAND);       
	push_Expect(&operatorStack,&operatorAND);
	push_Expect(&operatorStack,&operatorXOR);
	
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&number23);
	push_Expect(&dataStack,&number23);
	
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&operatorADD);//+
	pop_ExpectAndReturn(&operatorStack,&operatorXOR);       
	push_Expect(&operatorStack,&operatorXOR);
	push_Expect(&operatorStack,&operatorADD);
	
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&number24);
	push_Expect(&dataStack,&number24);
	
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&operatorMUL);//+
	pop_ExpectAndReturn(&operatorStack,&operatorADD);       
	push_Expect(&operatorStack,&operatorADD);
	push_Expect(&operatorStack,&operatorMUL);
	
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&number25);
	push_Expect(&dataStack,&number25);
	
	nextToken_ExpectAndReturn(&newTokenizer,NULL);
	
	pop_ExpectAndReturn(&operatorStack,&operatorMUL);
	
	pop_ExpectAndReturn(&dataStack,&number25); //inside the function
	pop_ExpectAndReturn(&dataStack,&number24);	//pop out for calculate
	createNumberToken_ExpectAndReturn(600,&number600);
	push_Expect(&dataStack,&number600);
	
	pop_ExpectAndReturn(&operatorStack,&operatorADD);
	
	pop_ExpectAndReturn(&dataStack,&number600); //inside the function
	pop_ExpectAndReturn(&dataStack,&number23);	//pop out for calculate
	createNumberToken_ExpectAndReturn(623,&number623);
	push_Expect(&dataStack,&number623);
	
	pop_ExpectAndReturn(&operatorStack,&operatorXOR);
	
	pop_ExpectAndReturn(&dataStack,&number623); //inside the function
	pop_ExpectAndReturn(&dataStack,&number22);	//pop out for calculate
	createNumberToken_ExpectAndReturn(633,&number633);
	push_Expect(&dataStack,&number633);
	
	pop_ExpectAndReturn(&operatorStack,&operatorAND);
	
	pop_ExpectAndReturn(&dataStack,&number633); //inside the function
	pop_ExpectAndReturn(&dataStack,&number211);	//pop out for calculate
	createNumberToken_ExpectAndReturn(81,&number81);
	push_Expect(&dataStack,&number81);
	
	pop_ExpectAndReturn(&operatorStack,NULL);
	pop_ExpectAndReturn(&dataStack,&number81);
	result = evaluate("211&22^23+24*25");
	TEST_ASSERT_EQUAL(81,result);
}

void test_evaluate_should_calculate_the_complex_expression_with_different_arrangement_of_precedance()
{
	Tokenizer newTokenizer;
	Stack operatorStack;
	Stack dataStack;
	int result;
	NumberToken number266 = {.type=NUMBER_TOKEN,.value=266};
	NumberToken number27 = {.type=NUMBER_TOKEN,.value=27};
	NumberToken number28 = {.type=NUMBER_TOKEN,.value=28};
	NumberToken number29 = {.type=NUMBER_TOKEN,.value=29};
	NumberToken number30 = {.type=NUMBER_TOKEN,.value=30};
	NumberToken number57 = {.type=NUMBER_TOKEN,.value=57};
	NumberToken number34 = {.type=NUMBER_TOKEN,.value=34};
	NumberToken number2 = {.type=NUMBER_TOKEN,.value=2};
	
	OperatorToken operatorAND={.type=OPERATOR_TOKEN,.name="&",.precedence=20};
	OperatorToken operatorXOR={.type=OPERATOR_TOKEN,.name="^",.precedence=50};
	OperatorToken operatorADD={.type=OPERATOR_TOKEN,.name="+",.precedence=70};
	OperatorToken operatorOR={.type=OPERATOR_TOKEN,.name="|",.precedence=10};
	
	stackNew_ExpectAndReturn(&operatorStack); 
	stackNew_ExpectAndReturn(&dataStack); 
	tokenizerNew_ExpectAndReturn("266|27^28+29&30",&newTokenizer);
	
	
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&number266);
	push_Expect(&dataStack,&number266);

	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&operatorOR); 
	pop_ExpectAndReturn(&operatorStack,NULL);       
	push_Expect(&operatorStack,&operatorOR);
	
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&number27);
	push_Expect(&dataStack,&number27);

	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&operatorXOR);
	pop_ExpectAndReturn(&operatorStack,&operatorOR);       
	push_Expect(&operatorStack,&operatorOR);
	push_Expect(&operatorStack,&operatorXOR);
	
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&number28);
	push_Expect(&dataStack,&number28);
	
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&operatorADD);
	pop_ExpectAndReturn(&operatorStack,&operatorXOR);       
	push_Expect(&operatorStack,&operatorXOR);
	push_Expect(&operatorStack,&operatorADD);
	
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&number29);
	push_Expect(&dataStack,&number29);
	
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&operatorAND);
	pop_ExpectAndReturn(&operatorStack,&operatorADD);
	pop_ExpectAndReturn(&dataStack,&number29);
	pop_ExpectAndReturn(&dataStack,&number28);
	createNumberToken_ExpectAndReturn(57,&number57);
	push_Expect(&dataStack,&number57);
	pop_ExpectAndReturn(&operatorStack,&operatorXOR);
	pop_ExpectAndReturn(&dataStack,&number57);
	pop_ExpectAndReturn(&dataStack,&number27);
	createNumberToken_ExpectAndReturn(34,&number34);
	push_Expect(&dataStack,&number34);
	pop_ExpectAndReturn(&operatorStack,&operatorOR);
	push_Expect(&operatorStack,&operatorOR);
	push_Expect(&operatorStack,&operatorAND);
	
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&number30);
	push_Expect(&dataStack,&number30);
	
	nextToken_ExpectAndReturn(&newTokenizer,NULL);
	
	pop_ExpectAndReturn(&operatorStack,&operatorAND);
	
	pop_ExpectAndReturn(&dataStack,&number30); //inside the function
	pop_ExpectAndReturn(&dataStack,&number34);	//pop out for calculate
	createNumberToken_ExpectAndReturn(2,&number2);
	push_Expect(&dataStack,&number2);
	
	pop_ExpectAndReturn(&operatorStack,&operatorOR);
	
	pop_ExpectAndReturn(&dataStack,&number2); //inside the function
	pop_ExpectAndReturn(&dataStack,&number266);	//pop out for calculate
	createNumberToken_ExpectAndReturn(266,&number266);
	push_Expect(&dataStack,&number266);
	
	pop_ExpectAndReturn(&operatorStack,NULL);
	pop_ExpectAndReturn(&dataStack,&number2);
	
	result = evaluate("266|27^28+29&30");
	TEST_ASSERT_EQUAL(2,result);
	}
void test_evaluate_will_throw_error_for_expression_start_with_operator()
{
	Tokenizer newTokenizer;
	Stack operatorStack;
	Stack dataStack;
	OperatorToken plus={.type=OPERATOR_TOKEN,.name="+"};
	ErrorCode exception;
	int result;
	stackNew_ExpectAndReturn(&operatorStack); 
	stackNew_ExpectAndReturn(&dataStack); 
	tokenizerNew_ExpectAndReturn("+",&newTokenizer);
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&plus);
	Try
	{
		result = evaluate("+");
	}
	Catch(exception)
	{
		TEST_ASSERT_EQUAL(ERR_NOT_DATA,exception);
	}
}

void test_evaluate_will_throw_error_for_expression_which_contain_number_consequently()
{
	Tokenizer newTokenizer;
	Stack operatorStack;
	Stack dataStack;
	NumberToken number38={.type=NUMBER_TOKEN,.value=38};
	NumberToken number39={.type=NUMBER_TOKEN,.value=39};
	ErrorCode exception;
	int result;
	stackNew_ExpectAndReturn(&operatorStack); 
	stackNew_ExpectAndReturn(&dataStack); 
	tokenizerNew_ExpectAndReturn("38 39 +",&newTokenizer);
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&number38);
	push_Expect(&dataStack,&number38);
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&number39);
	Try
	{
		result = evaluate("38 39 +");
	}
	Catch(exception)
	{
		TEST_ASSERT_EQUAL(ERR_NOT_OPERATOR,exception);
	}
}

void test_evaluate_will_throw_error_for_expression_which_contain_operator_consequently()
{
	Tokenizer newTokenizer;
	Stack operatorStack;
	Stack dataStack;
	NumberToken number40={.type=NUMBER_TOKEN,.value=40};
	OperatorToken plus={.type=OPERATOR_TOKEN,.name="+"};
	OperatorToken multiply={.type=OPERATOR_TOKEN,.name="*"};
	ErrorCode exception;
	int result;
	stackNew_ExpectAndReturn(&operatorStack); 
	stackNew_ExpectAndReturn(&dataStack); 
	tokenizerNew_ExpectAndReturn("40+*41",&newTokenizer);
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&number40);
	push_Expect(&dataStack,&number40);
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&plus);
	pop_ExpectAndReturn(&operatorStack,NULL);   
	push_Expect(&operatorStack,(Token*)&plus);
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&multiply);

	Try
	{
		result = evaluate("40+*41");
	}
	Catch(exception)
	{
		TEST_ASSERT_EQUAL(ERR_NOT_DATA,exception);
	}
}

void test_evaluate_will_throw_error_for_expression_which_contain_invalid_operator()
{
	Tokenizer newTokenizer;
	Stack operatorStack;
	Stack dataStack;
	NumberToken number43={.type=NUMBER_TOKEN,.value=43};
	OperatorToken UnknownOperator={.type=OPERATOR_TOKEN,.name="#"};
	ErrorCode exception;
	int result;
	stackNew_ExpectAndReturn(&operatorStack); 
	stackNew_ExpectAndReturn(&dataStack); 
	tokenizerNew_ExpectAndReturn("43#",&newTokenizer);
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&number43);
	push_Expect(&dataStack,&number43);
	nextToken_ExpectAndThrow(&newTokenizer,ERR_INVALID_TOKEN);
	Try
	{
		result = evaluate("43#");
	}
	Catch(exception)
	{
		TEST_ASSERT_EQUAL(ERR_INVALID_TOKEN,exception);
	}
}

void test_evaluate_will_throw_error_for_expression_which_is_an_invalid_expression()
{
	Tokenizer newTokenizer;
	Stack operatorStack;
	Stack dataStack;
	NumberToken number42={.type=NUMBER_TOKEN,.value=42};
	OperatorToken XOR={.type=OPERATOR_TOKEN,.name="^",.precedence=50};
	NumberToken number2={.type=NUMBER_TOKEN,.value=2};
	OperatorToken minus={.type=OPERATOR_TOKEN,.name="-",.precedence = 70};
	ErrorCode exception;
	int result;
	stackNew_ExpectAndReturn(&operatorStack); 
	stackNew_ExpectAndReturn(&dataStack); 
	tokenizerNew_ExpectAndReturn("42^2-",&newTokenizer);
	
	
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&number42);//111
	push_Expect(&dataStack,(Token*)&number42);
	
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&XOR); 	//	/
	pop_ExpectAndReturn(&operatorStack,NULL);       
	push_Expect(&operatorStack,(Token*)&XOR);
	
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&number2);//12
	push_Expect(&dataStack,(Token*)&number2);
	
	nextToken_ExpectAndReturn(&newTokenizer,(Token*)&minus);//+
	pop_ExpectAndReturn(&operatorStack,&XOR);    
	push_Expect(&operatorStack,(Token*)&XOR);
	push_Expect(&operatorStack,(Token*)&minus);

	nextToken_ExpectAndReturn(&newTokenizer,NULL);
	Try
	{
		result = evaluate("42^2-");
	}
	Catch(exception)
	{
		TEST_ASSERT_EQUAL(INVALID_EXPRESSION,exception);
	}
	
}












