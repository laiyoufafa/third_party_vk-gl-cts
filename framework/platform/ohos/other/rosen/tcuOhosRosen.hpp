#ifndef _TCUOHOSROSEN_HPP
#define _TCUOHOSROSEN_HPP
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

#include "tcuDefs.hpp"
#include "gluRenderConfig.hpp"
#include "gluPlatform.hpp"
#include "tcuOhos.hpp"

#include <iostream>
// #include <surface.h>
#include <cmath>
#include <securec.h>

// #include "command/rs_base_node_command.h"
// #include "command/rs_display_node_command.h"
// #include "command/rs_surface_node_command.h"
// #include "common/rs_common_def.h"
// #include "display_type.h"
// #include "pipeline/rs_render_result.h"
// #include "pipeline/rs_render_thread.h"
// #include "ui/rs_node.h"
// #include "ui/rs_surface_extractor.h"
// #include "ui/rs_ui_director.h"
// #include "core/transaction/rs_interfaces.h"
#include "core/ui/rs_display_node.h"
// #include "core/ui/rs_surface_node.h"
// temporary debug
// #include "foundation/graphic/standard/ROSEN/modules/render_service_base/src/platform/OHOS/rs_surface_frame_ohos.h"
// #include "foundation/graphic/standard/ROSEN/modules/render_service_base/src/platform/OHOS/rs_surface_ohos.h"
// #include <X11/Xlib.h>
// #include <X11/Xutil.h>
// #include <X11/keysym.h>
// #include <X11/Xatom.h>

namespace tcu
{
namespace OHOS
{
namespace Rosen
{

class OhosDisplay : public eglu::NativeDisplay
{
public:
                    OhosDisplay    (void);
    virtual            ~OhosDisplay    (void);

    OHOS::Rosen::RSDisplayNode::SharedPtr        getRDisplay        (void) { return m_display;}

    static DisplayState    s_displayState;

protected:
    OHOS::Rosen::RSDisplayNode::SharedPtr        m_display;

private:
                    OhosDisplay        (const OhosDisplay&);
    OhosDisplay&    operator=            (const OhosDisplay&);
};

class OhosWindow : public eglu::NativeWindow
{
public:
                    OhosWindow            (OhosDisplay& display, int width, int height);
                    ~OhosWindow        (void);

    void            setVisibility    (bool visible);

    void            processEvents    (void);
    DisplayBase&    getDisplay        (void) { return (eglu::NativeDisplay&)m_display; }

    void            getDimensions    (int* width, int* height) const;
    void            setDimensions    (int width, int height);

protected:
    OhosDisplay&    m_display;

private:
                    OhosWindow        (const OhosWindow&);
    OhosWindow&    operator=    (const OhosWindow&);
};

} // OHOS
} // tcu

#endif // _TCUOHOSROSEN_HPP
