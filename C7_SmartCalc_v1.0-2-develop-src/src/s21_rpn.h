#ifndef S21_RPN_H
#define S21_RPN_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// s21_calculate.c
int calculate(char* postfix, double x, double* result, int* status);

// s21_stack.c
void push_op(char* stack, int* top, char x);
char pop_op(const char* stack, int* top);
void push_num(double* stack, int* top, double x);
double pop_num(const double* stack, int* top);

// s21_parse.c
int precedence(char op);
int is_op(char ch);
int convert(char* input, char* postfix, int* status);
int is_func(const char* input, int i, int len);

#endif
