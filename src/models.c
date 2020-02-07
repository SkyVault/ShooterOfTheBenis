#include "models.h"

void update_billboard(EcsWorld* ecs, EntId ent) {

}

void draw_billboard(Camera* camera, EcsWorld* ecs, EntId ent) {
    EntStruct* self = get_ent(ecs, ent);

    if (!has_comp(ecs, self, Billboard) || !has_comp(ecs, self, Transform))
        return;

    Transform* transform = get_comp(ecs, self, Transform);
    Billboard* billboard = get_comp(ecs, self, Billboard);

    DrawBillboard(*camera, billboard->texture, transform->translation, ACTOR_HEIGHT, RAYWHITE);
}
