#include "physics.h"

Physics create_physics() {
    return (Physics) {
        .velocity = (Vector3){0},
        .friction = 0.02f,
    };
}

void update_physics(EcsWorld* ecs, Game* game, EntId ent) {
    EntStruct* self = get_ent(ecs, ent);
    if (!has_comp(ecs, self, Physics) ||
        !has_comp(ecs, self, Transform)) {

        return;
    }

    Physics* physics = get_comp(ecs, self, Physics);
    Transform* trans = get_comp(ecs, self, Transform);

    trans->translation.x += physics->velocity.x * GetFrameTime();
    trans->translation.y += physics->velocity.y * GetFrameTime();
    trans->translation.z += physics->velocity.z * GetFrameTime();

    physics->velocity.x *= powf(physics->friction, GetFrameTime());
    physics->velocity.y *= powf(physics->friction, GetFrameTime());
    physics->velocity.z *= powf(physics->friction, GetFrameTime());
}                                 
