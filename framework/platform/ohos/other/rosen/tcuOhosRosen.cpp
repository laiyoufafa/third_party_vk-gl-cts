/*-------------------------------------------------------------------------
 * drawElements Quality Program Tester Core
 * ----------------------------------------
 *
 * Copyright 2014 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *//*!
 * \file
 * \brief X11 utilities.
 *//*--------------------------------------------------------------------*/

#include "gluRenderConfig.hpp"
#include "deMemory.h"

// #include <X11/Xutil.h>
// using namespace OHOS;
// using namespace Media;
// using namespace Rosen;
// using namespace std;

namespace tcu
{
namespace OHOS
{
namespace Rosen
{

// DisplayBase::DisplayBase ()
// {
// }

// DisplayBase::~DisplayBase (void)
// {
// }

// WindowBase::WindowBase ()
//     : m_visible    (false)
// {
// }

// WindowBase::~WindowBase (void)
// {
// }

OhosDisplay::DisplayState OhosDisplay::s_displayState = OhosDisplay::DISPLAY_STATE_UNKNOWN;

OhosDisplay::OhosDisplay (void)
{
    //TODO: create Rosen displaynode
    // OHOS::Rosen::RSDisplayNodeConfig config;
    // OHOS::Rosen::RSDisplayNode::SharedPtr displayNode = OHOS::Rosen::RSDisplayNode::Create(config);

}

OhosDisplay::~OhosDisplay (void)
{
    //TODO: 释放display
}

// void OhosDisplay::processEvent (XEvent& event)
// {
//     // switch (event.type)
//     // {
//     //     case ClientMessage:
//     //         if ((unsigned)event.xclient.data.l[0] == m_deleteAtom)
//     //             m_eventState.setQuitFlag(true);
//     //         break;
//     //     // note: ConfigureNotify for window is handled in setDimensions()
//     //     default:
//     //         break;
//     // }
//     switch (event.type)
//     {
//     default: /* constant-expression */:
//         /* code */
//         printf("event.type: %d.\n", event.type);
//         break;
    
//     default:
//         break;
//     }
// }

// void OhosDisplay::processEvents (void)
// {
//     // XEvent    event;

//     // while (XPending(m_display))
//     // {
//     //     XNextEvent(m_display, &event);
//     //     processEvent(event);
//     // }
// }

// bool OhosDisplay::getVisualInfo (VisualID visualID, XVisualInfo& dst)
// {
//     bool            succ        = false;

//     return succ;
// }

// ::Visual* OhosDisplay::getVisual (VisualID visualID)
// {
//     return DE_NULL;
// }

// XlibWindow::XlibWindow (OhosDisplay& display, int width, int height, ::Visual* visual)
//     : WindowBase    ()
//     , m_display        (display)
//     , m_colormap    (None)
//     , m_window        (None)
// {
//     XSetWindowAttributes    swa;
//     ::Display* const        dpy                    = m_display.getXDisplay();
//     ::Window                root                = DefaultRootWindow(dpy);
//     unsigned long            mask                = CWBorderPixel | CWEventMask;

//     // If redirect is enabled, window size can't be guaranteed and it is up to
//     // the window manager to decide whether to honor sizing requests. However,
//     // overriding that causes window to appear as an overlay, which causes
//     // other issues, so this is disabled by default.
//     const bool                overrideRedirect    = false;

//     int depth = CopyFromParent;

//     if (overrideRedirect)
//     {
//         mask |= CWOverrideRedirect;
//         swa.override_redirect = true;
//     }

//     if (visual == DE_NULL)
//         visual = CopyFromParent;
//     else
//     {
//         XVisualInfo    info    = XVisualInfo();
//         bool        succ    = display.getVisualInfo(XVisualIDFromVisual(visual), info);

//         TCU_CHECK_INTERNAL(succ);

//         root                = RootWindow(dpy, info.screen);
//         m_colormap            = XCreateColormap(dpy, root, visual, AllocNone);
//         swa.colormap        = m_colormap;
//         mask |= CWColormap;

//         depth = info.depth;
//     }

//     swa.border_pixel    = 0;
//     swa.event_mask        = ExposureMask|KeyPressMask|KeyReleaseMask|StructureNotifyMask;

//     if (width == glu::RenderConfig::DONT_CARE)
//         width = DEFAULT_WINDOW_WIDTH;
//     if (height == glu::RenderConfig::DONT_CARE)
//         height = DEFAULT_WINDOW_HEIGHT;

//     m_window = XCreateWindow(dpy, root, 0, 0, width, height, 0,
//                              depth, InputOutput, visual, mask, &swa);
//     TCU_CHECK(m_window);

//     /* Prevent the window from stealing input, since our windows are
//      * non-interactive.
//      */
//     XWMHints *hints = XAllocWMHints();
//     hints->flags |= InputHint;
//     hints->input = False;
//     XSetWMHints(dpy, m_window, hints);
//     XFree(hints);

//     Atom deleteAtom = m_display.getDeleteAtom();
//     XSetWMProtocols(dpy, m_window, &deleteAtom, 1);
//     XSync(dpy,false);
// }

// void XlibWindow::setVisibility (bool visible)
// {
//     ::Display*    dpy            = m_display.getXDisplay();
//     int            eventType    = None;
//     XEvent        event;

//     if (visible == m_visible)
//         return;

//     if (visible)
//     {
//         XMapWindow(dpy, m_window);
//         eventType = MapNotify;
//     }
//     else
//     {
//         XUnmapWindow(dpy, m_window);
//         eventType = UnmapNotify;
//     }

//     // We are only interested about exposure/structure notify events, not user input
//     XSelectInput(dpy, m_window, ExposureMask | StructureNotifyMask);

//     do
//     {
//         XWindowEvent(dpy, m_window, ExposureMask | StructureNotifyMask, &event);
//     } while (event.type != eventType);

//     m_visible = visible;
// }

// void XlibWindow::getDimensions (int* width, int* height) const
// {
//     int x, y;
//     ::Window root;
//     unsigned width_, height_, borderWidth, depth;

//     XGetGeometry(m_display.getXDisplay(), m_window, &root, &x, &y, &width_, &height_, &borderWidth, &depth);
//     if (width != DE_NULL)
//         *width = static_cast<int>(width_);
//     if (height != DE_NULL)
//         *height = static_cast<int>(height_);
// }

// void XlibWindow::setDimensions (int width, int height)
// {
//     const unsigned int    mask        = CWWidth | CWHeight;
//     XWindowChanges        changes;
//     ::Display*            dpy            = m_display.getXDisplay();
//     XEvent                myevent;
//     changes.width    = width;
//     changes.height    = height;
//     XConfigureWindow(dpy, m_window, mask, &changes);
//     XFlush(dpy);

//     for(;;)
//     {
//         XNextEvent(dpy, &myevent);
//         if (myevent.type == ConfigureNotify) {
//             XConfigureEvent e = myevent.xconfigure;
//             if (e.width == width && e.height == height)
//                 break;
//         }
//         else
//             m_display.processEvent(myevent);
//     }
// }

// void XlibWindow::processEvents (void)
// {
//     // A bit of a hack, since we don't really handle all the events.
//     m_display.processEvents();
// }

// XlibWindow::~XlibWindow (void)
// {
//     XDestroyWindow(m_display.getXDisplay(), m_window);
//     if (m_colormap != None)
//         XFreeColormap(m_display.getXDisplay(), m_colormap);
// }

} // OHOS
} // tcu
