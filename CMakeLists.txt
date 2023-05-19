
cmake_minimum_required(VERSION 3.3)
project(lobo LANGUAGES C CXX)

find_package(SDL2 REQUIRED)

add_subdirectory(${PROJECT_SOURCE_DIR}/source/thirdparty/kaitai)

set(LOBO_SOURCES
	${PROJECT_SOURCE_DIR}/source/main.cpp
	${PROJECT_SOURCE_DIR}/source/lev_quake.cpp
	${PROJECT_SOURCE_DIR}/source/shim.c
	${PROJECT_SOURCE_DIR}/source/thirdparty/tinyfiledialogs.c
)

add_executable(lobo ${LOBO_SOURCES})
target_compile_definitions(lobo PUBLIC -DSHIM_SDL2=1)
target_link_libraries(lobo PUBLIC kaitai_struct_cpp_stl_runtime)
target_link_libraries(lobo PUBLIC SDL2::SDL2)
target_link_libraries(lobo PUBLIC TinyGL)
target_link_directories(lobo PUBLIC ${PROJECT_SOURCE_DIR}/source/thirdparty/TinyGL/lib)
target_include_directories(lobo PUBLIC ${PROJECT_SOURCE_DIR}/source/thirdparty)
target_include_directories(lobo PUBLIC ${PROJECT_SOURCE_DIR}/source/thirdparty/kaitai)
target_include_directories(lobo PUBLIC ${PROJECT_SOURCE_DIR}/source/thirdparty/TinyGL/inc)
