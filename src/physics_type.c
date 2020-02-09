#include "physics_type.h"

Physics create_physics() {
    return (Physics) {
        .velocity = (Vector3){0},
        .friction = 0.02f,
    };
}
