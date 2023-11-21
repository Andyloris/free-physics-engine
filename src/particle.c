#include <stdheaders.h>
#include <vectors.h>
#include <particle.h>

void particle_apply_force(const vector3d_t *force, particle_t *part)
{
	part->net_forces = vector_add(&part->net_forces, force);
}

void particle_update(particle_t *part)
{
	// F = ma, so a = F/m, or a = F*(1/m) (F is the net force acting on the particle)
	vector3d_t accel = vector_scalar_mult(&part->net_forces, 1/part->mass);

	// v = at + V (V is starting velocity)
	vector3d_t scaled_accel = vector_scalar_mult(&accel, sub_timestep);
	part->velocity = vector_add(&part->velocity, &scaled_accel);

	// r = R + vt - 0.5at² (R is starting position)
	vector3d_t scaled_vel = vector_scalar_mult(&part->velocity, sub_timestep);
	scaled_accel = vector_scalar_mult(&scaled_accel, 0.5*sub_timestep); // already multiplied "scaled_accel" by sub_timestep

	vector3d_t right = vector_sub(&scaled_vel, &scaled_accel);
	part->position = vector_add(&part->position, &right);

	// Zero out the net forces
	memset(&part->net_forces, 0, sizeof(vector3d_t));
}
