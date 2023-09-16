#pragma once
#include <stdint.h>

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef signed long long i64;

typedef float f32;
typedef double f64;
typedef long double f128;

typedef u64 usize;
typedef i64 isize;

typedef void *opaque;

typedef char *cstr;
typedef int *wcstr;

typedef opaque OpaqueFunctionPointer;

#define U32_MIN (-2147483647 - 1)

typedef enum {
  RESULT_ERRORR = U32_MIN,
  RESULT_ERROR_OUT_OF_MEMORY,
  RESULT_ERROR_INVALID,
  RESULT_ERROR_NOT_FOUND,

  RESULT_SUCCESS = 0,

  RESULT_WARNING,
} Result;
