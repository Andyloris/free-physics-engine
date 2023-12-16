#pragma once

enum func_status_enum
{
	SUCCESS = 0,
	FAILURE = 1
};

typedef enum func_status_enum func_status_t;

double kronecker_delta(double i, double j);
double abs_double(double n);
bool doubles_eq(double a, double b);
void print(const char *str);
