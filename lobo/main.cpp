
//
//
// headers
//
//

// std
#include <iostream>
#include <fstream>
#include <stdint.h>
#include <stdarg.h>

// kaitai
#include "lev_quake.h"

// tinyfiledialogs
#include "tinyfiledialogs.h"

// imgui
#include "imgui/imgui.h"

// gl
#include "GLFW/glfw3.h"

//
//
// globals
//
//

const char *LevPatterns[2] = {"*.lev", "*.LEV"};
const char *LevFilename = NULL;
GLFWwindow *GlfwWindow = NULL;

//
//
// functions
//
//

//
// Error
//

void Error(const char *s, ...)
{
	va_list ap;

	va_start(ap, s);
	vfprintf(stderr, s, ap);
	va_end(ap);

	exit(1);
}

//
// GlfwError
//

void GlfwError()
{
	const char *error;
	glfwGetError(&error);
	Error("%s", error);	
}

//
// Init
//

void Init(int w, int h, const char *title)
{
	// init library
	if (glfwInit() != GLFW_TRUE)
		GlfwError();

	// open window
	glfwDefaultWindowHints();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	GlfwWindow = glfwCreateWindow(w, h, title, NULL, NULL);
	if (GlfwWindow == NULL)
		GlfwError();

	// make current
	glfwMakeContextCurrent(GlfwWindow);
	glfwSwapInterval(1);
}

//
// DeInit
//

void DeInit()
{
	// close window
	if (GlfwWindow)
		glfwDestroyWindow(GlfwWindow);

	// cloes library
	glfwTerminate();
}

//
// StartFrame
//

void StartFrame()
{
	glfwPollEvents();
}

//
// EndFrame
//

void EndFrame()
{
	glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glfwSwapBuffers(GlfwWindow);
}

//
// main
//

int main(int argc, char **argv)
{
	// check for arg
	if (argc < 2)
	{
		LevFilename = tinyfd_openFileDialog("Choose a LEV File", "", 2, LevPatterns, "Quake LEV Files", 0);
		if (LevFilename == NULL) Error("LevFilename is NULL!");
	}
	else
	{
		LevFilename = (const char *)argv[1];
	}

	// open file stream
	std::ifstream fstream(LevFilename, std::ifstream::binary);
	if (!fstream.is_open()) Error("Couldn't open %s!", LevFilename);

	// open kaitai stream
	kaitai::kstream kstream(&fstream);

	// open lev
	lev_quake_t lev(&kstream);

	// init
	Init(800, 600, "lobo");

	// main render loop
	while (!glfwWindowShouldClose(GlfwWindow))
	{
		// poll events
		StartFrame();

		// process inputs
		if (glfwGetKey(GlfwWindow, GLFW_KEY_ESCAPE))
			glfwSetWindowShouldClose(GlfwWindow, GLFW_TRUE);

		// double buffer
		EndFrame();
	}

	// deinit
	DeInit();

	// return success
	return 0;
}
