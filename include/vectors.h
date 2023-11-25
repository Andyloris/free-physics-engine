#pragma once

struct vector3d_struct
{
	double x;
	double y;
	double z;
};

typedef struct vector3d_struct vector3d_t;

double vector_mag(const vector3d_t *vect);
double vector_squared_mag(const vector3d_t *vect);
double vector_dist(const vector3d_t *vect1, const vector3d_t *vect2);
double vector_squared_dist(const vector3d_t *vect1, const vector3d_t *vect2);
vector3d_t vector_add(const vector3d_t *vect1, const vector3d_t *vect2);
vector3d_t vector_sub(const vector3d_t *vect1, const vector3d_t *vect2);
vector3d_t vector_scalar_mult(const vector3d_t *vect1, const double scalar);
vector3d_t vector_zero(void);
bool vector_is_collinear(const vector3d_t *vect1, const vector3d_t *vect2);
vector3d_t *vector_alloc(double x, double y, double z, func_status_t *status);
void vector_free(vector3d_t *vector);
