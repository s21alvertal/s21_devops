#include "s21_rpn.h"

int calculate(char* postfix, double x, double* result, int* status) {
  double nums[255];
  char* e = postfix;
  int head = -1;
  int is_double = 0;  // Проверка, double ли число
  while (*e != '\0' && *status == 0) {
    // printf("Status: %d\n", *status);
    if (*e == 'x')
      push_num(nums, &head, x);
    else if (((int)*e >= 48 && (int)*e <= 57)) {
      double cur_num = 0;
      while (*e != ' ') {
        if (*e != '.' && !is_double) {
          cur_num = cur_num * 10 + (double)(*e - 48);
          e++;
        } else if (*e == '.' && !is_double) {
          e++;
          is_double = 1;
        } else if (*e == '.' && is_double) {
          *status = 1;
          return *status;
        } else {
          cur_num = cur_num + (double)(*e - 48) / pow(10, is_double);
          e++;
          is_double++;
        }
      }
      e--;
      is_double = 0;
      push_num(nums, &head, cur_num);
    } else if (*e != ' ') {
      double num1 = pop_num(nums, &head);
      double num2, result;
      switch (*e) {
        case '+':
          num2 = pop_num(nums, &head);
          result = num2 + num1;
          break;
        case '-':
          num2 = pop_num(nums, &head);
          result = num2 - num1;
          break;
        case '*':
          num2 = pop_num(nums, &head);
          result = num2 * num1;
          break;
        case '/':
          num2 = pop_num(nums, &head);
          result = num2 / num1;
          break;
        case '^':
          num2 = pop_num(nums, &head);
          result = pow(num2, num1);
          break;
        case '%':
          num2 = pop_num(nums, &head);
          result = fmod(num2, num1);
          break;
        case 's':
          result = sin(num1);
          break;
        case 'c':
          result = cos(num1);
          break;
        case 't':
          result = tan(num1);
          break;
        case 'i':
          result = asin(num1);
          break;
        case 'o':
          result = acos(num1);
          break;
        case 'a':
          result = atan(num1);
          break;
        case 'q':
          result = sqrt(num1);
          break;
        case 'n':
          result = log(num1);
          break;
        case 'l':
          result = log10(num1);
          break;
        case 'u':
          result = -num1;
          break;
        case 'p':
          result = num1;
          break;
        default:
          *status = 2;
          return *status;
      }
      push_num(nums, &head, result);
    }
    e++;
  }
  *result = pop_num(nums, &head);
  return *status;
}
