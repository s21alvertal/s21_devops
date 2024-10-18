#ifndef S21_SMARTCALC_H
#define S21_SMARTCALC_H

#include <cairo.h>
#include <gtk/gtk.h>

#include "s21_rpn.h"

typedef struct {
  GtkWidget *credit_amount;
  GtkWidget *term;
  GtkWidget *interest_rate;
  GtkWidget *annuity_button;
  GtkWidget *differentiated_button;
  GtkWidget *monthly_payment;
  GtkWidget *overpayment;
  GtkWidget *total_payment;
} credit_entrys;

typedef struct {
  GtkWidget *deposit_amount;
  GtkWidget *deposit_term;
  GtkWidget *interest_rate;
  GtkWidget *tax_rate;
  GtkWidget *periodicity;
  GtkWidget *capitalization;
  GtkWidget *replenishments;
  GtkWidget *withdrawals;
  GtkWidget *accrued_interest;
  GtkWidget *tax_amount;
  GtkWidget *deposit_amount_by_the_end;
} deposit_entrys;

void activate(GtkApplication *app, gpointer data);
void enter_symbol(GtkWidget *widget, gpointer data);
int calculate_bus(char *infix, double x, double *result);
void on_draw(GtkDrawingArea *widget, cairo_t *cr, int width, int height,
             gpointer data);
void print_graph(GtkWidget *widget, gpointer data);
void gui_calculate(GtkWidget *widget, gpointer data);
void remove_last_symbol(GtkWidget *widget, gpointer data);
void credit_calc(GtkWidget *widget, gpointer data);
void calculate_credit(GtkWidget *widget, gpointer data);
void deposit_calc(GtkWidget *widget, gpointer data);
void calculate_deposit(GtkWidget *widget, gpointer user_data);
void error_handler(gpointer data, int status);
void on_draw(GtkDrawingArea *widget, cairo_t *cr, int width, int height,
             gpointer data);

#endif
