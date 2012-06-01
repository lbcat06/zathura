/* See LICENSE file for license and copyright information */

#ifndef RENDER_H
#define RENDER_H

#include <stdbool.h>
#include <stdlib.h>
#include <girara/types.h>

#include "zathura.h"
#include "callbacks.h"

/**
 * This function initializes a render thread
 *
 * @param zathura object
 * @return The render thread object or NULL if an error occured
 */
render_thread_t* render_init(zathura_t* zathura);

/**
 * This function destroys the render thread object
 *
 * @param render_thread The render thread object
 */
void render_free(render_thread_t* render_thread);

/**
 * This function is used to add a page to the render thread list
 * that should be rendered.
 *
 * @param render_thread The render thread object
 * @param page The page that should be rendered
 * @param printing Render the page for printing.
 * @param target Rendering target in case we're rendering for printing.
 * @return true if no error occured
 */
bool render_page(render_thread_t* render_thread, zathura_page_t* page, bool printing, cairo_t* target);

/**
 * This function is used to unmark all pages as not rendered. This should
 * be used if all pages should be rendered again (e.g.: the zoom level or the
 * colors have changed)
 *
 * @param zathura Zathura object
 */
void render_all(zathura_t* zathura);

#endif // RENDER_H
