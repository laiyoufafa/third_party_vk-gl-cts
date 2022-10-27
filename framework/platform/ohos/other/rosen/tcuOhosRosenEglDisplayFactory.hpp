#ifndef _TCULNXX11EGLDISPLAYFACTORY_HPP
#define _TCULNXX11EGLDISPLAYFACTORY_HPP
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

#include "tcuOhos.hpp"
#include "egluNativeDisplay.hpp"

namespace tcu
{
namespace OHOS
{
namespace Rosen
{
namespace egl
{

eglu::NativeDisplayFactory* createDisplayFactory (void);

}
} // OHOS
} // tcu

#endif // _TCULNXX11EGLDISPLAYFACTORY_HPP
