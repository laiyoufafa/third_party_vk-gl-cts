include_directories(
	..
	../amber
	${DEQP_INL_DIR}
	)

set(DEQP_VK_COMPUTE_SRCS
	vktComputeTests.cpp
	vktComputeTests.hpp
	vktComputeBasicComputeShaderTests.cpp
	vktComputeBasicComputeShaderTests.hpp
	vktComputeCooperativeMatrixTests.cpp
	vktComputeCooperativeMatrixTests.hpp
	vktComputeIndirectComputeDispatchTests.cpp
	vktComputeIndirectComputeDispatchTests.hpp
	vktComputeShaderBuiltinVarTests.cpp
	vktComputeShaderBuiltinVarTests.hpp
	vktComputeTestsUtil.cpp
	vktComputeTestsUtil.hpp
	vktComputeZeroInitializeWorkgroupMemoryTests.cpp
	vktComputeZeroInitializeWorkgroupMemoryTests.hpp
	vktComputeWorkgroupMemoryExplicitLayoutTests.cpp
	vktComputeWorkgroupMemoryExplicitLayoutTests.hpp
	)

set(DEQP_VK_COMPUTE_LIBS
	tcutil
	vkutil
	)

PCH(DEQP_VK_COMPUTE_SRCS ../pch.cpp)

add_library(deqp-vk-compute STATIC ${DEQP_VK_COMPUTE_SRCS})
target_link_libraries(deqp-vk-compute ${DEQP_VK_COMPUTE_LIBS})
