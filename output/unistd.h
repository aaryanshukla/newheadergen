//===-- C standard library header unistd.h --------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIBC_UNISTD_H
#define LLVM_LIBC_UNISTD_H

#include "__llvm-libc-common.h"
#include "llvm-libc-macros/file-seek-macros.h"
#include "llvm-libc-macros/unistd-macros.h"


#include <llvm-libc-types/uid_t.h>
#include <llvm-libc-types/ssize_t.h>
#include <llvm-libc-types/size_t.h>
#include <llvm-libc-types/pid_t.h>
#include <llvm-libc-types/off_t.h>
#include <llvm-libc-types/__getoptargv_t.h>
#include <llvm-libc-types/__exec_envp_t.h>
#include <llvm-libc-types/__exec_argv_t.h>
__BEGIN_C_DECLS

int access(const char *, int);

int chdir(const char *);

int close(int);

int dup(int);

int dup2(int, int);

int dup3(int, int, int);

int execve(const char *, __exec_argv_t, __exec_envp_t);

int fchdir(int);

int fsync(int);

int ftruncate(int, off_t);

char * getcwd(char *, size_t);

uid_t geteuid();

int getpid();

int getppid();

uid_t getuid();

int isatty(int);

int link(const char *, const char *);

int linkat(int, const char *, int, const char *, int);

off_t lseek(int, off_t, int);

int pipe(int *);

ssize_t pread(int, void *, size_t, off_t);

ssize_t pwrite(int, const void *, size_t, off_t);

ssize_t read(int, void *, size_t);

ssize_t readlink(const char * __restrict, char * __restrict, size_t);

ssize_t readlinkat(const char * __restrict, char * __restrict, size_t);

int rmdir(const char *);

int symlink(const char *, const char *);

int symlinkat(int, const char *, int, const char *);

int sysconf(int);

int truncate(const char *, off_t);

int unlink(const char *);

int unlinkat(int, const char *, int);

ssize_t write(int, const void *, size_t);

void _exit(int)noreturn;

int execv(const char *, __exec_argv_t);

pid_t fork();

long __llvm_libc_syscall(long, long, long, long, long, long, long);

int getopt(int, __getoptargv_t, const char *);

void swab(const void * __restrict, void *, ssize_t);

extern char ** enivron();

extern char * optarg();

extern int optind();

extern int optopt();

extern int opterr();

extern char ** environ
extern char * optarg
extern int optind
extern int opterr
extern int optopt
__END_C_DECLS


#endif // LLVM_LIBC_UNISTD_H
