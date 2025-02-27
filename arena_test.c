#define ARENA_IMPL
#define ARENA_DEBUG
#include "arena.h"

int main() {
  Arena a1 = arena_new(sizeof(char)*16);
  arena_alloc(&a1, sizeof(char));
  arena_alloc(&a1, sizeof(char));
  arena_alloc(&a1, sizeof(char));
  arena_alloc(&a1, sizeof(char));
  arena_debug(&a1);
  arena_free(&a1);

  Arena a2 = arena_new(sizeof(char)*16);
  arena_alloc(&a2, sizeof(char)*16);
  arena_debug(&a2);
  arena_free(&a2);

  Arena a3 = arena_new(sizeof(char)*16);
  arena_alloc(&a3, sizeof(char)*16+1);
  // panic
}
