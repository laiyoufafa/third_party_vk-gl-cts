# Memory tests

include_directories(
	..
	../util
	${DEQP_INL_DIR}
	)

set(DEQP_VK_MEMORY_SRCS
	vktMemoryTests.cpp
	vktMemoryTests.hpp
	vktMemoryAllocationTests.cpp
	vktMemoryAllocationTests.hpp
	vktMemoryMappingTests.cpp
	vktMemoryMappingTests.hpp
	vktMemoryPipelineBarrierTests.hpp
	vktMemoryPipelineBarrierTests.cpp
	vktMemoryRequirementsTests.cpp
	vktMemoryRequirementsTests.hpp
	vktMemoryBindingTests.cpp
	vktMemoryBindingTests.hpp
	vktMemoryExternalMemoryHostTests.cpp
	vktMemoryExternalMemoryHostTests.hpp
	vktMemoryDeviceMemoryReportTests.cpp
	vktMemoryDeviceMemoryReportTests.hpp
	)

set(DEQP_VK_MEMORY_LIBS
	tcutil
	vkutil
	)

PCH(DEQP_VK_MEMORY_SRCS ../pch.cpp)

add_library(deqp-vk-memory STATIC ${DEQP_VK_MEMORY_SRCS})
target_link_libraries(deqp-vk-memory ${DEQP_VK_MEMORY_LIBS})
