#include <dlfcn.h>
#include <dynamic_library.h>

typedef DynamicLibrary Self;

Result DynamicLibraryLoad(DynamicLibraryLoadInfo const *info, Self *self) {
  opaque handle = dlopen(info->name, RTLD_LAZY | RTLD_LOCAL);
  if (!handle) return RESULT_ERRORR;
  self->handle = handle;
  return RESULT_SUCCESS;
}

void DynamicLibraryUnload(Self const *self) { dlclose(self->handle); }

Result DynamicLibraryLoadSymbol(DynamicLibrary const *self, cstr name,
                                OpaqueFunctionPointer *symbol) {
  OpaqueFunctionPointer symbol_ =
      (OpaqueFunctionPointer)dlsym(self->handle, name);
  if (!symbol_) return RESULT_ERRORR;
  *symbol = symbol_;
  return RESULT_SUCCESS;
}
