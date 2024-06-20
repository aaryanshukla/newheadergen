#ifndef LLVM_LIBC_DEMO_H
#define LLVM_LIBC_DEMO_H

#include "__llvm-libc-common.h"

#include "__llvm-libc-common.h"
__BEGIN_C_DECLS

int feraiseexcept(int);

double copysign(double, double);

size_t memmove(void *, const void *, size_t);

int strchrnul(const char *, int);

char strcspn(const char *, const char *);

size_t memcpy(void * __restrict, const void * __restrict, size_t);

size_t memcmp(const void *, const void *, size_t);

size_t memchr(const void *, int, size_t);

size_t memset(void *, int, size_t);

size_t memset_explicit(void *, int, size_t);

char strcpy(char * __restrict, const char * __restrict);

size_t strncpy(char * __restrict, const char * __restrict, size_t);

size_t strncat(char * __restrict, const char * __restrict, size_t);

char strcmp(const char *, const char *);

size_t strxfrm(char * __restrict, const char * __restrict, size_t);

char strdup(const char *);

size_t strndup(const char *, size_t);

char strcoll(const char *, const char *);

size_t strncmp(const char *, const char *, size_t);

int strchr(const char *, int);

char strpbrk(const char *, const char *);

int strrchr(const char *, int);

char strspn(const char *, const char *);

char strstr(const char *, const char *);

char strtok(char * __restrict, const char * __restrict);

int strerror(int);

char strlen(const char *);

__END_C_DECLS

 #endif // LLVM_LIBC_DEMO_H