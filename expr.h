#ifndef EXPR_H
#define EXPR_H

typedef enum {
  EXPR_ADD,
  EXPR_SUBTRACT,
  EXPR_DIVIDE,
  EXPR_MULTIPLY,
  EXPR_VALUE
} expr_t;

typedef struct expr {
  expr_t kind;
  struct expr *left;
  struct expr *right;
  int value;
} expr_s;

expr_s *expr_create(expr_t kind, expr_s *left, expr_s *right);
expr_s *expr_create_value(int value);
int expr_evaluate(expr_s *e);
void expr_print(expr_s *e);

#endif
