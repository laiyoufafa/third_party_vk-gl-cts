# Render pass tests

include_directories(
	..
	../draw
	${DEQP_INL_DIR}
	)

set(DEQP_VK_RENDER_PASS_SRCS
	vktRenderPassTests.cpp
	vktRenderPassTests.hpp
	vktRenderPassTestsUtil.cpp
	vktRenderPassTestsUtil.hpp
	vktRenderPassMultisampleTests.cpp
	vktRenderPassMultisampleTests.hpp
	vktRenderPassMultisampleResolveTests.cpp
	vktRenderPassMultisampleResolveTests.hpp
	vktRenderPassDepthStencilResolveTests.cpp
	vktRenderPassDepthStencilResolveTests.hpp
	vktRenderPassSampleReadTests.cpp
	vktRenderPassSampleReadTests.hpp
	vktRenderPassSparseRenderTargetTests.cpp
	vktRenderPassSparseRenderTargetTests.hpp
	vktRenderPassSubpassDependencyTests.cpp
	vktRenderPassSubpassDependencyTests.hpp
	vktRenderPassUnusedAttachmentSparseFillingTests.hpp
	vktRenderPassUnusedAttachmentSparseFillingTests.cpp
	vktRenderPassUnusedAttachmentTests.cpp
	vktRenderPassUnusedAttachmentTests.hpp
	vktRenderPassUnusedClearAttachmentTests.cpp
	vktRenderPassUnusedClearAttachmentTests.hpp
	vktRenderPassFragmentDensityMapTests.cpp
	vktRenderPassFragmentDensityMapTests.hpp
	vktRenderPassMultipleSubpassesMultipleCommandBuffersTests.cpp
	vktRenderPassMultipleSubpassesMultipleCommandBuffersTests.hpp
	vktRenderPassLoadStoreOpNoneTests.cpp
	vktRenderPassLoadStoreOpNoneTests.hpp
	vktDynamicRenderingTests.cpp
	vktDynamicRenderingTests.hpp
	)

set(DEQP_VK_RENDER_PASS_LIBS
	tcutil
	vkutil
	deqp-vk-draw
	)

PCH(DEQP_VK_RENDER_PASS_SRCS ../pch.cpp)

add_library(deqp-vk-render-pass STATIC ${DEQP_VK_RENDER_PASS_SRCS})
target_link_libraries(deqp-vk-render-pass ${DEQP_VK_RENDER_PASS_LIBS})
