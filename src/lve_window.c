#include "lve_window.h"
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

int LveWindow_init(LveWindow *window, int w, int h, char *name) {
  glfwInit();
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  window->width = w;
  window->height = h;
  window->name = name;
  GLFWwindow *result = glfwCreateWindow(w, h, name, NULL, NULL);
  if (result == NULL) {
    printf("GLFW failed to init window.\n");
    exit(1);
  }
  window->glfwwindow = result;
  return 0;
}

void LveWindow_destroy(LveWindow *window) {
  glfwDestroyWindow(window->glfwwindow);
  glfwTerminate();
  free(window);
}
int LveWindow_shouldClose(LveWindow *window){
  return glfwWindowShouldClose(window->glfwwindow);
}
