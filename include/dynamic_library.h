#pragma once
#include <types.h>

typedef struct {
  opaque handle;
} DynamicLibrary;

typedef struct {
  cstr const name;
} DynamicLibraryLoadInfo;

Result DynamicLibraryLoad(DynamicLibraryLoadInfo const *info,
                          DynamicLibrary *library);
void DynamicLibraryUnload(DynamicLibrary const *self);

Result DynamicLibraryLoadSymbol(DynamicLibrary const *self, cstr name,
                                OpaqueFunctionPointer *symbol);
