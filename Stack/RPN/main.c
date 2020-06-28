#include <stdio.h>
#include <stdlib.h>
#include "RPN.h"

int main()
{
    LinkStack *operators = (LinkStack*)malloc(sizeof(LinkStack));
    LinkStack *numbers = (LinkStack*)malloc(sizeof(LinkStack));
    double res;
    while(SUCCESS)
    {
        printf("\n\n\n");
        printf("--------Infix to Suffix calculator--------\n");
        printf("Input 'e' to exit.\n\n");
        char exp1[100] = {0};
        char exp2[100] = {0};
        initLStack(operators);
        initLStack(numbers);
        inputString(exp1);
        convertString(exp1, exp2, operators);
        res = computeString(numbers, exp2);
        printf("\nResult is %.2lf\n", res);
        system("pause");
        system("cls");
    }
    return 0;
}
