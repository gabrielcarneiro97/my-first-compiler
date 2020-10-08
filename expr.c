#include <stdlib.h>
#include <stdio.h>
#include "expr.h"

expr_s *expr_create(expr_t kind, expr_s *left, expr_s *right) {
  expr_s *e = malloc(sizeof(*e));
  e->kind = kind;
  e->value = 0;
  e->left = left;
  e->right = right;

  return e;
}

expr_s *expr_create_value(int value) {
  expr_s *e = expr_create(EXPR_VALUE, 0, 0);
  e->value = value;

  return e;
}

void expr_print(expr_s *e) {
	if(!e) return;

	printf("(");

	expr_print(e->left);

	switch(e->kind) {
		case EXPR_ADD:
			printf("+");
			break;
		case EXPR_SUBTRACT:
			printf("-");
			break;
		case EXPR_MULTIPLY:
			printf("*");
			break;
		case EXPR_DIVIDE:
			printf("/");
			break;
		case EXPR_VALUE:
			printf("%d",e->value);
			break;
	}

	expr_print(e->right);
	printf(")");
}


int expr_evaluate(expr_s *e) {
	if(!e) return 0;

	int l = expr_evaluate(e->left);
	int r = expr_evaluate(e->right);

	switch(e->kind) {
		case EXPR_ADD:
			return l+r;
		case EXPR_SUBTRACT:
			return l-r;
		case EXPR_MULTIPLY:
			return l*r;
		case EXPR_DIVIDE:
			if(r==0) {
				printf("runtime error: divide by zero\n");
				exit(1);
			}
			return l/r;
		case EXPR_VALUE:
			return e->value;
	}

	return 0;
}
