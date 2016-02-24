#ifndef NVIM_EVENT_PTY_PROCESS_H
#define NVIM_EVENT_PTY_PROCESS_H

#ifdef _WIN32
#include "pty_process_win.h"
#else
#include "pty_process_unix.h"
#endif

#endif  // NVIM_EVENT_PTY_PROCESS_H
