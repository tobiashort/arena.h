#define BUILD_IMPL
#include "build.h/build.h"

#define check_status(status) \
  if (status != 0) {         \
    return status;           \
  }                          \

int main() {
  int status;
  status = build_yourself();
  check_status(status);

  Cmd build_test = {0};
  cmd_append(&build_test, "cc", NULL);
  cmd_append(&build_test, "-Wall", "-Werror", NULL);
  cmd_append(&build_test, "-o", "arena_test", NULL);
  cmd_append(&build_test, "arena_test.c", NULL);
  status = cmd_run(&build_test);
  check_status(status);

  Cmd test_run = {0};
  cmd_append(&test_run, "./arena_test", NULL);
  return cmd_run(&test_run);
}
