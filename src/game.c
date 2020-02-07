#include "game.h"

Game* create_game(Assets* assets, Camera* camera) {
    Game* game = malloc(sizeof(Game));
    game->state = STATE_RUNNING;
    game->assets = assets;
    game->camera = camera;
    return game;
}
