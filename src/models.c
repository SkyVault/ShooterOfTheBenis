#include "models.h"

GfxState* create_gfx_state() {
    GfxState* gfx = malloc(sizeof(GfxState));
    for (int i = 0; i < MAX_NUMBER_OF_DRAWABLES; i++)
        gfx->drawables[i].flags = 0;
    gfx->num_drawables = 0;
    return gfx;
}

void update_billboard(EcsWorld* ecs, EntId ent) {

}

void draw_billboard(GfxState* gfx, Camera* camera, EcsWorld* ecs, EntId ent) {
    EntStruct* self = get_ent(ecs, ent);

    if (!has_comp(ecs, self, Billboard) || !has_comp(ecs, self, Transform))
        return;


    if (gfx->num_drawables < MAX_NUMBER_OF_DRAWABLES) {
        gfx->drawables[gfx->num_drawables++] = (Drawable) {
            .type = DrawType_Billboard,
            .flags = DrawFlag_Active,
            .transform = *get_comp(ecs, self, Transform),
            .diffuse = RAYWHITE,
            .billboard = *get_comp(ecs, self, Billboard),
        };
    }
}

void update_models(EcsWorld* ecs, EntId ent) {

}    

void draw_models(EcsWorld* ecs, EntId ent) {

}

void flush_graphics(GfxState* gfx, Camera* camera) {
    for (int i = MAX_NUMBER_OF_DRAWABLES - 1; i >= 0; i--) {
        if (!(gfx->drawables[i].flags & DrawFlag_Active))
            continue;

        Drawable* d = &gfx->drawables[i];

        if (d->type == DrawType_Billboard) {
            DrawBillboard(*camera, d->billboard.texture, d->transform.translation, ACTOR_HEIGHT, RAYWHITE);

        }
    }

    gfx->num_drawables = 0;
}
