/* WARNING: This is auto-generated file. Do not modify, since changes will
 * be lost! Modify the generating script instead.
 */
virtual VkResult			createInstance							(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance) const = 0;
virtual PFN_vkVoidFunction	getInstanceProcAddr						(VkInstance instance, const char* pName) const = 0;
virtual VkResult			enumerateInstanceExtensionProperties	(const char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties) const = 0;
virtual VkResult			enumerateInstanceLayerProperties		(uint32_t* pPropertyCount, VkLayerProperties* pProperties) const = 0;
virtual VkResult			enumerateInstanceVersion				(uint32_t* pApiVersion) const = 0;
