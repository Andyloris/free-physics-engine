#pragma once

// Types

enum fpe_func_status_enum
{
	SUCCESS = 0,
	FAILURE
};

typedef enum fpe_func_status_enum fpe_func_status_t;

struct fpe_vector3d_struct
{
	double x;
	double y;
	double z;
};

typedef struct fpe_vector3d_struct fpe_vector3d_t;

struct fpe_particle_struct
{
	fpe_vector3d_t *position;
	fpe_vector3d_t *velocity;
	fpe_vector3d_t *net_forces;
	double mass;
};

typedef struct fpe_particle_struct fpe_particle_t;

struct fpe_object_struct
{
	fpe_particle_t *center;
	double radius;
};

typedef struct fpe_object_struct fpe_object_t;

struct fpe_scene_struct
{
	fpe_object_t *objs;
	size_t n;
};

typedef struct fpe_scene_struct fpe_scene_t;

// Functions

// Vector

extern void fpe_vector_create(double x, double y, double z, fpe_vector3d_t **vector, fpe_func_status_t *status);
extern void fpe_vector_delete(fpe_vector3d_t *vector);

// Particle

extern void fpe_particle_create(fpe_vector3d_t position, fpe_vector3d_t velocity, fpe_vector3d_t net_forces, double mass, fpe_particle_t **particle, fpe_func_status_t *status);
extern void fpe_particle_delete(fpe_particle_t *particle);

// Object

extern void fpe_object_create(fpe_particle_t *particle, double radius, fpe_object_t **object, fpe_func_status_t *status);
extern void fpe_object_delete(fpe_object_t *object);

// Scene

extern void fpe_scene_create(size_t n, fpe_scene_t **scene, fpe_func_status_t *status);
extern void fpe_scene_delete(fpe_scene_t *scene);
extern void fpe_scene_add_object(fpe_scene_t *scene, fpe_object_t *obj, fpe_func_status_t *status);
extern void fpe_scene_update(fpe_scene_t *scene);
