
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

// shim
#include "shim.h"

// gl
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/ostinygl.h>

// kaitai
#include "lev_quake.h"

// tinyfiledialogs
#include "thirdparty/tinyfiledialogs.h"

//
//
// globals
//
//

#define WIDTH 800
#define HEIGHT 600
#define BPP 16

//
//
// globals
//
//

const char *LevPatterns[2] = {"*.lev", "*.LEV"};
const char *LevFilename = NULL;
std::ifstream *FileStream = NULL;
kaitai::kstream *KaitaiStream = NULL;
lev_quake_t *Lev = NULL;
ostgl_context *GlContext = NULL;

//
//
// functions
//
//

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
		if (LevFilename == NULL)
		{
			shim_error("LevFilename is NULL!");
			exit(1);
		}
	}

	// filestream
	FileStream = new std::ifstream(LevFilename, std::ifstream::binary);
	if (!FileStream->is_open())
	{
		shim_error("Couldn't open %s!", LevFilename);
		exit(1);
	}

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
	// load lev
	if (argc > 1)
		LoadLev(argv[1]);
	else
		LoadLev(NULL);

	// init window
	GlContext = ostgl_create_context(WIDTH, HEIGHT, BPP);
	ostgl_make_current(GlContext);
	shim_init(GlContext->width, GlContext->height, GlContext->depth, "lobo");

	// main loop
	while (shim_frame())
	{
		if (shim_key_read(SHIM_KEY_ESCAPE))
			shim_should_quit(SHIM_TRUE);

		glClearColor(1, 0, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		shim_blit(GlContext->width, GlContext->height, GlContext->depth, GlContext->pixels);
	}

	// shutdown
	ostgl_delete_context(GlContext);
	shim_quit();

	// return success
	return 0;
}
