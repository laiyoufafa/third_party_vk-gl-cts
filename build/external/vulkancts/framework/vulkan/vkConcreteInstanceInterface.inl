/* WARNING: This is auto-generated file. Do not modify, since changes will
 * be lost! Modify the generating script instead.
 */
virtual void		destroyInstance													(VkInstance instance, const VkAllocationCallbacks* pAllocator) const;
virtual VkResult	enumeratePhysicalDevices										(VkInstance instance, uint32_t* pPhysicalDeviceCount, VkPhysicalDevice* pPhysicalDevices) const;
virtual void		getPhysicalDeviceFeatures										(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures* pFeatures) const;
virtual void		getPhysicalDeviceFormatProperties								(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties* pFormatProperties) const;
virtual VkResult	getPhysicalDeviceImageFormatProperties							(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkImageFormatProperties* pImageFormatProperties) const;
virtual void		getPhysicalDeviceProperties										(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties* pProperties) const;
virtual void		getPhysicalDeviceQueueFamilyProperties							(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties* pQueueFamilyProperties) const;
virtual void		getPhysicalDeviceMemoryProperties								(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties* pMemoryProperties) const;
virtual VkResult	createDevice													(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDevice* pDevice) const;
virtual VkResult	enumerateDeviceExtensionProperties								(VkPhysicalDevice physicalDevice, const char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties) const;
virtual VkResult	enumerateDeviceLayerProperties									(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkLayerProperties* pProperties) const;
virtual void		getPhysicalDeviceSparseImageFormatProperties					(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, uint32_t* pPropertyCount, VkSparseImageFormatProperties* pProperties) const;
virtual VkResult	enumeratePhysicalDeviceGroups									(VkInstance instance, uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties) const;
virtual void		getPhysicalDeviceFeatures2										(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures) const;
virtual void		getPhysicalDeviceProperties2									(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties) const;
virtual void		getPhysicalDeviceFormatProperties2								(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2* pFormatProperties) const;
virtual VkResult	getPhysicalDeviceImageFormatProperties2							(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo, VkImageFormatProperties2* pImageFormatProperties) const;
virtual void		getPhysicalDeviceQueueFamilyProperties2							(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties2* pQueueFamilyProperties) const;
virtual void		getPhysicalDeviceMemoryProperties2								(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties) const;
virtual void		getPhysicalDeviceSparseImageFormatProperties2					(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, VkSparseImageFormatProperties2* pProperties) const;
virtual void		getPhysicalDeviceExternalBufferProperties						(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo, VkExternalBufferProperties* pExternalBufferProperties) const;
virtual void		getPhysicalDeviceExternalFenceProperties						(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo, VkExternalFenceProperties* pExternalFenceProperties) const;
virtual void		getPhysicalDeviceExternalSemaphoreProperties					(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, VkExternalSemaphoreProperties* pExternalSemaphoreProperties) const;
virtual void		destroySurfaceKHR												(VkInstance instance, VkSurfaceKHR surface, const VkAllocationCallbacks* pAllocator) const;
virtual VkResult	getPhysicalDeviceSurfaceSupportKHR								(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, VkSurfaceKHR surface, VkBool32* pSupported) const;
virtual VkResult	getPhysicalDeviceSurfaceCapabilitiesKHR							(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilitiesKHR* pSurfaceCapabilities) const;
virtual VkResult	getPhysicalDeviceSurfaceFormatsKHR								(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pSurfaceFormatCount, VkSurfaceFormatKHR* pSurfaceFormats) const;
virtual VkResult	getPhysicalDeviceSurfacePresentModesKHR							(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes) const;
virtual VkResult	getPhysicalDevicePresentRectanglesKHR							(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pRectCount, VkRect2D* pRects) const;
virtual VkResult	getPhysicalDeviceDisplayPropertiesKHR							(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPropertiesKHR* pProperties) const;
virtual VkResult	getPhysicalDeviceDisplayPlanePropertiesKHR						(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPlanePropertiesKHR* pProperties) const;
virtual VkResult	getDisplayPlaneSupportedDisplaysKHR								(VkPhysicalDevice physicalDevice, uint32_t planeIndex, uint32_t* pDisplayCount, VkDisplayKHR* pDisplays) const;
virtual VkResult	getDisplayModePropertiesKHR										(VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModePropertiesKHR* pProperties) const;
virtual VkResult	createDisplayModeKHR											(VkPhysicalDevice physicalDevice, VkDisplayKHR display, const VkDisplayModeCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDisplayModeKHR* pMode) const;
virtual VkResult	getDisplayPlaneCapabilitiesKHR									(VkPhysicalDevice physicalDevice, VkDisplayModeKHR mode, uint32_t planeIndex, VkDisplayPlaneCapabilitiesKHR* pCapabilities) const;
virtual VkResult	createDisplayPlaneSurfaceKHR									(VkInstance instance, const VkDisplaySurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) const;
virtual VkResult	enumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR	(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, uint32_t* pCounterCount, VkPerformanceCounterKHR* pCounters, VkPerformanceCounterDescriptionKHR* pCounterDescriptions) const;
virtual void		getPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR			(VkPhysicalDevice physicalDevice, const VkQueryPoolPerformanceCreateInfoKHR* pPerformanceQueryCreateInfo, uint32_t* pNumPasses) const;
virtual VkResult	getPhysicalDeviceSurfaceCapabilities2KHR						(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkSurfaceCapabilities2KHR* pSurfaceCapabilities) const;
virtual VkResult	getPhysicalDeviceSurfaceFormats2KHR								(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pSurfaceFormatCount, VkSurfaceFormat2KHR* pSurfaceFormats) const;
virtual VkResult	getPhysicalDeviceDisplayProperties2KHR							(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayProperties2KHR* pProperties) const;
virtual VkResult	getPhysicalDeviceDisplayPlaneProperties2KHR						(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPlaneProperties2KHR* pProperties) const;
virtual VkResult	getDisplayModeProperties2KHR									(VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModeProperties2KHR* pProperties) const;
virtual VkResult	getDisplayPlaneCapabilities2KHR									(VkPhysicalDevice physicalDevice, const VkDisplayPlaneInfo2KHR* pDisplayPlaneInfo, VkDisplayPlaneCapabilities2KHR* pCapabilities) const;
virtual VkResult	getPhysicalDeviceFragmentShadingRatesKHR						(VkPhysicalDevice physicalDevice, uint32_t* pFragmentShadingRateCount, VkPhysicalDeviceFragmentShadingRateKHR* pFragmentShadingRates) const;
virtual VkResult	createDebugReportCallbackEXT									(VkInstance instance, const VkDebugReportCallbackCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugReportCallbackEXT* pCallback) const;
virtual void		destroyDebugReportCallbackEXT									(VkInstance instance, VkDebugReportCallbackEXT callback, const VkAllocationCallbacks* pAllocator) const;
virtual void		debugReportMessageEXT											(VkInstance instance, VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode, const char* pLayerPrefix, const char* pMessage) const;
virtual VkResult	getPhysicalDeviceExternalImageFormatPropertiesNV				(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkExternalMemoryHandleTypeFlagsNV externalHandleType, VkExternalImageFormatPropertiesNV* pExternalImageFormatProperties) const;
virtual VkResult	releaseDisplayEXT												(VkPhysicalDevice physicalDevice, VkDisplayKHR display) const;
virtual VkResult	getPhysicalDeviceSurfaceCapabilities2EXT						(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilities2EXT* pSurfaceCapabilities) const;
virtual VkResult	createDebugUtilsMessengerEXT									(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pMessenger) const;
virtual void		destroyDebugUtilsMessengerEXT									(VkInstance instance, VkDebugUtilsMessengerEXT messenger, const VkAllocationCallbacks* pAllocator) const;
virtual void		submitDebugUtilsMessageEXT										(VkInstance instance, VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageTypes, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData) const;
virtual void		getPhysicalDeviceMultisamplePropertiesEXT						(VkPhysicalDevice physicalDevice, VkSampleCountFlagBits samples, VkMultisamplePropertiesEXT* pMultisampleProperties) const;
virtual VkResult	getPhysicalDeviceCalibrateableTimeDomainsEXT					(VkPhysicalDevice physicalDevice, uint32_t* pTimeDomainCount, VkTimeDomainEXT* pTimeDomains) const;
virtual VkResult	getPhysicalDeviceToolPropertiesEXT								(VkPhysicalDevice physicalDevice, uint32_t* pToolCount, VkPhysicalDeviceToolPropertiesEXT* pToolProperties) const;
virtual VkResult	getPhysicalDeviceCooperativeMatrixPropertiesNV					(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkCooperativeMatrixPropertiesNV* pProperties) const;
virtual VkResult	getPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV	(VkPhysicalDevice physicalDevice, uint32_t* pCombinationCount, VkFramebufferMixedSamplesCombinationNV* pCombinations) const;
virtual VkResult	createHeadlessSurfaceEXT										(VkInstance instance, const VkHeadlessSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) const;
virtual VkResult	acquireDrmDisplayEXT											(VkPhysicalDevice physicalDevice, int32_t drmFd, VkDisplayKHR display) const;
virtual VkResult	getDrmDisplayEXT												(VkPhysicalDevice physicalDevice, int32_t drmFd, uint32_t connectorId, VkDisplayKHR* display) const;
virtual VkResult	acquireWinrtDisplayNV											(VkPhysicalDevice physicalDevice, VkDisplayKHR display) const;
virtual VkResult	getWinrtDisplayNV												(VkPhysicalDevice physicalDevice, uint32_t deviceRelativeId, VkDisplayKHR* pDisplay) const;
virtual VkResult	createAndroidSurfaceKHR											(VkInstance instance, const VkAndroidSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) const;
virtual VkResult	getPhysicalDeviceVideoCapabilitiesKHR							(VkPhysicalDevice physicalDevice, const VkVideoProfileKHR* pVideoProfile, VkVideoCapabilitiesKHR* pCapabilities) const;
virtual VkResult	getPhysicalDeviceVideoFormatPropertiesKHR						(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceVideoFormatInfoKHR* pVideoFormatInfo, uint32_t* pVideoFormatPropertyCount, VkVideoFormatPropertiesKHR* pVideoFormatProperties) const;
virtual VkResult	createImagePipeSurfaceFUCHSIA									(VkInstance instance, const VkImagePipeSurfaceCreateInfoFUCHSIA* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) const;
virtual VkResult	createStreamDescriptorSurfaceGGP								(VkInstance instance, const VkStreamDescriptorSurfaceCreateInfoGGP* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) const;
virtual VkResult	createIOSSurfaceMVK												(VkInstance instance, const VkIOSSurfaceCreateInfoMVK* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) const;
virtual VkResult	createMacOSSurfaceMVK											(VkInstance instance, const VkMacOSSurfaceCreateInfoMVK* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) const;
virtual VkResult	createMetalSurfaceEXT											(VkInstance instance, const VkMetalSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) const;
virtual VkResult	createViSurfaceNN												(VkInstance instance, const VkViSurfaceCreateInfoNN* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) const;
virtual VkResult	createWaylandSurfaceKHR											(VkInstance instance, const VkWaylandSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) const;
virtual VkBool32	getPhysicalDeviceWaylandPresentationSupportKHR					(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, pt::WaylandDisplayPtr display) const;
virtual VkResult	createWin32SurfaceKHR											(VkInstance instance, const VkWin32SurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) const;
virtual VkBool32	getPhysicalDeviceWin32PresentationSupportKHR					(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex) const;
virtual VkResult	getPhysicalDeviceSurfacePresentModes2EXT						(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes) const;
virtual VkResult	createXcbSurfaceKHR												(VkInstance instance, const VkXcbSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) const;
virtual VkBool32	getPhysicalDeviceXcbPresentationSupportKHR						(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, pt::XcbConnectionPtr connection, pt::XcbVisualid visual_id) const;
virtual VkResult	createXlibSurfaceKHR											(VkInstance instance, const VkXlibSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) const;
virtual VkBool32	getPhysicalDeviceXlibPresentationSupportKHR						(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, pt::XlibDisplayPtr dpy, pt::XlibVisualID visualID) const;
virtual VkResult	acquireXlibDisplayEXT											(VkPhysicalDevice physicalDevice, pt::XlibDisplayPtr dpy, VkDisplayKHR display) const;
virtual VkResult	getRandROutputDisplayEXT										(VkPhysicalDevice physicalDevice, pt::XlibDisplayPtr dpy, pt::RROutput rrOutput, VkDisplayKHR* pDisplay) const;
