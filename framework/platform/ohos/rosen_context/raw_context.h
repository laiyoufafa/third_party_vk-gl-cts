/*
 * Copyright (c) 2022 Shenzhen Kaihong Digital Industry Development Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _RAW_CONTEXT_IMPL_H_
#define _RAW_CONTEXT_IMPL_H_

// #include <iostream>
// #include <surface.h>
// #include <ctime>
// #include <sys/time.h>

// #include "command/rs_base_node_command.h"
// #include "command/rs_display_node_command.h"
// #include "command/rs_surface_node_command.h"
// #include "common/rs_common_def.h"
// #include "display_type.h"
// #include "include/core/SkCanvas.h"
// #include "include/core/SkImageInfo.h"
// #include "pipeline/rs_render_result.h"
// #include "pipeline/rs_render_thread.h"
// #include "ui/rs_canvas_node.h"
// #include "ui/rs_surface_extractor.h"
// #include "ui/rs_ui_director.h"
// #include "transaction/rs_interfaces.h"
// #include "ui/rs_display_node.h"
// #include "ui/rs_surface_node.h"
#include "render_context/render_context.h"
// temporary debug
// #include "foundation/graphic/standard/rosen/modules/render_service_base/src/platform/ohos/rs_surface_frame_ohos.h"
// #include "foundation/graphic/standard/rosen/modules/render_service_base/src/platform/ohos/rs_surface_ohos.h"

// #include "ohos_context_i.h"

namespace OHOS {
namespace Rosen {



class RawContext : public RenderContext {
public:
    RawContext();
    EGLSurface CreateCurrentSurface();
private:
};

}
}

#endif