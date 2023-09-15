#include <dynamic_library.h>

static void check(Result result) {
  if (result < RESULT_SUCCESS) __debugbreak();
}

typedef int(__stdcall *PFN_MessageBox)(opaque, wcstr, wcstr, u32);

int main() {
  DynamicLibrary user32;
  check(DynamicLibraryLoad(
      &(DynamicLibraryLoadInfo){
          .name = "user32",
      },
      &user32));

  PFN_MessageBox messageBox;
  check(DynamicLibraryLoadSymbol(&user32, "MessageBoxW",
                                 (OpaqueFunctionPointer)&messageBox));

  messageBox(nullptr, L"The operation failed successfully", L"Error", 0);
  DynamicLibraryUnload(&user32);
  return RESULT_SUCCESS;
}
