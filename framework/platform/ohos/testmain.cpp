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

#include <cstdio>
#include <iostream>
#include "tcuDefs.hpp"
#include "tcuCommandLine.hpp"
#include "tcuPlatform.hpp"
#include "tcuApp.hpp"
#include "tcuResource.hpp"
#include "tcuTestLog.hpp"
#include "tcuTestSessionExecutor.hpp"
#include "deUniquePtr.hpp"

#include "external/openglcts/modules/common/glcConfigPackage.hpp"
#include "external/openglcts/modules/common/glcTestPackage.hpp"
#include "external/openglcts/modules/gles2/es2cTestPackage.hpp"
#include "external/openglcts/modules/gles3/es3cTestPackage.hpp"
#include "external/openglcts/modules/gles32/es32cTestPackage.hpp"
#include "external/openglcts/modules/gles31/es31cTestPackage.hpp"

#include "modules/gles2/tes2TestPackage.hpp"
#include "modules/gles3/tes3TestPackage.hpp"
#include "modules/gles31/tes31TestPackage.hpp"

#include "ohos_context_i.h"

#include "tcuTestContext.hpp"
#include "tcuOhosPlatform.hpp"

static tcu::TestPackage *createES2Package(tcu::TestContext &testCtx)
{
    return new es2cts::TestPackage(testCtx, "KHR-GLES2");
}

static tcu::TestPackage *createES32Package(tcu::TestContext &testCtx)
{
    return new es32cts::ES32TestPackage(testCtx, "KHR-GLES32");
}
static tcu::TestPackage* createES30Package(tcu::TestContext& testCtx)
{
	return new es3cts::ES30TestPackage(testCtx, "KHR-GLES3");
}
static tcu::TestPackage* createES31Package(tcu::TestContext& testCtx)
{
	return new es31cts::ES31TestPackage(testCtx, "KHR-GLES31");
}

static tcu::TestPackage* createdEQPES2Package(tcu::TestContext& testCtx)
{
	return new deqp::gles2::TestPackage(testCtx);
}
static tcu::TestPackage* createdEQPES30Package(tcu::TestContext& testCtx)
{
	return new deqp::gles3::TestPackage(testCtx);
}
static tcu::TestPackage* createdEQPES31Package(tcu::TestContext& testCtx)
{
	return new deqp::gles31::TestPackage(testCtx);
}

// Implement this in your platform port.

void RegistPackage()
{

    tcu::TestPackageRegistry *registry = tcu::TestPackageRegistry::getSingleton();
    // registry->registerPackage("CTS-Configs", createConfigPackage);

    // TODO: 判断当前上下文EGL环境是哪个?
    /*
KHR-GLES2
KHR-GLES3
KHR-GLES31
KHR-GLESEXT
KHR-GLES32
    */
    // OHOS::Rosen::RosenContext::GetInstance().GetGlesVer() == 3.2
    registry->registerPackage("KHR-GLES31", createES31Package);
    registry->registerPackage("KHR-GLES2", createES2Package);
    registry->registerPackage("KHR-GLES3", createES30Package);
    registry->registerPackage("KHR-GLES32", createES32Package);
    registry->registerPackage("dEQP-GLES2", createdEQPES2Package);
    registry->registerPackage("dEQP-GLES3", createdEQPES30Package);
    registry->registerPackage("dEQP-GLES31", createdEQPES31Package);
}

void InitCase(tcu::TestNode *node)
{

    switch (node->getNodeType())
    {
    case tcu::NODETYPE_PACKAGE: // 1,		//!< Test case package -- same as group, but is omitted from XML dump.
    case tcu::NODETYPE_GROUP:   // 2,			//!< Test case container -- cannot be executed.
        node->init();
    case tcu::NODETYPE_ROOT: // = 0,		//!< Root for all test packages.
    {
        std::vector<tcu::TestNode *> children;
        node->getChildren(children);
        for (uint32_t i = 0; i < children.size(); i++)
        {
            InitCase(children[i]);
        }
    }
    break;
    case tcu::NODETYPE_SELF_VALIDATE: // 3,	//!< Self-validating test case -- can be executed
    case tcu::NODETYPE_PERFORMANCE:   // 4,	//!< Performace test case -- can be executed
    case tcu::NODETYPE_CAPABILITY:    // 5,	//!< Capability score case -- can be executed
    case tcu::NODETYPE_ACCURACY:      // 6		//!< Accuracy test case -- can be executed
        break;
    }
}
bool GetCasePath(tcu::TestNode *node, std::vector<tcu::TestNode *> &casePath, std::vector<std::string> &namePath, uint32_t deep = 0)
{
    if (deep >= namePath.size())
        return false;
    if (namePath[deep].compare(node->getName()) != 0)
        return false;
    casePath.push_back(node);
    switch (node->getNodeType())
    {
    case tcu::NODETYPE_ROOT: // = 0,		//!< Root for all test packages.
        printf("NODETYPE_ROOT\n");
        break;
    case tcu::NODETYPE_PACKAGE: //,		//!< Test case package -- same as group, but is omitted from XML dump.
    case tcu::NODETYPE_GROUP: //,			//!< Test case container -- cannot be executed.
        printf("NODETYPE_GROUP\n");
        {
            std::vector<tcu::TestNode *> children;
            node->getChildren(children);
            for (uint32_t i = 0; i < children.size(); i++)
            {
                // printf("-----------%s==%s\n",children[i]->getName(),namePath[deep+1].c_str());
                if (GetCasePath(children[i], casePath, namePath, deep + 1))
                    return true;
            }
        }
        break;
    case tcu::NODETYPE_SELF_VALIDATE: //,	//!< Self-validating test case -- can be executed
        printf("NODETYPE_SELF_VALIDATE\n");
        return true;
    case tcu::NODETYPE_PERFORMANCE: //,	//!< Performace test case -- can be executed
        printf("NODETYPE_PERFORMANCE\n");
        return true;
    case tcu::NODETYPE_CAPABILITY: //,	//!< Capability score case -- can be executed
        printf("NODETYPE_CAPABILITY\n");
        return true;
    case tcu::NODETYPE_ACCURACY: //		//!< Accuracy test case -- can be executed
        printf("NODETYPE_ACCURACY\n");
        return true;
    }
    return false;
}

int main(int argc, char **argv)
{
    printf("testmain start --- \n");
    int exitStatus = EXIT_SUCCESS;

#if (DE_OS != DE_OS_WIN32)
    // Set stdout to line-buffered mode (will be fully buffered by default if stdout is pipe).
    setvbuf(stdout, DE_NULL, _IOLBF, 4 * 1024);
#endif

    try
    {
        RegistPackage();

        tcu::CommandLine cmdLine(argc, argv);
        tcu::DirArchive archive(cmdLine.getArchiveDir());
        tcu::TestLog log(cmdLine.getLogFileName(), cmdLine.getLogFlags());
        de::UniquePtr<tcu::Platform> platform(createOhosPlatform());

        if(1==0)
        {
            std::string caseName = "KHR-GLES2.shaders.aggressive_optimizations.sin_float_frag";
            std::vector<std::string> namePath;
            size_t offp = 0;
            while (true)
            {
                int32_t i = caseName.find_first_of('.', offp);
                if (i == -1)
                {
                    namePath.push_back(caseName.substr(offp));
                    break;
                }
                namePath.push_back(caseName.substr(offp, i - offp));
                offp = i + 1;
            }
            // Create test context
            tcu::TestContext *m_testCtx = new tcu::TestContext(*platform, archive, log, cmdLine, DE_NULL);
            // Create root from registry
            tcu::TestPackageRoot *m_testRoot = new tcu::TestPackageRoot(*m_testCtx, tcu::TestPackageRegistry::getSingleton());
            InitCase(m_testRoot);

            std::vector<tcu::TestNode *> children;
            m_testRoot->getChildren(children);
            for (uint32_t i = 0; i < children.size(); i++)
            {
                std::vector<tcu::TestNode *> casePath;
                printf("GetPathPath %s\n",GetCasePath(children[i], casePath, namePath)?"true":"false");
                for(uint32_t j=0;j<casePath.size();j++)
                {
                    printf("%d %s\n",j,casePath[j]->getName());
                }
                uint32_t p=casePath.size()-1;
                printf("run testcast 1\n");
                casePath[p]->init();
                printf("run testcast 2\n");
                casePath[p]->iterate();
                printf("run testcast 3\n");
                casePath[p]->deinit();
                printf("run testcast 4\n");
            }
            exit(0);
        }

        de::UniquePtr<tcu::App> app(new tcu::App(*platform, archive, log, cmdLine));

        // Main loop.
        for (;;)
        {
            if (!app->iterate())
            {
                if (cmdLine.getRunMode() == tcu::RUNMODE_EXECUTE &&
                    (!app->getResult().isComplete || app->getResult().numFailed))
                {
                    exitStatus = EXIT_FAILURE;
                }

                break;
            }
        }
    }
    catch (const std::exception &e)
    {
        tcu::die("%s", e.what());
    }

    return exitStatus;
}