
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
#include "imgui/backends/imgui_impl_glfw.h"
#include "imgui/backends/imgui_impl_opengl3.h"

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
std::ifstream *FileStream = NULL;
kaitai::kstream *KaitaiStream = NULL;
lev_quake_t *Lev = NULL;

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

	// init imgui
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(GlfwWindow, true);
	ImGui_ImplOpenGL3_Init("#version 130");
}

//
// DeInit
//

void DeInit()
{
	// imgui
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	// close window
	if (GlfwWindow)
		glfwDestroyWindow(GlfwWindow);

	// cloes library
	glfwTerminate();

	// clean up memory
	if (Lev) delete Lev;
	if (FileStream) delete FileStream;
	if (KaitaiStream) delete KaitaiStream;
}

//
// StartFrame
//

void StartFrame()
{
	// glfw
	glfwPollEvents();

	// imgui
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

//
// EndFrame
//

void EndFrame()
{
	// clear
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// imgui
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	// show
	glfwSwapBuffers(GlfwWindow);
}

//
// QuitMainLoop
//

void QuitMainLoop()
{
	glfwSetWindowShouldClose(GlfwWindow, GLFW_TRUE);
}

//
// LoadLev
//

void LoadLev(const char *filename)
{
	// clear old
	if (Lev) delete Lev;
	if (FileStream) delete FileStream;
	if (KaitaiStream) delete KaitaiStream;

	// load
	if (filename)
	{
		LevFilename = (const char *)filename;
	}
	else
	{
		LevFilename = tinyfd_openFileDialog("Choose a LEV File", "", 2, LevPatterns, "Quake LEV Files", 0);
		if (LevFilename == NULL) Error("LevFilename is NULL!");
	}

	// filestream
	FileStream = new std::ifstream(LevFilename, std::ifstream::binary);
	if (!FileStream->is_open()) Error("Couldn't open %s!", LevFilename);

	// kaitaistream
	KaitaiStream = new kaitai::kstream(FileStream);

	// lev
	Lev = new lev_quake_t(KaitaiStream);
}

//
// main
//

int main(int argc, char **argv)
{
	// load
	if (argc > 1)
		LoadLev(argv[1]);
	else
		LoadLev(NULL);

	// init
	Init(800, 600, "lobo");

	// main render loop
	while (!glfwWindowShouldClose(GlfwWindow))
	{
		// poll events
		StartFrame();

		// main menu bar
		if (ImGui::BeginMainMenuBar())
		{
			if (ImGui::BeginMenu("File", true))
			{
				if (ImGui::MenuItem("Load")) { LoadLev(NULL); }
				if (ImGui::MenuItem("Quit")) { QuitMainLoop(); }
				ImGui::EndMenu();
			}

			ImGui::EndMainMenuBar();
		}

		// double buffer
		EndFrame();
	}

	// deinit
	DeInit();

	// return success
	return 0;
}
