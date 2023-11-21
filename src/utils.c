#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <consts.h>
#include <utils.h>

double kronecker_delta(double i, double j)
{
	return i == j;
}

union L
{
	uint64_t i;
	double n;
};

double abs_double(double n)
{
	union L i;
	i.n = n;
	i.i &= ~(1ULL << (sizeof(uint64_t)*CHAR_BIT - 1));
	return i.n;
}
