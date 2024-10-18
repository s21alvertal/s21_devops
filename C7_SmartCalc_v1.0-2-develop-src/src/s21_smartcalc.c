#include "s21_smartcalc.h"
credit_entrys cred;
int main(int argc, char *argv[]) {
  int status;
  GtkApplication *app;

  app = gtk_application_new("org.florencm.smartcalc",
                            G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  return status;
}

void activate(GtkApplication *app, gpointer data) {
  GtkWidget *window;
  GtkWidget *grid;
  GtkWidget *entry;
  GtkWidget *button1;
  GtkWidget *button2;
  GtkWidget *button3;
  GtkWidget *button4;
  GtkWidget *button5;
  GtkWidget *button6;
  GtkWidget *button7;
  GtkWidget *button8;
  GtkWidget *button9;
  GtkWidget *button0;
  GtkWidget *button_sum;
  GtkWidget *button_sub;
  GtkWidget *button_mult;
  GtkWidget *button_div;
  GtkWidget *button_dot;
  GtkWidget *button_power;
  GtkWidget *button_mod;
  GtkWidget *button_eq;
  GtkWidget *button_graph;
  GtkWidget *button_remove;
  GtkWidget *button_credit_calc;
  GtkWidget *button_deposit_calc;

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Smart Calc v1.0");
  gtk_window_set_default_size(GTK_WINDOW(window), 300, 400);
  gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

  grid = gtk_grid_new();
  gtk_window_set_child(GTK_WINDOW(window), grid);
  gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
  gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);

  entry = gtk_entry_new();
  gtk_entry_set_max_length(GTK_ENTRY(entry), 255);
  gtk_entry_set_activates_default(GTK_ENTRY(entry), TRUE);

  button1 = gtk_button_new_with_label("1");
  g_signal_connect(button1, "clicked", G_CALLBACK(enter_symbol),
                   (gpointer)entry);
  gtk_widget_set_focusable(button1, FALSE);

  button2 = gtk_button_new_with_label("2");
  g_signal_connect(button2, "clicked", G_CALLBACK(enter_symbol),
                   (gpointer)entry);
  gtk_widget_set_focusable(button2, FALSE);

  button3 = gtk_button_new_with_label("3");
  g_signal_connect(button3, "clicked", G_CALLBACK(enter_symbol),
                   (gpointer)entry);
  gtk_widget_set_focusable(button3, FALSE);

  button4 = gtk_button_new_with_label("4");
  g_signal_connect(button4, "clicked", G_CALLBACK(enter_symbol),
                   (gpointer)entry);
  gtk_widget_set_focusable(button4, FALSE);

  button5 = gtk_button_new_with_label("5");
  g_signal_connect(button5, "clicked", G_CALLBACK(enter_symbol),
                   (gpointer)entry);
  gtk_widget_set_focusable(button5, FALSE);

  button6 = gtk_button_new_with_label("6");
  g_signal_connect(button6, "clicked", G_CALLBACK(enter_symbol),
                   (gpointer)entry);
  gtk_widget_set_focusable(button6, FALSE);

  button7 = gtk_button_new_with_label("7");
  g_signal_connect(button7, "clicked", G_CALLBACK(enter_symbol),
                   (gpointer)entry);
  gtk_widget_set_focusable(button7, FALSE);

  button8 = gtk_button_new_with_label("8");
  g_signal_connect(button8, "clicked", G_CALLBACK(enter_symbol),
                   (gpointer)entry);
  gtk_widget_set_focusable(button8, FALSE);

  button9 = gtk_button_new_with_label("9");
  g_signal_connect(button9, "clicked", G_CALLBACK(enter_symbol),
                   (gpointer)entry);
  gtk_widget_set_focusable(button9, FALSE);

  button0 = gtk_button_new_with_label("0");
  g_signal_connect(button0, "clicked", G_CALLBACK(enter_symbol),
                   (gpointer)entry);
  gtk_widget_set_focusable(button0, FALSE);

  button_sum = gtk_button_new_with_label("+");
  g_signal_connect(button_sum, "clicked", G_CALLBACK(enter_symbol),
                   (gpointer)entry);
  gtk_widget_set_focusable(button_sum, FALSE);

  button_sub = gtk_button_new_with_label("-");
  g_signal_connect(button_sub, "clicked", G_CALLBACK(enter_symbol),
                   (gpointer)entry);
  gtk_widget_set_focusable(button_sub, FALSE);

  button_mult = gtk_button_new_with_label("*");
  g_signal_connect(button_mult, "clicked", G_CALLBACK(enter_symbol),
                   (gpointer)entry);
  gtk_widget_set_focusable(button_mult, FALSE);

  button_div = gtk_button_new_with_label("/");
  g_signal_connect(button_div, "clicked", G_CALLBACK(enter_symbol),
                   (gpointer)entry);
  gtk_widget_set_focusable(button_div, FALSE);

  button_power = gtk_button_new_with_label("^");
  g_signal_connect(button_power, "clicked", G_CALLBACK(enter_symbol),
                   (gpointer)entry);
  gtk_widget_set_focusable(button_power, FALSE);

  button_mod = gtk_button_new_with_label("%");
  g_signal_connect(button_mod, "clicked", G_CALLBACK(enter_symbol),
                   (gpointer)entry);
  gtk_widget_set_focusable(button_mod, FALSE);

  button_dot = gtk_button_new_with_label(".");
  g_signal_connect(button_dot, "clicked", G_CALLBACK(enter_symbol),
                   (gpointer)entry);
  gtk_widget_set_focusable(button_dot, FALSE);

  button_eq = gtk_button_new_with_label("=");
  g_signal_connect(button_eq, "clicked", G_CALLBACK(gui_calculate),
                   (gpointer)entry);
  gtk_widget_set_focusable(button_eq, FALSE);

  button_graph = gtk_button_new_with_label("Graph");
  g_signal_connect(button_graph, "clicked", G_CALLBACK(print_graph),
                   (gpointer)entry);
  gtk_widget_set_focusable(button_graph, FALSE);

  button_remove = gtk_button_new_with_label("<");
  g_signal_connect(button_remove, "clicked", G_CALLBACK(remove_last_symbol),
                   (gpointer)entry);
  gtk_widget_set_focusable(button_remove, FALSE);

  button_credit_calc = gtk_button_new_with_label("Credit");
  g_signal_connect(button_credit_calc, "clicked", G_CALLBACK(credit_calc),
                   (gpointer)entry);
  gtk_widget_set_focusable(button_credit_calc, FALSE);

  button_deposit_calc = gtk_button_new_with_label("Deposit");
  g_signal_connect(button_deposit_calc, "clicked", G_CALLBACK(deposit_calc),
                   (gpointer)entry);
  gtk_widget_set_focusable(button_deposit_calc, FALSE);

  gtk_grid_attach(GTK_GRID(grid), entry, 1, 1, 6, 1);
  gtk_grid_attach(GTK_GRID(grid), button1, 1, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button2, 2, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button3, 3, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button4, 1, 3, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button5, 2, 3, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button6, 3, 3, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button7, 1, 4, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button8, 2, 4, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button9, 3, 4, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button0, 2, 5, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button_sum, 4, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button_sub, 5, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button_mult, 4, 3, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button_div, 5, 3, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button_power, 4, 4, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button_mod, 5, 4, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button_dot, 1, 5, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button_eq, 4, 5, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button_graph, 5, 5, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button_remove, 3, 5, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button_credit_calc, 6, 2, 1, 2);
  gtk_grid_attach(GTK_GRID(grid), button_deposit_calc, 6, 4, 1, 2);

  gtk_entry_grab_focus_without_selecting(GTK_ENTRY(entry));
  gtk_window_set_default_widget(GTK_WINDOW(window), button_eq);
  gtk_window_present(GTK_WINDOW(window));
}

void enter_symbol(GtkWidget *widget, gpointer data) {
  int position = (int)gtk_entry_get_text_length(data);
  // g_print("%b", gtk_widget_has_visible_focus(data));
  // if (gtk_widget_has_visible_focus(data) == TRUE) {
  //   gtk_editable_delete_text(data, 0, position);
  //   position = 0;
  // }
  gtk_editable_insert_text(data, gtk_button_get_label(GTK_BUTTON(widget)), 1,
                           &position);
  gtk_editable_set_position(data, position + 1);
}

int calculate_bus(char *infix, double x, double *result) {
  char postfix[255];
  int status = 0;
  convert(infix, postfix, &status);
  g_print("%s\n%s\n", infix, postfix);
  if (!status) calculate(postfix, x, result, &status);
  return status;
}

void print_graph(GtkWidget *widget, gpointer data) {
  GtkWidget *graph_window;
  GtkWidget *drawing_area;

  graph_window = gtk_window_new();
  gtk_window_set_title(GTK_WINDOW(graph_window), "Graph");
  gtk_window_set_default_size(GTK_WINDOW(graph_window), 430, 430);
  gtk_window_set_resizable(GTK_WINDOW(graph_window), FALSE);

  drawing_area = gtk_drawing_area_new();
  gtk_drawing_area_set_draw_func(GTK_DRAWING_AREA(drawing_area), on_draw, data,
                                 NULL);
  gtk_window_set_child(GTK_WINDOW(graph_window), drawing_area);
  gtk_window_present(GTK_WINDOW(graph_window));
}

void on_draw(GtkDrawingArea *widget, cairo_t *cr, int width, int height,
             gpointer data) {
  cairo_set_source_rgb(cr, 1.0, 1.0, 1.0);
  cairo_paint(cr);
  cairo_set_source_rgb(cr, 0.0, 0.0, 0.0);
  cairo_set_line_width(cr, 2);

  cairo_move_to(cr, width / 2, 0);
  cairo_line_to(cr, width / 2, height);
  cairo_move_to(cr, 0, height / 2);
  cairo_line_to(cr, width, height / 2);
  cairo_stroke(cr);

  char infix[255];
  strcpy(infix, gtk_editable_get_text(data));
  double x_max = 21;
  double x_min = -21;
  double h_step = (fabs(x_max) + fabs(x_min)) / width;
  double x_cur = x_min;
  double x_prev = 0.0, y_prev = 0.0;
  int first_flag = 1;
  for (int i = 0; i <= width; i++) {
    double y = 0.0;
    int status = calculate_bus(infix, x_cur, &y);
    // g_print("%s\n %f\n %f\n", infix, x_cur, y);
    if (status == 0 && first_flag == 0 && isfinite(y)) {
      cairo_move_to(cr, x_prev, height / 2 - (y_prev / h_step));
      cairo_line_to(cr, i, height / 2 - (y / h_step));
      cairo_stroke(cr);
    } else if (status == 0 && first_flag == 1 && isfinite(y)) {
      cairo_move_to(cr, width / 2, height / 2);
      first_flag = 0;
    }
    x_prev = i;
    y_prev = y;
    x_cur += h_step;
  }
}

void gui_calculate(GtkWidget *widget, gpointer data) {
  char infix[255];
  char str_result[255];
  int status = 0;
  double result = 0.0;
  strcpy(infix, gtk_editable_get_text(data));
  status = calculate_bus(infix, 0, &result);
  if (status == 0) {
    sprintf(str_result, "%f", result);
    gtk_editable_set_text(data, str_result);
    gtk_editable_set_position(data, strlen(str_result));
    gtk_widget_grab_focus(data);
  } else
    error_handler(data, status);
}

void remove_last_symbol(GtkWidget *widget, gpointer data) {
  guint16 len = gtk_entry_get_text_length(data);
  gtk_editable_delete_text(data, len - 1, len);
}

void error_handler(gpointer data, int status) {
  if (status == 1)
    gtk_editable_set_text(data, "Input error!");
  else if (status == 2)
    gtk_editable_set_text(data, "Calculation error!");
  gtk_editable_set_position(data, (int)gtk_entry_get_text_length(data));
  gtk_widget_grab_focus(data);
}

void credit_calc(GtkWidget *widget, gpointer data) {
  // credit_entrys cred;
  GtkWidget *credit_window;
  GtkWidget *calc_button = gtk_button_new_with_label("Calculate");

  cred.credit_amount = gtk_entry_new();
  gtk_entry_set_placeholder_text(GTK_ENTRY(cred.credit_amount),
                                 "Credit amount (RUR)");
  cred.term = gtk_entry_new();
  gtk_entry_set_placeholder_text(GTK_ENTRY(cred.term), "Term (months)");
  cred.interest_rate = gtk_entry_new();
  gtk_entry_set_placeholder_text(GTK_ENTRY(cred.interest_rate),
                                 "Interest rate (%)");

  cred.annuity_button = gtk_check_button_new_with_label("Annuity");
  gtk_check_button_set_active(GTK_CHECK_BUTTON(cred.annuity_button), TRUE);
  cred.differentiated_button =
      gtk_check_button_new_with_label("Differentiated");
  gtk_check_button_set_group(GTK_CHECK_BUTTON(cred.annuity_button),
                             GTK_CHECK_BUTTON(cred.differentiated_button));

  cred.monthly_payment = gtk_entry_new();
  gtk_entry_set_placeholder_text(GTK_ENTRY(cred.monthly_payment),
                                 "Monthly payment");
  gtk_editable_set_editable(GTK_EDITABLE(cred.monthly_payment), FALSE);
  gtk_widget_set_focusable(cred.monthly_payment, FALSE);
  cred.overpayment = gtk_entry_new();
  gtk_entry_set_placeholder_text(GTK_ENTRY(cred.overpayment), "Overpayment");
  gtk_editable_set_editable(GTK_EDITABLE(cred.overpayment), FALSE);
  gtk_widget_set_focusable(cred.overpayment, FALSE);
  cred.total_payment = gtk_entry_new();
  gtk_entry_set_placeholder_text(GTK_ENTRY(cred.total_payment),
                                 "Total payment");
  gtk_editable_set_editable(GTK_EDITABLE(cred.total_payment), FALSE);
  gtk_widget_set_focusable(cred.total_payment, FALSE);

  GtkWidget *grid = gtk_grid_new();

  credit_window = gtk_window_new();
  gtk_window_set_title(GTK_WINDOW(credit_window), "Credit Calc");
  gtk_window_set_default_size(GTK_WINDOW(credit_window), 700, 400);
  gtk_window_set_resizable(GTK_WINDOW(credit_window), FALSE);

  gtk_window_set_child(GTK_WINDOW(credit_window), grid);
  gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
  gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);

  gtk_grid_attach(GTK_GRID(grid), cred.credit_amount, 1, 1, 3, 1);
  gtk_grid_attach(GTK_GRID(grid), cred.term, 1, 2, 3, 1);
  gtk_grid_attach(GTK_GRID(grid), cred.interest_rate, 1, 3, 3, 1);
  gtk_grid_attach(GTK_GRID(grid), cred.annuity_button, 1, 4, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), cred.differentiated_button, 2, 4, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), cred.monthly_payment, 4, 1, 3, 1);
  gtk_grid_attach(GTK_GRID(grid), cred.overpayment, 4, 2, 3, 1);
  gtk_grid_attach(GTK_GRID(grid), cred.total_payment, 4, 3, 3, 1);
  gtk_grid_attach(GTK_GRID(grid), calc_button, 1, 5, 6, 1);

  g_signal_connect(calc_button, "clicked", G_CALLBACK(calculate_credit),
                   (gpointer)&cred);

  gtk_window_present(GTK_WINDOW(credit_window));
}

void calculate_credit(GtkWidget *widget, gpointer user_data) {
  credit_entrys *data = (credit_entrys *)user_data;
  if (data == NULL) g_print("%s", "dead");
  int status = 0;
  char infix[255];
  double tmp_result;
  char result_monthly[255];
  char result_over[255];
  char result_total[255];
  if (gtk_entry_get_text_length(GTK_ENTRY(cred.credit_amount)) == 0 ||
      gtk_entry_get_text_length(GTK_ENTRY(cred.interest_rate)) == 0 ||
      gtk_entry_get_text_length(GTK_ENTRY(cred.term)) == 0)
    status = 1;
  else if (gtk_check_button_get_active(GTK_CHECK_BUTTON(cred.annuity_button))) {
    strcat(infix, gtk_editable_get_text(GTK_EDITABLE(cred.credit_amount)));
    strcat(infix, "*((");
    strcat(infix, gtk_editable_get_text(GTK_EDITABLE(cred.interest_rate)));
    strcat(infix, "/100/12)/(1-(1+(");
    strcat(infix, gtk_editable_get_text(GTK_EDITABLE(cred.interest_rate)));
    strcat(infix, "/100/12))^-");
    strcat(infix, gtk_editable_get_text(GTK_EDITABLE(cred.term)));
    strcat(infix, "))");
    status = calculate_bus(infix, 0, &tmp_result);
    if (!status) sprintf(result_monthly, "%f", tmp_result);
    strcpy(infix, "\0");
    strcat(infix, result_monthly);
    strcat(infix, "*");
    strcat(infix, gtk_editable_get_text(GTK_EDITABLE(cred.term)));
    strcat(infix, "-");
    strcat(infix, gtk_editable_get_text(GTK_EDITABLE(cred.credit_amount)));
    if (!status) {
      status = calculate_bus(infix, 0, &tmp_result);
      sprintf(result_over, "%f", tmp_result);
    }
    strcpy(infix, "\0");
    strcat(infix, result_over);
    strcat(infix, "+");
    strcat(infix, gtk_editable_get_text(GTK_EDITABLE(cred.credit_amount)));
    if (!status) {
      status = calculate_bus(infix, 0, &tmp_result);
      sprintf(result_total, "%f", tmp_result);
    }
  } else if (gtk_check_button_get_active(
                 GTK_CHECK_BUTTON(cred.differentiated_button))) {
    /*
     * 	double tmp_result, remains, body;
     *	char body_str[255];
     *	sprintf(gtk_editable_get_text(GTK_EDITABLE(cred.credit_amount)), "%f",
     *remains); strcat(infix,
     *gtk_editable_get_text(GTK_EDITABLE(cred.credit_amount))); strcat(infix,
     *"/"); strcat(infix, gtk_editable_get_text(GTK_EDITABLE(cred.term)));
     *	status = calculate_bus(infix, 0, &body);
     *	if (!status) sprintf(body_str, "%f", tmp_result);
     *	strcpy(infix, "\0");
     */
  }
  if (status) {
    strcpy(result_monthly, "Error");
    strcpy(result_over, "Error");
    strcpy(result_total, "Error");
  }
  gtk_editable_set_text(GTK_EDITABLE(cred.monthly_payment), result_monthly);
  gtk_editable_set_text(GTK_EDITABLE(cred.overpayment), result_over);
  gtk_editable_set_text(GTK_EDITABLE(cred.total_payment), result_total);
}

void deposit_calc(GtkWidget *widget, gpointer data) {
  deposit_entrys dep;
  GtkWidget *deposit_window;
  GtkWidget *calc_button = gtk_button_new_with_label("Calculate");
  dep.deposit_amount = gtk_entry_new();
  gtk_entry_set_placeholder_text(GTK_ENTRY(dep.deposit_amount),
                                 "Deposit amount (RUR)");
  dep.deposit_term = gtk_entry_new();
  gtk_entry_set_placeholder_text(GTK_ENTRY(dep.deposit_term), "Term (months)");
  dep.interest_rate = gtk_entry_new();
  gtk_entry_set_placeholder_text(GTK_ENTRY(dep.interest_rate),
                                 "Interest rate (%)");
  dep.tax_rate = gtk_entry_new();
  gtk_entry_set_placeholder_text(GTK_ENTRY(dep.tax_rate), "Tax rate (%)");
  dep.periodicity = gtk_entry_new();
  gtk_entry_set_placeholder_text(GTK_ENTRY(dep.periodicity), "Periodicity");
  dep.capitalization = gtk_entry_new();
  gtk_entry_set_placeholder_text(GTK_ENTRY(dep.capitalization),
                                 "Capitalization");
  dep.replenishments = gtk_entry_new();  // 1000 2000 0 0 450 etc
  gtk_entry_set_placeholder_text(GTK_ENTRY(dep.replenishments),
                                 "Replenishments (100 0 25 etc.)");
  dep.withdrawals = gtk_entry_new();
  gtk_entry_set_placeholder_text(GTK_ENTRY(dep.withdrawals),
                                 "Withdrawals (100 0 25 etc.)");
  dep.accrued_interest = gtk_entry_new();
  gtk_entry_set_placeholder_text(GTK_ENTRY(dep.accrued_interest),
                                 "Accrued interest");
  gtk_editable_set_editable(GTK_EDITABLE(dep.accrued_interest), FALSE);
  gtk_widget_set_focusable(dep.accrued_interest, FALSE);
  dep.tax_amount = gtk_entry_new();
  gtk_entry_set_placeholder_text(GTK_ENTRY(dep.tax_amount), "Tax amount");
  gtk_editable_set_editable(GTK_EDITABLE(dep.tax_amount), FALSE);
  gtk_widget_set_focusable(dep.tax_amount, FALSE);
  dep.deposit_amount_by_the_end = gtk_entry_new();
  gtk_entry_set_placeholder_text(GTK_ENTRY(dep.deposit_amount_by_the_end),
                                 "Deposit amount by the end");
  gtk_editable_set_editable(GTK_EDITABLE(dep.deposit_amount_by_the_end), FALSE);
  gtk_widget_set_focusable(dep.deposit_amount_by_the_end, FALSE);

  GtkWidget *grid = gtk_grid_new();

  deposit_window = gtk_window_new();
  gtk_window_set_title(GTK_WINDOW(deposit_window), "Deposit Calc");
  gtk_window_set_default_size(GTK_WINDOW(deposit_window), 700, 400);
  gtk_window_set_resizable(GTK_WINDOW(deposit_window), FALSE);

  gtk_window_set_child(GTK_WINDOW(deposit_window), grid);
  gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
  gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);

  gtk_grid_attach(GTK_GRID(grid), dep.deposit_amount, 1, 1, 3, 1);
  gtk_grid_attach(GTK_GRID(grid), dep.deposit_term, 1, 2, 3, 1);
  gtk_grid_attach(GTK_GRID(grid), dep.interest_rate, 1, 3, 3, 1);
  gtk_grid_attach(GTK_GRID(grid), dep.tax_rate, 1, 4, 3, 1);
  gtk_grid_attach(GTK_GRID(grid), dep.periodicity, 1, 5, 3, 1);
  gtk_grid_attach(GTK_GRID(grid), dep.capitalization, 1, 6, 3, 1);
  gtk_grid_attach(GTK_GRID(grid), dep.replenishments, 1, 7, 6, 1);
  gtk_grid_attach(GTK_GRID(grid), dep.withdrawals, 1, 8, 6, 1);
  gtk_grid_attach(GTK_GRID(grid), dep.accrued_interest, 4, 1, 3, 1);
  gtk_grid_attach(GTK_GRID(grid), dep.tax_amount, 4, 2, 3, 1);
  gtk_grid_attach(GTK_GRID(grid), dep.deposit_amount_by_the_end, 4, 3, 3, 1);
  gtk_grid_attach(GTK_GRID(grid), calc_button, 1, 9, 6, 1);

  g_signal_connect(calc_button, "clicked", G_CALLBACK(calculate_deposit),
                   (gpointer)&dep);

  gtk_window_present(GTK_WINDOW(deposit_window));
}

void calculate_deposit(GtkWidget *widget, gpointer data) { return; }
