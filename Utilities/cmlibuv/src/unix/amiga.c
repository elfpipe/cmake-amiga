#include "uv.h"
#include "internal.h"
#include <stdio.h>
void uv__platform_invalidate_fd(uv_loop_t* loop, int fd) { }
int uv__platform_loop_init(uv_loop_t* loop) { return -1; }
void uv__platform_loop_delete(uv_loop_t* loop) { }

void uv__io_poll(uv_loop_t* loop, int timeout) { }
int uv__io_fork(uv_loop_t* loop) {
  uv__platform_loop_delete(loop);
  return uv__platform_loop_init(loop);
}
int uv__io_check_fd(uv_loop_t* loop, int fd) { }

int fileno(FILE *stream) { return ((stream)->_file); }