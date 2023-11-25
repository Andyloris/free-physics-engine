#include <stdheaders.h>
#include <vectors.h>
#include <particle.h>
#include <object.h>
#include <scene.h>

// Vector

extern void fpe_vector_create(double x, double y, double z, vector3d_t **vector, func_status_t *status)
{
	*vector = vector_alloc(x, y, z, status);
}

extern void fpe_vector_delete(vector3d_t *vector)
{
	vector_free(vector);
}

// Particle

extern void fpe_particle_create(vector3d_t *position, vector3d_t *velocity, vector3d_t *net_forces, double mass, particle_t **particle, func_status_t *status)
{
	*particle = particle_alloc(*position, *velocity, *net_forces, mass, status);
}

extern void fpe_particle_delete(particle_t *particle)
{
	particle_free(particle);
}

// Object

extern void fpe_object_create(particle_t *particle, double radius, object_t **object, func_status_t *status)
{
	*object = object_alloc(*particle, radius, status);
}

extern void fpe_object_delete(object_t *object)
{
	object_free(object);
}

extern void fpe_get_object_position(object_t *object, vector3d_t **vector)
{
	**vector = *object->center->position;
}

// Scene

extern void fpe_scene_create(size_t n, scene_t **scene, func_status_t *status)
{
	*scene = scene_alloc(n, status);
}

extern void fpe_scene_delete(scene_t *scene)
{
	scene_free(scene);
}

extern void fpe_scene_add_object(scene_t *scene, object_t *obj, func_status_t *status)
{
	scene_add_object(scene, obj, status);
}

extern void fpe_scene_update(scene_t *scene)
{
	scene_update(scene);
}
