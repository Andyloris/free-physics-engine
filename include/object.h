#pragma once

struct object_struct
{
	particle_t center;
	double radius; // For now all object are spheres
};

typedef struct object_struct object_t;

bool object_is_colliding(const object_t *obj1, const object_t *obj2);
void object_apply_force(const vector3d_t *force, object_t *obj);
void object_update(object_t *obj);
void object_apply_gravity(object_t *obj);
