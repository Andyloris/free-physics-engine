#pragma once

struct particle_struct
{
	vector3d_t *position; // In meters
	vector3d_t *velocity; // In m/s
	vector3d_t *net_forces; // In N/kg
	double mass; // In kg
};

typedef struct particle_struct particle_t;

void particle_apply_force(const vector3d_t *force, particle_t *part);
void particle_update(particle_t *part);
particle_t *particle_alloc(vector3d_t position, vector3d_t velocity, vector3d_t net_forces, double mass, func_status_t *status);
void particle_free(particle_t *particle);
