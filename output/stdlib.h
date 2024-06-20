// getenv is part of posix library
#ifndef LLVM_LIBC_STDLIB_H
#define LLVM_LIBC_STDLIB_H

#include "__llvm-libc-common.h"

#include <llvm-libc-types/__atexithandler_t.h>
#include <llvm-libc-types/__qsortrcompare_t.h>
#include <llvm-libc-types/__qsortcompare_t.h>
#include <llvm-libc-types/__bsearchcompare_t.h>
#include <llvm-libc-types/size_t.h>
#include <llvm-libc-types/lldiv_t.h>
#include <llvm-libc-types/ldiv_t.h>
#include <llvm-libc-types/div_t.h>
__BEGIN_C_DECLS

int abs(int);

int atoi(const char *);

double atof(const char * __restrict);

long atol(const char *);

long long atoll(const char *);

void * bsearch(const void *, const void *, size_t, size_t, __bsearchcompare_t);

div_t div(int, int);

long labs(long);

ldiv_t ldiv(long, long);

long long llabs(long long);

lldiv_t lldiv(long long, long long);

void qsort(void *, size_t, size_t, __qsortcompare_t);

void qsort_r(void *, size_t, size_t, __qsortrcompare_t, void *);

int rand();

void srand(unsigned int);

int strfromd(char * __restrict, size_t, const char * __restrict, double);

int strfromf(char * __restrict, size_t, const char * __restrict, float);

int strfroml(char * __restrict, size_t, const char * __restrict, long double);

double strtod(const char * __restrict, char * * __restrict);

float strtof(const char * __restrict, char * * __restrict);

long strtol(const char * __restrict, char * * __restrict, int);

long double strtold(const char * __restrict, char * * __restrict);

long long strtoll(const char * __restrict, char * * __restrict, int);

unsigned long strtoul(const char * __restrict, char * * __restrict, int);

unsigned long long strtoull(const char * __restrict, char * * __restrict, int);

void * malloc(size_t);

void * calloc(size_t, size_t);

void * realloc(void *, size_t);

void * aligned_alloc(size_t, size_t);

void free(void *);

_Noreturn void _Exit(int);

_Noreturn void abort();

int at_quick_exit(__atexithandler_t);

int atexit(__atexithandler_t);

_Noreturn void exit(int);

char * getenv(const char *);

_Noreturn void quick_exit(int);

__END_C_DECLS

 #endif // LLVM_LIBC_STDLIB_H