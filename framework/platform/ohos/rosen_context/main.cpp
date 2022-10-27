#include <iostream>
#include <surface.h>
#include <ctime>
#include <sys/time.h>

#include "command/rs_base_node_command.h"
#include "command/rs_display_node_command.h"
#include "command/rs_surface_node_command.h"
#include "common/rs_common_def.h"
#include "display_type.h"
#include "include/core/SkCanvas.h"
#include "include/core/SkImageInfo.h"
#include "pipeline/rs_render_result.h"
#include "pipeline/rs_render_thread.h"
#include "ui/rs_canvas_node.h"
#include "ui/rs_surface_extractor.h"
#include "ui/rs_ui_director.h"
#include "transaction/rs_interfaces.h"
#include "ui/rs_display_node.h"
#include "ui/rs_surface_node.h"
#include "render_context/render_context.h"
// temporary debug
#include "foundation/graphic/standard/rosen/modules/render_service_base/src/platform/ohos/rs_surface_frame_ohos.h"
#include "foundation/graphic/standard/rosen/modules/render_service_base/src/platform/ohos/rs_surface_ohos.h"

using namespace OHOS;
using namespace Rosen;
using namespace std;
/*
class CCSurface
{
public:
    CCSurface();

    void OnDisplayConnected(ScreenId id);
    void OnDisplayDisConnected(ScreenId id);

    RenderContext *GetRenderContext() { return rc_; }

private:
    RSInterfaces &rsInterface_;
    std::unordered_map<ScreenId, RSScreenModeInfo> screens_;
    ScreenId defaultScreenId_;

    int screenWidth_ = 0;
    int screenheight_ = 0;
    int screenRefreshRate_ = 0;

    RenderContext *rc_ = nullptr;
};

CCSurface::CCSurface() : rsInterface_(RSInterfaces::GetInstance())
{
    // #ifdef ACE_ENABLE_GPU
    // #ifdef ACE_ENABLE_GL
    // rsInterface_.SetScreenChangeCallback([this](ScreenId id, ScreenEvent event)
    //                                      {
    //         switch (event) {
    //             case ScreenEvent::CONNECTED: {
    //                 this->OnDisplayConnected(id);
    //                 break;
    //             }
    //             case ScreenEvent::DISCONNECTED: {
    //                 this->OnDisplayDisConnected(id);
    //                 break;
    //             }
    //             default:
    //                 break;
    //         } });
    defaultScreenId_ = rsInterface_.GetDefaultScreenId();
    screens_[defaultScreenId_] = rsInterface_.GetScreenActiveMode(defaultScreenId_);

    screenWidth_ = screens_[defaultScreenId_].GetScreenWidth();
    screenheight_ = screens_[defaultScreenId_].GetScreenHeight();
    screenRefreshRate_ = static_cast<int>(screens_[defaultScreenId_].GetScreenRefreshRate());

    std::cout << "Screen " << defaultScreenId_ << " active mode info:\n";
    std::cout << "Width: " << screenWidth_ << ", Height: " << screenheight_;
    std::cout << ", RefreshRate: " << screenRefreshRate_ << "Hz.\n";

    rc_ = RenderContextFactory::GetInstance().CreateEngine();
    if (rc_)
    {
        std::cout << "Init RenderContext success.\n";
        rc_->InitializeEglContext();
        glDepthMask(GL_TRUE);
    }
    else
    {
        std::cout << "Init RenderContext failed, RenderContext is nullptr.\n";
    }
}

// void CCSurface::OnDisplayConnected(ScreenId id)
// {
//     screens_[id] = rsInterface_.GetScreenActiveMode(id);
//     std::cout << "DmsMock: Display " << id << " connected." << endl;
// }

// void CCSurface::OnDisplayDisConnected(ScreenId id)
// {
//     if (screens_.count(id) == 0)
//     {
//         cout << "DmsMock: No display " << id << "!" << endl;
//     }
//     else
//     {
//         std::cout << "DmsMock: Display " << id << " disconnected." << endl;
//         screens_.erase(id);
//         if (id == defaultScreenId_)
//         {
//             defaultScreenId_ = rsInterface_.GetDefaultScreenId();
//             std::cout << "DmsMock: DefaultDisplayId changed, new DefaultDisplayId is" << defaultScreenId_ << "."
//                       << endl;
//         }
//     }
// }
*/
int64_t GetNowTime()
{
    struct timeval start = {};
    gettimeofday(&start, nullptr);
    constexpr uint32_t secToUsec = 1000 * 1000;
    return static_cast<int64_t>(start.tv_sec) * secToUsec + start.tv_usec;
}

int main()
{

    // CCSurface ccs;

    auto transactionProxy = RSTransactionProxy::GetInstance();
    if (transactionProxy == nullptr)
    {
        printf("error 1\n");
        return -1;
    }
    RSDisplayNode::SharedPtr displayNode = RSDisplayNode::Create(RSDisplayNodeConfig());

    RenderContext *rc = RenderContextFactory::GetInstance().CreateEngine();
    if (!rc)
    {
        printf("error 2\n");
        return -1;
    }
    rc->InitializeEglContext();
    glDepthMask(GL_TRUE);

    std::shared_ptr<RSSurfaceNode> surfaceNode = RSSurfaceNode::Create(RSSurfaceNodeConfig());
    surfaceNode->SetBounds(100, 100, 100, 100);
    displayNode->AddChild(surfaceNode, -1);

    std::shared_ptr<RSSurface> rsSurface = RSSurfaceExtractor::ExtractRSSurface(surfaceNode);

    rsSurface->SetRenderContext(rc);
    auto framePtr = rsSurface->RequestFrame(100, 100);
    // printf("getExtensions 1 %s\n", glGetString(GL_VERSION));

    // printf("getExtensions 2 %s\n", glGetString(GL_EXTENSIONS));
    if (!framePtr)
    {
        printf("error 3\n");
        return -1;
    }

    rc->MakeCurrent(rc->GetEGLSurface());
    glViewport(0, 0, 100, 100);

    uint64_t t1 = GetNowTime();
    for (int i = 0; i < 100; i++)
    {
        glClearDepthf(1.0f);
        glClearColor(1.0 * ((i * 10) % 256) / 256, 0.0, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        rc->SwapBuffers(rc->GetEGLSurface());
        transactionProxy->FlushImplicitTransaction();
        printf("%d,%llu\n", i, GetNowTime() - t1);
        t1 = GetNowTime();
    }
    printf("ok\n");
    return 0;
}