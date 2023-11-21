#include <stdheaders.h>
#include <vectors.h>
#include <particle.h>
#include <object.h>

bool object_is_colliding(const object_t *obj1, const object_t *obj2)
{
	// Two spheres are colliding if the distance between their centers is less than the sum of their radiuses.
	// We can use the property that "if x < y, then x² < y²" to avoid using square roots

	double squared_distance = vector_squared_dist(&obj1->center.position, &obj2->center.position);
	double squared_radiuses = obj1->radius*obj1->radius + obj2->radius*obj2->radius;

	return squared_distance < squared_radiuses;
}

void object_apply_force(const vector3d_t *force, object_t *obj)
{
	particle_apply_force(force, &obj->center);
}

void object_update(object_t *obj)
{
	particle_update(&obj->center);
}

void object_apply_gravity(object_t *obj)
{
	const vector3d_t gravity = { .x = 0, .y = G, .z = 0 };
	object_apply_force(&gravity, obj);
}
