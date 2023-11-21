#include <stdheaders.h>
#include <vectors.h>
#include <particle.h>
#include <object.h>
#include <scene.h>

scene_t scene_alloc(size_t n)
{
	log_info("Allocating a scene with %u objects...", n);
	scene_t scene;
	scene.n = n;
	scene.objs = (object_t *)calloc(n, sizeof(object_t));
	if (scene.objs == NULL)
	{
		log_error("Failed to allocate %u objects in c (calloc returned a null pointer)", n);
		exit(EXIT_FAILURE);
	}
	return scene;
}

void scene_free(scene_t *scene)
{
	log_info("Freeing a scene...");
	free(scene->objs);
}

func_status_t scene_add_object(scene_t *scene, const object_t *obj)
{
	scene->objs = (object_t *)realloc(scene->objs, (scene->n+1)*sizeof(object_t));
	if (scene->objs == NULL)
	{
		log_warn("Failed to add %uth object to the scene", scene->n+1);
		return FAILURE;
	}
	memcpy(&scene->objs[scene->n++], obj, sizeof(object_t));
	return SUCCESS;
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
