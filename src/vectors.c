#include <stdheaders.h>
#include <vectors.h>

#define VECTOR_SQMAG(vect) (vect->x*vect->x + vect->y*vect->y + vect->z*vect->z) // Vector squared magnitude
#define vector3d_zero { .x = 0, .y = 0, .z = 0 }

inline double vector_mag(const vector3d_t *vect)
{
	return sqrt(VECTOR_SQMAG(vect));
}

inline double vector_squared_mag(const vector3d_t *vect)
{
	return VECTOR_SQMAG(vect);
}

double vector_dist(const vector3d_t *vect1, const vector3d_t *vect2)
{
	// The distance between two vectors v and w is the length (magnitude) of the difference vector v - w.
	vector3d_t difference_vector = vector_sub(vect1, vect2);
	return vector_mag(&difference_vector);
}

double vector_squared_dist(const vector3d_t *vect1, const vector3d_t *vect2)
{
	// The distance between two vectors v and w is the length (magnitude) of the difference vector v - w.
	vector3d_t difference_vector = vector_sub(vect1, vect2);
	return vector_squared_mag(&difference_vector);
}

vector3d_t vector_add(const vector3d_t *vect1, const vector3d_t *vect2)
{
	vector3d_t vect;
	vect.x = vect1->x + vect2->x;
	vect.y = vect1->y + vect2->y;
	vect.z = vect1->z + vect2->z;

	return vect;
}

vector3d_t vector_sub(const vector3d_t *vect1, const vector3d_t *vect2)
{
	vector3d_t vect;
	vect.x = vect1->x - vect2->x;
	vect.y = vect1->y - vect2->y;
	vect.z = vect1->z - vect2->z;

	return vect;
}

vector3d_t vector_scalar_mult(const vector3d_t *vect1, const double scalar)
{
	vector3d_t vect;
	vect.x = vect1->x * scalar;
	vect.y = vect1->y * scalar;
	vect.z = vect1->z * scalar;
	return vect;
}

vector3d_t vector_zero()
{
	const vector3d_t vect = vector3d_zero;
	return vect;
}
