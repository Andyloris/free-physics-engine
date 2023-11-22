#include <stdheaders.h>
#include <utils.h> // Already included in stdheaders.h, reincluded for the sake of consistency

double kronecker_delta(double i, double j)
{
	return (double)doubles_eq(i, j);
}

union L
{
	uint64_t i;
	double n;
};

double abs_double(double n)
{
	const uint64_t sign_mask = (1ULL << (sizeof(uint64_t)*CHAR_BIT - 1));
	union L i;
	i.n = n;
	i.i &= ~sign_mask;
	return i.n;
}

#define epsilon 0.0000001

// https://www.reddit.com/r/C_Programming/comments/4thsn7/comparing_doubles_in_c/
// Comapring doubles is dangerous because of rounding errors
bool doubles_eq(double a, double b)
{
	return abs_double(a - b) < epsilon;
}

void print(const char *str)
{
	printf("%s", str);
}
