#include "s21_rpn.h"

int precedence(char op) {
  int result = -1;
  switch (op) {
    case '+':
    case '-':
      result = 1;
      break;
    case '*':
    case '/':
    case '%':
      result = 2;
      break;
    case '^':
      result = 3;
      break;
    case 's':  // sin
    case 'c':  // cos
    case 't':  // tan
    case 'i':  // asin
    case 'o':  // acos
    case 'a':  // atan
    case 'q':  // sqrt
    case 'n':  // ln
    case 'l':  // log
      result = 4;
      break;
    case 'u':  // unary -
    case 'p':  // unary +
      result = 5;
      break;
  }
  return result;
}

int is_op(char ch) {
  return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' ||
          ch == '%');
}

int is_func(const char* input, int i, int len) {
  int result = 0;
  char* s;
  char* string = malloc((len - i + 2) * sizeof(char));
  strcpy(string, input + i);
  s = strstr(string, "sin");
  if (s != NULL && s - string == 0) result = 1;
  s = strstr(string, "cos");
  if (s != NULL && s - string == 0) result = 2;
  s = strstr(string, "tan");
  if (s != NULL && s - string == 0) result = 3;
  s = strstr(string, "asin");
  if (s != NULL && s - string == 0) result = 4;
  s = strstr(string, "acos");
  if (s != NULL && s - string == 0) result = 5;
  s = strstr(string, "atan");
  if (s != NULL && s - string == 0) result = 6;
  s = strstr(string, "sqrt");
  if (s != NULL && s - string == 0) result = 7;
  s = strstr(string, "ln");
  if (s != NULL && s - string == 0) result = 8;
  s = strstr(string, "log");
  if (s != NULL && s - string == 0) result = 9;
  free(string);
  return result;
}

int convert(char* input, char* postfix, int* status) {
  int len = strlen(input);
  char stack[255];  // Основной стек, для знаков
  int top = -1;
  int i, j;
  int check =
      0;  // Переменная для проверки, особо полезна в случаях, когда число > 10
  for (i = 0, j = 0; i < len; i++) {
    if (((int)input[i] >= 48 && (int)input[i] <= 57) || (input[i] == 'x')) {
      while (((int)input[i] >= 48 && (int)input[i] <= 57) || input[i] == '.' ||
             (input[i] == 'x')) {
        postfix[j++] = input[i];
        check = 1;
        i++;
      }
      i--;
    } else if (input[i] == '(')
      push_op(stack, &top, input[i]);
    else if (input[i] == ')') {
      while (top > -1 && stack[top] != '(') {
        postfix[j++] = pop_op(stack, &top);
        postfix[j++] = ' ';
      }
      if (top > -1 && stack[top] != '(') {
        *status = 1;
      } else
        top--;
    } else if ((input[i] == '-' || input[i] == '+') &&
               (i == 0 || input[i - 1] == '(' || is_op(input[i - 1]))) {
      if (input[i] == '-')
        push_op(stack, &top, 'u');
      else
        push_op(stack, &top, 'p');
    } else if (is_op(input[i]) || is_func(input, i, len)) {
      int func = is_func(input, i, len);
      while (!func && top > -1 &&
             precedence(stack[top]) >= precedence(input[i])) {
        postfix[j] = pop_op(stack, &top);
        j += 1;
        postfix[j] = ' ';
        j += 1;
      }
      if (!func)
        push_op(stack, &top, input[i]);

      else if (func == 1) {
        push_op(stack, &top, 's');
        i += 2;
      } else if (func == 2) {
        push_op(stack, &top, 'c');
        i += 2;
      } else if (func == 3) {
        push_op(stack, &top, 't');
        i += 2;
      } else if (func == 4) {
        push_op(stack, &top, 'i');
        i += 3;
      } else if (func == 5) {
        push_op(stack, &top, 'o');
        i += 3;
      } else if (func == 6) {
        push_op(stack, &top, 'a');
        i += 3;
      } else if (func == 7) {
        push_op(stack, &top, 'q');
        i += 4;
      } else if (func == 8) {
        push_op(stack, &top, 'n');
        i += 1;
      } else if (func == 9) {
        push_op(stack, &top, 'l');
        i += 2;
      }
    } else {
      *status = 1;
    }
    if (check) {
      postfix[j++] = ' ';
      check = 0;
    }
  }

  while (top > -1) {
    postfix[j++] = pop_op(stack, &top);
    postfix[j++] = ' ';
  }
  postfix[j] = '\0';

  return *status;
}
