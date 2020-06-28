#include "RPN.h"

Status initLStack(LinkStack *s)
{
    s->count = 0;
    s->top = (LinkStackPtr)malloc(sizeof(StackNode));
    if(s->top == NULL)
    {
        printf("Failed to allocate memory.\n");
        return ERROR;
    }
    else
    {
        s->top = NULL;
    }
    return SUCCESS;
}

Status isEmptyLStack(LinkStack *s)
{
    if(s->count == 0)
    {
        return SUCCESS;
    }
    return ERROR;
}

Status destroyLStack(LinkStack *s)
{
    if(isEmptyLStack(s))
    {
        return ERROR;
    }
    while(s->top != NULL)
    {
        LinkStackPtr p = s->top;
        s->top = s->top->next;
        free(p);
    }
    s->count = 0;
    return SUCCESS;
}

Status pushLStackdouble(LinkStack *s, double data)
{
    LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
    if(p == NULL)
    {
        printf("Failed to allocate memory.\n");
        return ERROR;
    }
    p->data = data;
    p->next = s->top;
    s->top = p;
    s->count ++;
    return SUCCESS;
}

Status pushLStackchar(LinkStack *s, char data)
{
    LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
    if(p == NULL)
    {
        printf("Failed to allocate memory.\n");
        return ERROR;
    }
    p->cData = data;
    p->next = s->top;
    s->top = p;
    s->count ++;
    return SUCCESS;
}

Status popLStackdouble(LinkStack *s, double *data)
{
    if(isEmptyLStack(s))
    {
        return ERROR;
    }
    *data = s->top->data;
    LinkStackPtr p = s->top;
    s->top = p->next;
    free(p);
    p = NULL;
    s->count--;
    return SUCCESS;
}

Status popLStackchar(LinkStack *s, char *data)
{
    if(isEmptyLStack(s))
    {
        return ERROR;
    }
    *data = s->top->cData;
    LinkStackPtr p = s->top;
    s->top = p->next;
    free(p);
    p = NULL;
    s->count--;
    return SUCCESS;
}

void inputString(char s[]) // Input infix expression.
{
    int i = 0; // index.
    printf("Input infix expression:");
    char *strs = s;

    scanf("%s", s);
    if(*strs =='e')
    {
        exit(0);
    }
    //getchar(); // ³Ô»Ø³µ
    // Check the input of the infix expression.
    while(SUCCESS)
    {
        // Check illegal characters.
        if((s[i]<'0'||s[i]>'9') && (s[i]!='+'&&s[i]!='-'&&s[i]!='*'&&s[i]!='/'&&s[i]!='.'&&s[i]!='('&&s[i]!= ')'))
        {
            printf("Errors, please input again:");
            scanf("%s", s);
            i = 0;
        }
        else
        {
            i++;
        }
        if(s[i] == '\0')
        {
            break; // All correct to exit.
        }
    }
    checkString(s); // Check the input of the string.
}

Status checkString(char s[]) // Check the input of the string.
{
    int i, j = 0;
    char a[20] = {0}; // Store operator.
    int flag = 0; // Judge whether the number is negative.
    int bracket = 0; // Whether it is double brackets.
    for(i=0; s[i]!='\0'; i++)
    {
        // Store operators between numbers.
        if(s[i] == '+'||s[i] == '-'||s[i] == '*'||s[i] == '/')
        {
            a[j++] = s[i];
        }
        // Judge if the brackets match.
        if(s[i] == '(')
        {
            bracket = 1;
        }
        if(s[i] == ')' && bracket == 1)
        {
            bracket = 0;
        }
        // Operate and judge whether they are correct.
        if((s[i+1]>='0'&&s[i+1]<='9') || s[i+1]=='(')
        {
            char c = a[0];
            for(int k=1; k<j; k++)
            {
                if((c=='+'&&a[k]=='-') || (c=='-'&&a[k]=='+'))
                {
                    c = '-';
                }
                else if(c=='-' && a[k]=='-')
                {
                    c = '+';
                }
                else if(c=='*' && a[k]=='+')
                {
                    c = '*';
                }
                else if((c=='*'||c=='/') && a[k]=='-')
                {
                    if(flag == 0)
                    {
                        flag = 1; // negative.
                    }
                    else
                    {
                        flag = 0; // positive.
                    }
                }
                else if((c=='+'||c=='-') && (a[k]=='*'||a[k]=='/'))
                {
                    printf("Errors, please input again.\n");
                    inputString(s);
                }
            }
            if(c=='+' || c =='-' || c=='*' || c=='/')
            {
               s[i-j+1] = c;
               for(int k = i-j+2; s[k]!='\0'; k++)
               {
                   s[k] = s[k+j-1];
               }
               i = i-j+2;
            }
            for(int k=0; k<j; k++)
            {
                a[k] = '\0';
            }
            j = 0;
        }
    }
    if(s[i-1]=='+' || s[i-1]=='-' || s[i-1]=='*' || s[i-1]=='/' || bracket!=0)
    {
        printf("Errors, please input again.\n");
        inputString(s);
    }
    return SUCCESS;
}

double getTopLStackdouble(LinkStack *s)
{
    if(isEmptyLStack(s))
    {
        return 0;
    }
    return (s->top->data);
}

char getTopLStackchar(LinkStack *s)
{
    if(isEmptyLStack(s))
    {
        return '\0';
    }
    return (s->top->cData);
}

// Convert infix expression to suffix expression.
Status convertString(char s1[], char s2[], LinkStack *s)
{
    int i = 0, j = 0;
    int flag = 0; // Separate right bracket and operator.
    char c;
    while(s1[i] != '\0')
    {
        if((s1[i]>='0'&&s1[i]<='9') || s1[i]=='.')
        {
            s2[j++] = s1[i];
        }
        if(s1[i+1] == ')')
        {
            if(s1[i+2]=='+' || s1[i+2]=='-' || s1[i+2]=='*' || s1[i+2]=='/' || s1[i+2]=='\0' || s1[i+2]==')')
            {
                if(flag == 0)
               {
                    flag = 1;
                    s2[j++] = ' ';
               }
            }
        }
        if(s1[i+1] == '+'||s1[i+1] == '-'||s1[i+1] == '*'||s1[i+1] == '/'||s1[i+1] == '\0')
        {
            if(flag == 1)
            {
                flag = 0;
            }
            else
            {
                s2[j++] = ' ';
            }
        }
        if(s1[i] == '+'||s1[i] == '-'||s1[i] == '*'||s1[i] == '/')
        {
            if(isEmptyLStack(s))
            {
                pushLStackchar(s, s1[i]); // Empty stack or left bracket.
            }
            else
            {
                switch(judgePriority(s1[i], getTopLStackchar(s)))
                {
                case -1:
                    {
                        pushLStackchar(s , s1[i]); // Operator priority is higher than the top of the stack.
                        break;
                    }
                case 0:
                case 1:
                    {
                        while(judgePriority(s1[i], getTopLStackchar(s)) != -1)
                        {
                            popLStackchar(s , &s2[j++]); // Operator priority is lower or equal to the top of the stack.
                            if(isEmptyLStack(s))
                            {
                                break;
                            }
                        }
                        if(!isEmptyLStack(s)&&(judgePriority(s1[i], getTopLStackchar(s)) == -1))
                        {
                            pushLStackchar(s, s1[i]); // Operator priority is higher than the top of the stack.
                        }
                        if(isEmptyLStack(s))
                        {
                            pushLStackchar(s , s1[i]);
                        }
                        break;
                    }
                }
            }
        }
        if(s1[i] == '(')
        {
            pushLStackchar(s, s1[i]);
        }
        if(s1[i] == ')')
        {
            while(SUCCESS)
            {
                popLStackchar(s, &s2[j++]);
                if(s->top == NULL||s->top->cData == '(')
                {
                    break;
                }
            }
            popLStackchar(s, &c);
        }
        i++;
    }
    while(!isEmptyLStack(s))
    {
        popLStackchar(s, &s2[j++]); // Transfer stack.
    }
    printf("Suffix expression:");
    for(i=0; s2[i]!='\0'; i++)
    {
        printf("%c", s2[i]);
    }
    printf("\n");
    return SUCCESS;
}

// Judge operator priority.
int judgePriority(char a, char b)
{
    if(((a == '+' || a == '-')&&(b == '+' || b == '-'))||((a == '*' || a == '/')&&(b == '*' || b == '/')))
    {
        return 1; // Equal priority.
    }
    else if((a == '+'||a == '-')&&(b == '*'||b == '/'))
    {
        return 0; // High priority on the right.
    }
    else
    {
        return -1; // High priority on the left.
    }
}

double computeString(LinkStack *s1, char s[])
{
    double temp = 0;
    int flag = 0;
    for(int i=0; s[i]!='\0'; i++)
    {
        if(s[i] == '.')
        {
            flag = 1;
        }
        if(s[i]>='0' && s[i]<='9')
        {
            if(flag != 0)
            {
                temp += (double)(s[i]-48)*pow(10, -flag);
                flag++;
            }
            else
            {
                temp = temp*10 + (double)(s[i]-48);
            }
        }
        if(s[i] == ' ')
        {
            pushLStackdouble(s1, temp);
            temp = 0;
            flag = 0;
        }
        if(s[i] == '+'||s[i] == '-'||s[i] == '*'||s[i] == '/')
        {
            double a, b, temp2;
            popLStackdouble(s1, &a);
            popLStackdouble(s1, &b);
            switch(s[i])
            {
            case '+':
                temp2 = a + b;
                pushLStackdouble(s1, temp2);
                temp2 = 0;
                break;
            case '-':
                temp2 = b - a;
                pushLStackdouble(s1, temp2);
                temp2 = 0;
                break;
            case '*':
                temp2 = b * a;
                pushLStackdouble(s1, temp2);
                temp2 = 0;
                break;
            case '/':
                temp2 = b / a;
                pushLStackdouble(s1, temp2);
                temp2 = 0;
                break;
            }
        }
    }
    popLStackdouble(s1, &temp);
    return temp;
}
