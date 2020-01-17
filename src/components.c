#include "components.h"

int contains(Body* a, Body* b) {
    return
        a->pos.x + a->size.x > b->pos.x &&
        a->pos.x < b->pos.x + b->size.x &&
        a->pos.y + a->size.y > b->pos.y &&
        a->pos.y < b->pos.y + b->size.y;
}

V2 center(Body* b){
    return(V2) {
        .x = b->pos.x + b->size.x * 0.5,
        .y = b->pos.y + b->size.y * 0.5,
    };
}

void update_timed_destroy(EcsWorld* world, EntId id) {
    EntStruct* e = get_ent(world, id);
    if (!has_comp(world, e, TimedDestroy)) return;

    TimedDestroy* td = get_comp(world, e, TimedDestroy);

    if (td->time_left <= 0.0f) {
        kill_ent(e);
        return;
    }

    td->time_left -= GetFrameTime();
}
