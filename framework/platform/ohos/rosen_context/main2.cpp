#include <ctime>
#include <sys/time.h>

#include <hilog/log.h>
#include <ipc_skeleton.h>
#include <platform/ohos/rs_irender_service.h>

#include <display_type.h>
#include <display_manager.h>
#include <foundation/windowmanager/interfaces/innerkits/wm/window_manager.h>
#include <ipc_skeleton.h>
#include <iremote_broker.h>
// #include <iservice_registry.h>
#include <platform/ohos/rs_irender_service.h>
// #include <parameters.h>
#include <render_context/render_context.h>
// #include <system_ability_definition.h>
#include <ui/rs_surface_extractor.h>
#include <vsync_helper.h>
#include <window.h>
#include <window_option.h>
#include <window_scene.h>

using namespace OHOS;
using namespace Rosen;

int64_t GetNowTime()
{
    struct timeval start = {};
    gettimeofday(&start, nullptr);
    constexpr uint32_t secToUsec = 1000 * 1000;
    return static_cast<int64_t>(start.tv_sec) * secToUsec + start.tv_usec;
}

int main()
{
    sptr<WindowOption> option = new WindowOption();
    option->SetWindowType(WindowType::WINDOW_TYPE_BOOT_ANIMATION);
    option->RemoveWindowFlag(WindowFlag::WINDOW_FLAG_NEED_AVOID);
    option->SetWindowRect({100, 100, 100, 100});
    int displayId = 0;
    sptr<IWindowLifeCycle> listener = nullptr;
    WindowScene *scene_ = new WindowScene(); /////////////////////////////////////////////////////
    scene_->Init(displayId, nullptr, listener, option);
    auto window_ = scene_->GetMainWindow(); ////////////////////////////////////////////////
    while (window_ == nullptr)
    {
        printf("window is nullptr, continue to init window\n");
        scene_->Init(displayId, nullptr, listener, option);
        window_ = scene_->GetMainWindow();
        sleep(1);
    }
    scene_->GoForeground();

    std::shared_ptr<RSSurface> rsSurface_ = RSSurfaceExtractor::ExtractRSSurface(window_->GetSurfaceNode());
    if (rsSurface_ == nullptr)
    {
        printf("rsSurface is nullptr");
        return -1;
    }
    RenderContext *rc_ = RenderContextFactory::GetInstance().CreateEngine();
    if (rc_ == nullptr)
    {
        printf("InitilizeEglContext failed\n");
        return -1;
    }
    else
    {
        printf("init egl context\n");
        rc_->InitializeEglContext();
        rsSurface_->SetRenderContext(rc_);
    }

    std::unique_ptr<RSSurfaceFrame> frame = rsSurface_->RequestFrame(1000, 1000);
    if (!frame)
    {
        printf("error 3\n");
        return -1;
    }

    rc_->MakeCurrent(rc_->GetEGLSurface());
    glViewport(0, 0, 100, 100);

    uint64_t t1 = GetNowTime();
    for (int i = 0; i < 100; i++)
    {
        glClearDepthf(1.0f);
        glClearColor(1.0 * ((i * 10) % 256) / 256, 0.0, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        rc_->SwapBuffers(rc_->GetEGLSurface());
        printf("%d,%llu\n", i, GetNowTime() - t1);
        t1 = GetNowTime();
    }
    printf("ok\n");
    return 0;
}