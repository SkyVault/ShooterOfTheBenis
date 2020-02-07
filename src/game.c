#include "game.h"

Game* create_game(Assets* assets, Camera* camera, EcsWorld* ent_world) {
    Game* game = malloc(sizeof(Game));
    game->state = STATE_RUNNING;
    game->assets = assets;
    game->camera = camera;
    game->ent_world = ent_world;
    return game;
}
