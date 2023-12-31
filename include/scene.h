#pragma once

struct scene_struct
{
	object_t *objs;
	size_t n;
};

typedef struct scene_struct scene_t;
scene_t *scene_alloc(size_t n, func_status_t *status);
void scene_free(scene_t *scene);
void scene_apply_gravity(scene_t *scene);
void scene_add_object(scene_t *scene, const object_t *obj, func_status_t *status);
void scene_set_objects(scene_t *scene, const object_t *obj);
void scene_update(scene_t *scene);
