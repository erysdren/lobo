
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

const char *lev_patterns[2] = {"*.lev", "*.LEV"};
const char *lev_filename = NULL;
std::ifstream *lev_fstream = NULL;
kaitai::kstream *lev_kstream = NULL;
lev_quake_t *lev = NULL;
ostgl_context *gl_context = NULL;
GLuint gl_model;

//
//
// functions
//
//

//
// lev_load
//

void lev_load(const char *filename)
{
	// clear old
	if (lev) delete lev;
	if (lev_fstream) delete lev_fstream;
	if (lev_kstream) delete lev_kstream;

	// load
	if (filename)
	{
		lev_filename = (const char *)filename;
	}
	else
	{
		lev_filename = tinyfd_openFileDialog("Choose a LEV File", "", 2, lev_patterns, "Quake LEV Files", 0);
		if (lev_filename == NULL)
		{
			shim_error("lev_filename is NULL!");
			exit(1);
		}
	}

	// filestream
	lev_fstream = new std::ifstream(lev_filename, std::ifstream::binary);
	if (!lev_fstream->is_open())
	{
		shim_error("Couldn't open %s!", lev_filename);
		exit(1);
	}

	// kaitaistream
	lev_kstream = new kaitai::kstream(lev_fstream);

	// lev
	lev = new lev_quake_t(lev_kstream);

	// begin list
	gl_model = glGenLists(1);
	glNewList(gl_model, GL_COMPILE);
	glBegin(GL_QUADS);

	// planes
	for (int p = 0; p < lev->header()->num_planes(); p++)
	{
		// get plane
		lev_quake_t::plane_t *plane = (*lev->planes())[p];

		// quads
		for (int q = plane->quad_start_index(); q < plane->quad_end_index(); q++)
		{
			// get quad
			lev_quake_t::quad_t *quad = (*lev->quads())[q];

			// vertices
			for (int v = 0; v < 4; v++)
			{
				lev_quake_t::vertex_t *vertex = (*lev->vertices())[(*quad->vertex_indices())[v]];

				float x = (*vertex->coords())[0] / 512.0f;
				float y = (*vertex->coords())[1] / 512.0f;
				float z = (*vertex->coords())[2] / 512.0f;

				glVertex3f(x, y, z);
			}
		}
	}

	/* end list */
	glEnd();
	glEndList();
}

//
// main
//

int main(int argc, char **argv)
{
	// init gl
	gl_context = ostgl_create_context(WIDTH, HEIGHT, BPP);
	ostgl_make_current(gl_context);
	glEnable(GL_CULL_FACE);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);

	// load lev
	if (argc > 1)
		lev_load(argv[1]);
	else
		lev_load(NULL);

	// init window
	shim_init(gl_context->width, gl_context->height, gl_context->depth, "lobo");

	// main loop
	while (shim_frame())
	{
		// process events
		if (shim_key_read(SHIM_KEY_ESCAPE))
			shim_should_quit(SHIM_TRUE);

		// clear screen
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// do wireframe
		GLfloat white[4] = {1.0, 1.0, 1.0, 1.0};
		glPolygonMode(GL_FRONT, GL_LINE);
		glMaterialfv(GL_FRONT, GL_EMISSION, white);
		glPolygonOffset(0, -1);
		glCallList(gl_model);

		// blit
		shim_blit(gl_context->width, gl_context->height, gl_context->depth, gl_context->pixels);
	}

	// shutdown
	if (lev) delete lev;
	if (lev_fstream) delete lev_fstream;
	if (lev_kstream) delete lev_kstream;
	ostgl_delete_context(gl_context);
	shim_quit();

	// return success
	return 0;
}
