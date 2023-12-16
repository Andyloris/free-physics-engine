#pragma once

// Types

/**
 * @brief      This enum contains the different statuses of a function.
 */
enum fpe_func_status_enum
{
	SUCCESS = 0,
	FAILURE = 1
};

/**
 * A type that can contain each value in the fpe_func_status_enum
 */
typedef enum fpe_func_status_enum fpe_func_status_t;

/**
 * @brief      A structure containing the components of a vector
 */
struct fpe_vector3d_struct
{
	double x;
	double y;
	double z;
};

/**
 * A type containing an fpe_vector3d_struct
 */
typedef struct fpe_vector3d_struct fpe_vector3d_t;

/**
 * @brief      A structure containing the mass, position, velocity, and net forces acting on an object
 */
struct fpe_particle_struct
{
	fpe_vector3d_t *position;
	fpe_vector3d_t *velocity;
	fpe_vector3d_t *net_forces;
	double mass;
};

/**
 * A type containing an fpe_particle_struct
 */
typedef struct fpe_particle_struct fpe_particle_t;


/**
 * @brief      A structure containing a particle representing the center of an object, and it's radius
 */
struct fpe_object_struct
{
	fpe_particle_t *center;
	double radius;
};

/**
 * A type containing an fpe_object_struct
 */
typedef struct fpe_object_struct fpe_object_t;

/**
 * @brief      A structure containing an array of n objects, and the number n of objects
 */
struct fpe_scene_struct
{
	fpe_object_t *objs;
	size_t n;
};

/**
 * A type containing an fpe_scene_struct
 */
typedef struct fpe_scene_struct fpe_scene_t;

// Functions

// Vectors

/**
 * \defgroup Vector Vector Functions
 */
/**@{*/

/**
 * @brief      This function allocates a vector
 *
 * @param[in]  x       The x component of the vector
 * @param[in]  y       The y component of the vector
 * @param[in]  z       The z component of the vector
 * @param[out] vector  A pointer to an fpe_vector3d_t pointer
 * @param[out] status  A pointer to an fpe_func_status_t
 */
extern void fpe_vector_create(double x, double y, double z, fpe_vector3d_t **vector, fpe_func_status_t *status);

/**
 * @brief      This function deletes a previously allocated vector
 *
 * @param[in]  vector  A pointer to an fpe_vector3d_t
 */
extern void fpe_vector_delete(fpe_vector3d_t *vector);

/**@}*/

// Particle

/**
 * \defgroup Particle Particle Functions
 */
/**@{*/

/**
 * @brief      This function allocates a particle
 *
 * @param[in]  position    The position of the particle
 * @param[in]  velocity    The velocity of the particle
 * @param[in]  net_forces  The net forces acting on the particle
 * @param[in]  mass        The mass of the particle
 * @param[out] particle    A pointer to an fpe_particle_t pointer
 * @param[out] status      A pointer to an fpe_func_status_t
 */
extern void fpe_particle_create(fpe_vector3d_t position, fpe_vector3d_t velocity, fpe_vector3d_t net_forces, double mass, fpe_particle_t **particle, fpe_func_status_t *status);

/**
 * @brief      This function deletes a previously allocated particle
 *
 * @param[in]  particle  A pointer to an fpe_particle_t
 */
extern void fpe_particle_delete(fpe_particle_t *particle);

/**@}*/

// Object

/**
 * \defgroup Object Object Functions
 */
/**@{*/

/**
 * @brief      This function allocates an object
 *
 * @param[in]  particle  The particle representing the center of the object
 * @param[in]  radius    The radius of the object
 * @param[out] object    A pointer to an fpe_object_t pointer
 * @param[out] status    A pointer to an fpe_func_status_t
 */
extern void fpe_object_create(fpe_particle_t *particle, double radius, fpe_object_t **object, fpe_func_status_t *status);

/**
 * @brief      This function deletes a previously allocated object
 *
 * @param[in]  object  A pointer to an fpe_object_t
 */
extern void fpe_object_delete(fpe_object_t *object);

/**
 * @brief       This function gets the position of an object
 *
 * @param[in]   object  The object
 * @param[out]  vector  A pointer to an fpe_vector3d_t pointer
 */
extern void fpe_get_object_position(fpe_object_t *object, fpe_vector3d_t **vector);

/**@}*/

// Scene

/**
 * \defgroup Scene Scene Functions
 */
/**@{*/

/**
 * @brief       This function allocates a scene
 * 
 * @param[in]   n       The number of objects in the scene
 * @param[out]  scene   A pointer to an fpe_scene_t pointer
 * @param[out]  status  A pointer to an fpe_func_status_t
 */
extern void fpe_scene_create(size_t n, fpe_scene_t **scene, fpe_func_status_t *status);

/**
 * @brief      This function delete a previously allocated scene
 * 
 * @param[in]  scene  The scene  
 */
extern void fpe_scene_delete(fpe_scene_t *scene);

/**
 * @brief       This function adds an object to a scene
 * 
 * @param[in]   scene   The scene
 * @param[in]   object  The object to add
 * @param[out]  status  A pointer to an fpe_func_status_t
 */
extern void fpe_scene_add_object(fpe_scene_t *scene, fpe_object_t *obj, fpe_func_status_t *status);

/**
 * @brief      This function updates the objects in a scene, applying the necessary forces to them     
 * 
 * @param[in]  scene  The scene
 */
extern void fpe_scene_update(fpe_scene_t *scene);

/**@}*/
