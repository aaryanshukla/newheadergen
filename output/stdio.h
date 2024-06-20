#ifndef LLVM_LIBC_STDIO_H
#define LLVM_LIBC_STDIO_H

#include "__llvm-libc-common.h"

#define _IONBF
#define _IOLBF
#define _IOFBF
#define stdout
#define stdin
#define stderr
#include <llvm-libc-types/size_t.h>
#include <llvm-libc-types/off_t.h>
#include <llvm-libc-types/cookie_io_functions_t.h>
#include <llvm-libc-types/FILE.h>
__BEGIN_C_DECLS

int remove(const char *);

int rename(const char *, const char *);

int sprintf(char * __restrict, const char * __restrict, ...);

int snprintf(char * __restrict, size_t, const char * __restrict, ...);

int fprintf(FILE * __restrict, const char * __restrict, ...);

int printf(const char * __restrict, ...);

int vsprintf(char * __restrict, const char * __restrict, va_list);

int vsnprintf(char * __restrict, size_t, const char * __restrict, va_list);

int vfprintf(FILE * __restrict, const char * __restrict, va_list);

int vprintf(const char * __restrict, va_list);

int sscanf(const char * __restrict, const char * __restrict, ...);

int scanf(const char * __restrict, ...);

int fscanf(FILE * __restrict, const char * __restrict, ...);

int fileno(FILE *);

void clearerr(FILE *);

void clearerr_unlocked(FILE *);

int fclose(FILE *);

void flockfile(FILE *);

int feof(FILE *);

int feof_unlocked(FILE *);

int ferror(FILE *);

int ferror_unlocked(FILE *);

int fgetc(FILE *);

int fgetc_unlocked(FILE *);

char * fgets(char * __restrict, int, FILE * __restrict);

int fflush(FILE *);

FILE * fopen(const char *, const char *);

int fputc(int, FILE *);

int fputs(const char * __restrict, FILE * __restrict);

FILE * fopencookie(void *, const char *, cookie_io_functions_t);

size_t fread(void * __restrict, size_t, size_t, FILE * __restrict);

size_t fread_unlocked(void * __restrict, size_t, size_t, FILE * __restrict);

int fseek(FILE *, long, int);

long ftell(FILE *);

void funlockfile(FILE *);

size_t fwrite(const void * __restrict, size_t, size_t, FILE * __restrict);

size_t fwrite_unlocked(const void * __restrict, size_t, size_t, FILE * __restrict);

int getc(FILE *);

int getc_unlocked(FILE *);

int getchar();

int getchar_unlocked();

int putc(int, FILE *);

int putchar(int);

int puts(const char *);

void setbuf(FILE * __restrict, char * __restrict);

int setvbuf(FILE * __restrict, char * __restrict, int, size_t);

int ungetc(int, FILE *);

extern FILE * stderr();

extern FILE * stdin();

extern FILE * stdout();

__END_C_DECLS

 #endif // LLVM_LIBC_STDIO_H