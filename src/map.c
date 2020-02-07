#include "map.h"

Map* load_map(int map, Game* game) {
    Map* result = malloc(sizeof(Map));
    result->current_map = map;

    for (int i = 0; i < MAX_MAP_WIDTH*MAX_MAP_HEIGHT; i++)
        result->walls[i].active = 0;

    const struct LvlData* data = &map_data[result->current_map];

    Model default_wall = LoadModelFromMesh(game->assets->meshes[MESH_CUBE]);
    default_wall.materials[0].maps[MAP_DIFFUSE].texture = game->assets->textures[TEX_WALL_1];
    default_wall.materials[0] .shader = game->assets->shaders[SHADER_PHONG_LIGHTING];
    
    for (int z = 0; z < data->h; z++) {
        for (int x = 0; x < data->w; x++) {
            char chr = data->d[x + z * data->w];

            if (chr != '.') {
                result->walls[x + z * data->w].active = 1;
                result->walls[x + z * data->w].model = default_wall;
            } else {
                result->walls[x + z * data->w].active = 0;
            }
        }
    }

    return result;
}

void update_map(Map* map) {

}

void draw_map(Map* map) {
    const struct LvlData* data = &map_data[map->current_map];

    for (int z = 0; z < data->h; z++) {
        for (int x = 0; x < data->w; x++) {
            char chr = data->d[x + z * data->w];

            if (chr != '.' && map->walls[x + z * data->w].active) {
                DrawModel(
                    map->walls[x + z * data->w].model,
                    (Vector3){x * CUBE_SIZE, 0, z * CUBE_SIZE},
                    CUBE_SIZE,
                    RAYWHITE);
            }
        }
    }
}
