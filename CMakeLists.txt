
cmake_minimum_required(VERSION 3.3)
project(lobo LANGUAGES C CXX)

find_package(SDL2 REQUIRED)

add_subdirectory(thirdparty/kaitai)

set(LOBO_SOURCES
	source/main.cpp
	source/lev_quake.cpp
	source/thirdparty/tinyfiledialogs.c
)

add_executable(lobo ${LOBO_SOURCES})
target_link_libraries(lobo PUBLIC kaitai_struct_cpp_stl_runtime)
target_link_libraries(lobo PUBLIC SDL2::SDL2)
target_link_libraries(lobo PUBLIC thirdparty/TinyGL/lib/libTinyGL.a)
target_include_directories(lobo PUBLIC thirdparty/kaitai)
target_include_directories(lobo PUBLIC thirdparty/TinyGL/inc)
