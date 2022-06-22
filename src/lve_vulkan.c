#include "lve_vulkan.h"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vulkan/vulkan_core.h>

LveVulkan LveVulkan_new(char *name) {
  LveVulkan vulkan;

  VkApplicationInfo vkinfo;
  vkinfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  vkinfo.pApplicationName = name;
  vkinfo.applicationVersion = VK_MAKE_API_VERSION(0, 0, 0, 1);
  vkinfo.pEngineName = "No Engine";
  vkinfo.engineVersion = VK_MAKE_API_VERSION(0, 0, 0, 1);
  vkinfo.apiVersion = VK_API_VERSION_1_3;

  VkInstanceCreateInfo createinfo;
  createinfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  createinfo.pApplicationInfo = &vkinfo;

  unsigned int glfw_extension_count = 0;
  const char **glfw_extensions;
  glfw_extensions = glfwGetRequiredInstanceExtensions(&glfw_extension_count);

  createinfo.enabledExtensionCount = glfw_extension_count;
  createinfo.ppEnabledExtensionNames = glfw_extensions;
  createinfo.enabledLayerCount = glfw_extension_count;

  VkInstance instance = NULL;

  // const char *validationLayers = {
  //     "VK_LAYER_KHRONOS_validation",
  // };
  VkResult result = vkCreateInstance(&createinfo, NULL, &instance);
  if (result != VK_SUCCESS) {
    printf("Could not Create Instance\n");
    exit(1);
  }

  unsigned int extension_count = 0;
  vkEnumerateInstanceExtensionProperties(NULL, &extension_count, NULL);
  VkExtensionProperties *extensions =
      (VkExtensionProperties *)malloc(sizeof(extension_count));
  vkEnumerateInstanceExtensionProperties(NULL, &extension_count, extensions);

  printf("Available Extensions: \n");
  for (int i = 0; i < (int)extension_count; i++) {
    printf("Name:\t%s\n", extensions[i].extensionName);
  }
  vulkan.instance = instance;
  return vulkan;
}

void LveVulkan_destroy(LveVulkan vulkan) {
  vkDestroyInstance(vulkan.instance, NULL);
}
