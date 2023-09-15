cmake_minimum_required(VERSION 3.27.4)
project(cdtk VERSION 0.1.0 LANGUAGES C)

include(cmake/util.cmake)

add_library(${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PUBLIC include)
setup(${PROJECT_NAME})
if(CMAKE_SYSTEM_NAME STREQUAL Windows)
  target_sources(${PROJECT_NAME} PRIVATE src/windows/dynamic_library.c)
else()
target_sources(${PROJECT_NAME} PRIVATE src/unix/dynamic_library.c)
endif()

if(PROJECT_IS_TOP_LEVEL)
  add_subdirectory(test)
  target_link_libraries(${PROJECT_NAME}_test PRIVATE ${PROJECT_NAME})
  setup(${PROJECT_NAME}_test)
endif()
