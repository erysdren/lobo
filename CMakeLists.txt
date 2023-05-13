
cmake_minimum_required (VERSION 3.3)
project(lobo LANGUAGES C CXX)

add_subdirectory(thirdparty/kaitai)
add_subdirectory(thirdparty/imgui)

set(LOBO_SOURCES
	lobo/main.cpp
	lobo/lev_quake.cpp
	thirdparty/tinyfiledialogs.c
)

add_executable(lobo ${LOBO_SOURCES})
target_link_libraries(lobo PUBLIC kaitai_struct_cpp_stl_runtime)
target_link_libraries(lobo PUBLIC imgui)
target_include_directories(lobo PUBLIC thirdparty)
target_include_directories(lobo PUBLIC thirdparty/kaitai)
target_include_directories(lobo PUBLIC thirdparty/imgui)
