#pragma once
#include <vulkan/vulkan.h>

typedef struct LveVulkan {
  VkInstance instance;
} LveVulkan;

LveVulkan LveVulkan_new(char *name);
void LveVulkan_destroy(LveVulkan vulkan);
