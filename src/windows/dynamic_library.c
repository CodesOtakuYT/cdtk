#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

#include <Windows.h>
#include <dynamic_library.h>

typedef DynamicLibrary Self;

Result DynamicLibraryLoad(DynamicLibraryLoadInfo const *info, Self *self) {
  opaque handle = LoadLibraryExA(info->name, nullptr, 0);
  if (!handle) return RESULT_ERRORR;
  self->handle = handle;
  return RESULT_SUCCESS;
}

void DynamicLibraryUnload(Self const *self) { FreeLibrary(self->handle); }

Result DynamicLibraryLoadSymbol(DynamicLibrary const *self, cstr name,
                                OpaqueFunctionPointer *symbol) {
  OpaqueFunctionPointer symbol_ =
      (OpaqueFunctionPointer)GetProcAddress(self->handle, name);
  if (!symbol_) return RESULT_ERRORR;
  *symbol = symbol_;
  return RESULT_SUCCESS;
}
