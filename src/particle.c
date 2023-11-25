#include <stdheaders.h>
#include <vectors.h>
#include <particle.h>

void particle_apply_force(const vector3d_t *force, particle_t *part)
{
	*part->net_forces = vector_add(part->net_forces, force);
}

void particle_update(particle_t *part)
{
	// F = ma, so a = F/m, or a = F*(1/m) (F is the net force acting on the particle)
	vector3d_t accel = vector_scalar_mult(part->net_forces, 1/part->mass);

	// v = at + V (V is starting velocity)
	vector3d_t scaled_accel = vector_scalar_mult(&accel, sub_timestep);
	*part->velocity = vector_add(part->velocity, &scaled_accel);

	// r = R + vt - 0.5at² (R is starting position)
	vector3d_t scaled_vel = vector_scalar_mult(part->velocity, sub_timestep);
	scaled_accel = vector_scalar_mult(&scaled_accel, 0.5*sub_timestep); // already multiplied "scaled_accel" by sub_timestep

	vector3d_t right = vector_sub(&scaled_vel, &scaled_accel);
	*part->position = vector_add(part->position, &right);

	// Zero out the net forces
	memset(part->net_forces, 0, sizeof(vector3d_t));
}

particle_t *particle_alloc(vector3d_t position, vector3d_t velocity, vector3d_t net_forces, double mass, func_status_t *status)
{
	*status = SUCCESS;
	log_info("Allocating a particle...");
	particle_t *particle = malloc(sizeof(particle_t));

	memset(particle, 0, sizeof(particle_t)); // This is in the case this function fails. If someone tries to free the crappy pointer returned, free will just get a null pointer.

	if (particle == NULL)
	{
		log_warn("Failed to allocate a particle (malloc returned a null pointer)");
		*status = FAILURE;
		return particle;
	}

	particle->position = vector_alloc(position.x, position.y, position.z, status);
	particle->velocity = vector_alloc(velocity.x, velocity.y, velocity.z, status);
	particle->net_forces = vector_alloc(net_forces.x, net_forces.y, net_forces.z, status);
	particle->mass = mass;

	return particle;
}

void particle_free(particle_t *particle)
{
	log_info("Freeing a particle...");
	vector_free(particle->position);
	vector_free(particle->velocity);
	vector_free(particle->net_forces);
	free(particle);
}
