
cmake_minimum_required (VERSION 3.3)
project(imgui LANGUAGES CXX)

set(IMGUI_SOURCES
	imgui_demo.cpp
	imgui_draw.cpp
	imgui_tables.cpp
	imgui_widgets.cpp
	imgui.cpp
	backends/imgui_impl_glfw.cpp
	backends/imgui_impl_opengl3.cpp
)

add_library(imgui ${IMGUI_SOURCES})
target_include_directories(imgui PRIVATE ${PROJECT_SOURCE_DIR})
