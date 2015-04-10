#ifndef NVIM_EVENT_PTY_PROCESS_H
#define NVIM_EVENT_PTY_PROCESS_H

#ifdef HAVE_CONFIG_H
# include "auto/config.h"
#endif

#ifdef FEAT_PTY_PROCESS
#include <sys/ioctl.h>

#include "nvim/event/process.h"

typedef struct pty_process {
  Process process;
  char *term_name;
  uint16_t width, height;
  struct winsize winsize;
  int tty_fd;
} PtyProcess;

# ifdef INCLUDE_GENERATED_DECLARATIONS
#  include "event/pty_process.h.generated.h"
# endif

#else

# include "nvim/event/libuv_process.h"

typedef struct pty_process {
  Process process;
  char *term_name;
  uint16_t width, height;
} PtyProcess;

# define pty_process_spawn(job) libuv_process_spawn((LibuvProcess *)job)
# define pty_process_close(job) libuv_process_close((LibuvProcess *)job)
# define pty_process_close_master(job) libuv_process_close((LibuvProcess *)job)
# define pty_process_resize(job, width, height)
# define pty_process_teardown(loop)
#endif

static inline PtyProcess pty_process_init(Loop *loop, void *data)
{
  PtyProcess rv;
  rv.process = process_init(loop, kProcessTypePty, data);
  rv.term_name = NULL;
  rv.width = 80;
  rv.height = 24;
#ifdef FEAT_PTY_PROCESS
  rv.tty_fd = -1;
#endif
  return rv;
}

#endif  // NVIM_EVENT_PTY_PROCESS_H
