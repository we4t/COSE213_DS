#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100

typedef enum {
    lparen,
    rparen,
    plus,
    minus,
    times,
    divide,
    mod,
    eos,
    operand
} precedence;

// 스택에 들어가는건 피연산자를 제외한 모든 것. eos도 포함.
// eos : end-of-string, '\0'
precedence stack[MAX_STACK_SIZE];
char expr[MAX_EXPR_SIZE];

static int isp[] = {0, 19, 12, 12, 13, 13, 13, 0};
static int icp[] = {20, 19, 12, 12, 13, 13, 13, 0};

precedence get_token(char *symbol, int *n) {
    // 아래의 코드를 보면 알겠지만
    // 후위 표기식으로 변환할 때
    // n으로 문장에서 살펴볼 캐릭터 값의 인덱스를 조종하고,
    // symbol은 살펴보는 캐릭터를 출력하기 위해 매개변수로 넣음.

    *symbol = expr[(*n)++];
    switch (*symbol) {
    case '(':
        return lparen;
    case ')':
        return rparen;
    case '+':
        return plus;
    case '-':
        return minus;
    case '*':
        return times;
    case '/':
        return divide;
    case '%':
        return mod;
    case '\0':
        return eos;
    default:
        return operand;
    }
}

void postfix(void) {
    // function to convert from infix to postfix
    char symbol;
    precedence token;
    int n = 0;
    int top = 0;
    stack[0] = eos; // place on the bottom.

    for (token = get_token(&symbol, &n); token != eos;) {
        if (token == operand)
            print("%c", symbol);

        else if (token == rparen) {
            while (stack[top] == lparen) {
                delete (&top);
            }
        }

        else {
            while (isp[stack[top]] >= icp[token]) {
                print_token(delete (&top));
            }
            add(&top, token);
        }
        token = get_token(&symbol, &n);
    }

    while ((token = delete (&top)) != eos)
        print_token(token);

    printf("\n");
}

int eval(void) {
	// 사전작업 : expr이 후위 표기식이며, 
	// 스택의 데이터타입이 int 일 때에만 사용 가능한 방식.

    precedence token;
    char symbol;
    int op1, op2;
    int top = -1; // push 에서 stack[++top] = item 이므로 괜찮음.
    int n = 0;
    token = get_token(&symbol, &n);

    while (token != eos) {
        if (token == operand) {
            // token이 피연산자이면
            add(&top, symbol - '0');
            // 피연산자이면 숫자로 만들어서
            // stack top에 삽입
        } else {
            // token이 연산자이면
            op2 = delete (&top);
            op1 = delete (&top);
            // 스택에 존재하는 피연산자 두 개 꺼냄.

            switch (token) {
            case plus:
                add(&top, op1 + op2);
                break;
            case minus:
                add(&top, op1 + op2);
                break;
            case times:
                add(&top, op1 * op2);
                break;
            case divide:
                add(&top, op1 / op2);
                break;
            case mod:
                add(&top, op1 % op2);
                break;
            }
        }
		token = get_token(&symbol, &n);
    }
	return delete(&top);
}