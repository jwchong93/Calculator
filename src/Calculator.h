#ifndef Calculator_H
#define Calculator_H
#include "Stack.h"
#include "Token.h"

void tryEvaluateOperatorOnStackThenPush(Stack *operatorStack,Stack *dataStack,OperatorToken *operator);
void evaluateAllOperatorsOnStack(Stack *operatorStack,Stack *dataStack);
void evaluateOperator(Stack *dataStack,OperatorToken *operator);
int evaluate(char *expression);

#endif // Calculator_H
