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
 * \brief X11Egl Display Factory.
 *//*--------------------------------------------------------------------*/

#include "tcuOhosEglDisplayFactory.hpp"
#include "egluGLContextFactory.hpp"
#include "eglwLibrary.hpp"
#include "eglwFunctions.hpp"
#include "eglwEnums.hpp"
#include "deUniquePtr.hpp"

namespace tcu
{
namespace OHOS_ROSEN
{
namespace egl
{

// typedef OHOS::Rosen::RSDisplayNode::SharedPtr    EGLNativeDisplayType;
// typedef ::Pixmap    EGLNativePixmapType;
// typedef ::Window    EGLNativeWindowType;

// DE_STATIC_ASSERT(sizeof(EGLNativeDisplayType)    <= sizeof(eglw::EGLNativeDisplayType));
// DE_STATIC_ASSERT(sizeof(EGLNativePixmapType)    <= sizeof(eglw::EGLNativePixmapType));
// DE_STATIC_ASSERT(sizeof(EGLNativeWindowType)    <= sizeof(eglw::EGLNativeWindowType));

extern "C"
{

// typedef EGLW_APICALL    eglw::EGLDisplay    (EGLW_APIENTRY* eglRosenGetDisplayFunc)            (EGLNativeDisplayType display_id);
// typedef EGLW_APICALL    eglw::EGLBoolean    (EGLW_APIENTRY* eglX11CopyBuffersFunc)            (eglw::EGLDisplay dpy, eglw::EGLSurface surface, EGLNativePixmapType target);
// typedef EGLW_APICALL    eglw::EGLSurface    (EGLW_APIENTRY* eglX11CreatePixmapSurfaceFunc)    (eglw::EGLDisplay dpy, eglw::EGLConfig config, EGLNativePixmapType pixmap, const eglw::EGLint* attrib_list);
// typedef EGLW_APICALL    eglw::EGLSurface    (EGLW_APIENTRY* eglX11CreateWindowSurfaceFunc)    (eglw::EGLDisplay dpy, eglw::EGLConfig config, EGLNativeWindowType win, const eglw::EGLint* attrib_list);

}

using std::string;

using de::MovePtr;
using de::UniquePtr;
using glu::ContextFactory;
using eglu::GLContextFactory;
using eglu::NativeDisplay;
using eglu::NativeDisplayFactory;
using eglu::NativeWindow;
using eglu::NativeWindowFactory;
using eglu::NativePixmap;
using eglu::NativePixmapFactory;
using eglu::WindowParams;
using tcu::TextureLevel;

class OhosLibrary : public eglw::DefaultLibrary
{
public:
    OhosLibrary (void)
        : eglw::DefaultLibrary("libGLESv1_impl.so")
    {
    }
};

class OhosDisplay : public NativeDisplay
{
public:
    static const Capability CAPABILITIES        = Capability(CAPABILITY_GET_DISPLAY_LEGACY );

    OhosDisplay                (void);
    virtual ~OhosDisplay         (void) {};

    void*                        getPlatformNative        (void)    { return this; }
    eglw::EGLNativeDisplayType    getPlatformExtension    (void)    { return reinterpret_cast<eglw::EGLNativeDisplayType>(this); }
    eglw::EGLNativeDisplayType    getLegacyNative            (void)    { return reinterpret_cast<eglw::EGLNativeDisplayType>(this); }

    NativeDisplay&                getOhosDisplay            (void)            { return *this;}
    const eglw::Library&        getLibrary                (void) const    { return m_library;    }
    const eglw::EGLAttrib*        getPlatformAttributes    (void) const    { return DE_NULL; }

private:
    OhosLibrary                        m_library;
};

OhosDisplay::OhosDisplay (void) 
    : NativeDisplay(eglu::NativeDisplay::CAPABILITY_GET_DISPLAY_LEGACY)
{
    //TODO: create display
}

class OhosWindow : public NativeWindow
{
public:
    static const Capability    CAPABILITIES        = Capability(CAPABILITY_CREATE_SURFACE_LEGACY |
                                                             CAPABILITY_CREATE_SURFACE_PLATFORM |
                                                             CAPABILITY_CREATE_SURFACE_PLATFORM_EXTENSION |
                                                             CAPABILITY_GET_SURFACE_SIZE |
                                                             CAPABILITY_SET_SURFACE_SIZE |
                                                             CAPABILITY_GET_SCREEN_SIZE);

    OhosWindow        (OhosDisplay&    display, const WindowParams&    params);

    eglw::EGLNativeWindowType    getLegacyNative            (void) { return nullptr; }
    void*                        getPlatformExtension    (void) { return nullptr; }
    void*                        getPlatformNative        (void) { return nullptr; }

    IVec2                        getSurfaceSize        (void) const;
    void                        setSurfaceSize        (IVec2 size);
    IVec2                        getScreenSize        (void) const { return getSurfaceSize(); }

};

OhosWindow::OhosWindow (OhosDisplay& display, const WindowParams& params)
    : NativeWindow    (CAPABILITIES)
{
    //TODO: 创建rosen window
    if (display.getPlatformNative() != nullptr) {
        printf("OhosWindow params: width=%d, height=%d\n", params.width, params.height);
    }
}

IVec2 OhosWindow::getSurfaceSize (void) const
{
    IVec2 ret;
    return ret;
}

void OhosWindow::setSurfaceSize (IVec2 size)
{
    //TODO: 设置size
    printf("setSurfaceSize IVec2: %d\n", size.x());
}

class OhosWindowFactory : public NativeWindowFactory
{
public:
                        OhosWindowFactory        (void);
    virtual                ~OhosWindowFactory (void) {};

    NativeWindow*        createWindow        (NativeDisplay*            nativeDisplay,
                                             const WindowParams&    params) const;
};

OhosWindowFactory::OhosWindowFactory (void)
    : NativeWindowFactory ("window", "Rosen Window", OhosWindow::CAPABILITIES)
{
}

NativeWindow* OhosWindowFactory::createWindow (NativeDisplay*        nativeDisplay,
                                           const WindowParams&    params) const
{
    //TODO: new native window
    OhosDisplay&    display    = *dynamic_cast<OhosDisplay*>(nativeDisplay);

    return dynamic_cast<NativeWindow*>(new OhosWindow(display, params));
}

class OhosPixmap : public NativePixmap
{
public:
    enum {
        CAPABILITIES = (CAPABILITY_CREATE_SURFACE_LEGACY |
                        CAPABILITY_CREATE_SURFACE_PLATFORM_EXTENSION |
                        CAPABILITY_READ_PIXELS)
    };

    OhosPixmap                (void);

    void*                    getPlatformNative    (void) { return this; }

};

OhosPixmap::OhosPixmap (void)
    : NativePixmap(eglu::NativePixmap::CAPABILITY_CREATE_SURFACE_LEGACY) 
{
    //TODO: create pixmap
}

class OhosPixmapFactory : public eglu::NativePixmapFactory
{
public:
    OhosPixmapFactory    (void)
        : eglu::NativePixmapFactory ("pixmap", "Rosen Pixmap", eglu::NativePixmap::CAPABILITY_CREATE_SURFACE_LEGACY) {};

    NativePixmap*    createPixmap    (NativeDisplay* nativeDisplay,
                                     int            width,
                                     int            height) const;
};

NativePixmap* OhosPixmapFactory::createPixmap (NativeDisplay* nativeDisplay,
                                           int            width,
                                           int            height) const

{
    //TODO create pixmap
    // OhosDisplay*                display        = dynamic_cast<OhosDisplay*>(nativeDisplay);
    if (nativeDisplay != nullptr) {
        printf("OhosPixmapFactory::createPixmap width=%d, height=%d,\n", width, height);
    }
    
    return new OhosPixmap();
}

class OhosDisplayFactory : public NativeDisplayFactory
{
public:
                        OhosDisplayFactory     (void);
    virtual                ~OhosDisplayFactory (void) {};

    NativeDisplay*        createDisplay        (const eglw::EGLAttrib* attribList) const;

};

OhosDisplayFactory::OhosDisplayFactory (void) 
    : eglu::NativeDisplayFactory("ROSEN", "Rosen Display", OhosDisplay::CAPABILITIES)
{
    //TODO: 增加window，pixmap factory
    m_nativeWindowRegistry.registerFactory(new OhosWindowFactory());
    m_nativePixmapRegistry.registerFactory(new OhosPixmapFactory());
}

NativeDisplay* OhosDisplayFactory::createDisplay (const eglw::EGLAttrib* attribList) const
{
    //TODO: create Rosen display
    DE_UNREF(attribList);
    return new OhosDisplay();
}

NativeDisplayFactory* createDisplayFactory (void)
{
    return new OhosDisplayFactory();
}

} // egl
} // OHOS
} // tcu
