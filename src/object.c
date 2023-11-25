#include <stdheaders.h>
#include <vectors.h>
#include <particle.h>
#include <object.h>

bool object_is_colliding(const object_t *obj1, const object_t *obj2)
{
	// Two spheres are colliding if the distance between their centers is less than the sum of their radiuses.
	// We can use the property that "if x < y, then x² < y²" to avoid using square roots

	double squared_distance = vector_squared_dist(obj1->center->position, obj2->center->position);
	double squared_radiuses = obj1->radius*obj1->radius + obj2->radius*obj2->radius;

	return squared_distance < squared_radiuses;
}

void object_apply_force(const vector3d_t *force, object_t *obj)
{
	particle_apply_force(force, obj->center);
}

void object_update(object_t *obj)
{
	particle_update(obj->center);
}

void object_apply_gravity(object_t *obj)
{
	const vector3d_t gravity = { .x = 0, .y = G, .z = 0 };
	object_apply_force(&gravity, obj);
}

object_t *object_alloc(particle_t particle, double radius, func_status_t *status)
{
	*status = SUCCESS;
	log_info("Allocating an object...");
	object_t *object = malloc(sizeof(object_t));

	memset(object, 0, sizeof(object_t));

	if (object == NULL)
	{
		log_warn("Failed to allocate an object (malloc returned a null pointer)");
		*status = FAILURE;
		return object;
	}

	object->center = particle_alloc(*particle.position, *particle.velocity, *particle.net_forces, particle.mass, status);
	object->radius = radius;

	return object;
}

void object_free(object_t *object)
{
	log_info("Freeing an object");
	particle_free(object->center);
	free(object);
}
