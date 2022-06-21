#pragma once
#include <GLFW/glfw3.h>
#include <string.h>
#define GLFW_INCLUDE_VULKAN

typedef struct LveWindow {
  GLFWwindow *glfwwindow;
  char *name;
  int width;
  int height;
} LveWindow;

int LveWindow_init(LveWindow *window, int w, int h, char *name);
void LveWindow_destroy(LveWindow *window);
int LveWindow_shouldClose(LveWindow *window);
