#ifndef DEMO_H
#define DEMO_H

#include "__llvm-libc-common.h"

#include "__llvm-libc-common.h"
__BEGIN_C_DECLS

int  (int  ); feraiseexcept(int);

double  (double  , double  ); copysign(double x, double y);

void  * (void  * ,  void  * , size_t  ); memmove(void * dst, const void * src, size_t count);

char  * ( char  * , int  ); strchrnul(const char * src, int c);

size_t  ( char  * ,  char  * ); strcspn(const char * src, const char * segment);

void  * (void  *  ,  void  *  , size_t  ); memcpy(void * __restrict, const void * __restrict, size_t);

int  ( void  * ,  void  * , size_t  ); memcmp(const void * lhs, const void * rhs, size_t count);

void  * ( void  * , int  , size_t  ); memchr(const void * src, int c, size_t n);

void  * (void  * , int  , size_t  ); memset(void * ptr, int value, size_t count);

void  * (void  * , int  , size_t  ); memset_explicit(void * ptr, int value, size_t count);

char  * (char  *  ,  char  *  ); strcpy(char * __restrict dest, const char * __restrict src);

char  * (char  *  ,  char  *  , size_t  ); strncpy(char * __restrict dest, const char * __restrict src, size_t n);

char  * (char  *  ,  char  *  , size_t  ); strncat(char * __restrict dest, const char * __restrict src, size_t count);

int  ( char  * ,  char  * ); strcmp(const char * left, const char * right);

size_t  (char  *  ,  char  *  , size_t  ); strxfrm(char * __restrict dest, const char * __restrict src, size_t n);

char  * ( char  * ); strdup(const char * src);

char  * ( char  * , size_t  ); strndup(const char * src, size_t size);

int  ( char  * ,  char  * ); strcoll(const char * left, const char * right);

int  ( char  * ,  char  * , size_t  ); strncmp(const char * left, const char * right, size_t n);

char  * ( char  * , int  ); strchr(const char * src, int c);

char  * ( char  * ,  char  * ); strpbrk(const char * src, const char * breakset);

char  * ( char  * , int  ); strrchr(const char * src, int c);

size_t  ( char  * ,  char  * ); strspn(const char * src, const char * segment);

char  * ( char  * ,  char  * ); strstr(const char * haystack, const char * needle);

char  * (char  *  ,  char  *  ); strtok(char * __restrict src, const char * __restrict delimiter_string);

char  * (int  ); strerror(int err_num);

size_t  ( char  * ); strlen(const char * src);

__END_C_DECLS

#endif // DEMO_H