#ifndef _TCUOHOSEGLPLATFORM_HPP
#define _TCUOHOSEGLPLATFORM_HPP
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

#include "egluPlatform.hpp"
#include "deUniquePtr.hpp"
#include "gluContextFactory.hpp"

namespace tcu
{
namespace OHOS
{
namespace egl
{

class Platform : public eglu::Platform
{
public:
    Platform                (void);
    virtual ~Platform        (void) {}

    de::MovePtr<glu::ContextFactory>    createContextFactory    (void);
};

} // egl
} // OHOS
} // tcu

#endif // _TCUOHOSEGLPLATFORM_HPP
