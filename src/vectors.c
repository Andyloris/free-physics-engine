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

bool vector_is_collinear(const vector3d_t *vect1, const vector3d_t *vect2)
{
	// Two vectors are collinear if both lie on a same line or parallel lines and they may be oriented in same or opposite direction
	return doubles_eq(vect1->x*vect1->y*vect1->z, vect2->x*vect2->y*vect2->z);
}

vector3d_t *vector_alloc(double x, double y, double z, func_status_t *status)
{
	*status = SUCCESS;
	log_info("Allocating a vector...");
	vector3d_t *vector = malloc(sizeof(vector3d_t));

	if (vector == NULL)
	{
		log_warn("Failed to allocate a vector (malloc returned a null pointer)");
		*status = FAILURE;
		return vector;
	}

	vector->x = x;
	vector->y = y;
	vector->z = z;

	return vector;
}

void vector_free(vector3d_t *vector)
{
	log_info("Freeing a vector");
	free(vector);
}
