#ifndef _GLX_drawable_h_
#define _GLX_drawable_h_

/*
 * SGI FREE SOFTWARE LICENSE B (Version 2.0, Sept. 18, 2008)
 * Copyright (C) 1991-2000 Silicon Graphics, Inc. All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice including the dates of first publication and
 * either this permission notice or a reference to
 * http://oss.sgi.com/projects/FreeB/
 * shall be included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * SILICON GRAPHICS, INC. BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Except as contained in this notice, the name of Silicon Graphics, Inc.
 * shall not be used in advertising or otherwise to promote the sale, use or
 * other dealings in this Software without prior written authorization from
 * Silicon Graphics, Inc.
 */

/* We just need to avoid clashing with DRAWABLE_{WINDOW,PIXMAP} */
enum {
    GLX_DRAWABLE_WINDOW,
    GLX_DRAWABLE_PIXMAP,
    GLX_DRAWABLE_PBUFFER,
    GLX_DRAWABLE_ANY
};

struct __GLXdrawable {
    void (*destroy) (__GLXdrawable * private);
     GLboolean(*swapBuffers) (ClientPtr client, __GLXdrawable *);
    void (*copySubBuffer) (__GLXdrawable * drawable,
                           int x, int y, int w, int h);
    void (*waitX) (__GLXdrawable *);
    void (*waitGL) (__GLXdrawable *);

    DrawablePtr pDraw;
    XID drawId;

    /*
     ** Either GLX_DRAWABLE_PIXMAP, GLX_DRAWABLE_WINDOW or
     ** GLX_DRAWABLE_PBUFFER.
     */
    int type;

    /*
     ** Configuration of the visual to which this drawable was created.
     */
    __GLXconfig *config;

    GLenum target;
    GLenum format;

    /*
     ** Event mask
     */
    unsigned long eventMask;
};

extern int validGlxDrawable(ClientPtr client, XID id, int type, int access_mode,
                            __GLXdrawable **drawable, int *err);

#endif                          /* !__GLX_drawable_h__ */
