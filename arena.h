#ifndef ARENA_H
#define ARENA_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Arena {
  size_t  cap;
  void   *beg;
  size_t  pos;
} Arena;

Arena arena_new(size_t cap);
void *arena_alloc(Arena *arena, size_t size);
void arena_free(Arena *arena);

#ifdef ARENA_IMPL

Arena arena_new(size_t cap) {
  Arena a = {0};
  a.cap = cap;
  a.beg = malloc(cap);
  a.pos = 0;
  return a;
}

void *arena_alloc(Arena *arena, size_t size) {
  if ((arena->pos + size) > arena->cap) {
    printf("out of memory\n");
    abort();
  }
  void *ret = arena->beg + arena->pos;
  arena->pos += size;
  return ret;
}

void arena_free(Arena *arena) {
  free(arena->beg);
}

#ifdef ARENA_DEBUG

void arena_debug(Arena *a) {
  printf("cap: %ld\n", a->cap);
  printf("beg: %p\n",  a->beg);
  printf("pos: %p\n",  a->beg+a->pos);
  printf("\n");
  printf("[");
  for (int i = 0; i < a->pos; i++) {
    printf("#");
  }
  for (int i = 0; i < (a->cap - a->pos); i++) {
    printf("-");
  }
  printf("]\n");
}

#endif // ARENA_DEBUG
#endif // ARENA_IMPL
#endif // ARENA_H
