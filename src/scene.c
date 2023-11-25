#include <stdheaders.h>
#include <vectors.h>
#include <particle.h>
#include <object.h>
#include <scene.h>

scene_t *scene_alloc(size_t n, func_status_t *status)
{
	*status = SUCCESS;
	log_info("Allocating a scene with %u objects...", n);
	scene_t *scene = (scene_t *)malloc(sizeof(scene_t));

	if (scene == NULL)
	{
		log_warn("Failed to allocate scene (malloc returned a null pointer)");
		*status = FAILURE;
		return scene;
	}

	scene->n = n;
	scene->objs = (object_t *)calloc(n, sizeof(object_t));

	if (scene->objs == NULL)
	{
		log_warn("Failed to allocate %u objects (calloc returned a null pointer)", n);
		*status = FAILURE;
	}
	return scene;
}

void scene_free(scene_t *scene)
{
	log_info("Freeing a scene...");
	size_t i = 0;

	while (i < scene->n)
	{
		object_free(&scene->objs[i]);
	}

	free(scene);
}

void scene_add_object(scene_t *scene, const object_t *obj, func_status_t *status)
{
	*status = SUCCESS;
	scene->objs = (object_t *)realloc(scene->objs, (scene->n+1)*sizeof(object_t));
	if (scene->objs == NULL)
	{
		log_warn("Failed to add %uth object to the scene", scene->n+1);
		*status = FAILURE;
		return;
	}
	memcpy(&scene->objs[scene->n++], obj, sizeof(object_t));
}

void scene_set_objects(scene_t *scene, const object_t *obj)
{
	size_t i = 0;
	while (i < scene->n)
	{
		memcpy(&scene->objs[i], obj, sizeof(object_t));
		i++;
	}
}

void scene_update(scene_t *scene)
{
	size_t i = 0;
	while (i < sub_frames)
	{
		size_t j = 0;
		while (j < scene->n)
		{
			// Apply all of the required forces
			object_apply_gravity(&scene->objs[j]);
			object_update(&scene->objs[j]);
			j++;
		}
		i++;
	}
}
