#ifndef _ES2ATEXTUREFILTERINGTESTS_HPP
#define _ES2ATEXTUREFILTERINGTESTS_HPP
/*-------------------------------------------------------------------------
 * drawElements Quality Program OpenGL ES 2.0 Module
 * -------------------------------------------------
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
 * \brief Texture filtering accuracy tests.
 *//*--------------------------------------------------------------------*/

#include "tcuDefs.hpp"
#include "tes2TestCase.hpp"

namespace deqp
{
namespace gles2
{
namespace Accuracy
{

class TextureFilteringTests : public TestCaseGroup
{
public:
								TextureFilteringTests		(Context& context);
								~TextureFilteringTests		(void);

	void						init						(void);

private:
								TextureFilteringTests		(const TextureFilteringTests& other);
	TextureFilteringTests&		operator=					(const TextureFilteringTests& other);
};

} // Accuracy
} // gles2
} // deqp

#endif // _ES2ATEXTUREFILTERINGTESTS_HPP
