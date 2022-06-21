#include "app.h"
#include "lve_window.h"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

int App_init(App *app, int w, int h, char *name) {
  LveWindow *window = (LveWindow *)malloc(sizeof(LveWindow));
  if (LveWindow_init(window, w, h, name) == -1) {
    return -1;
  }
  app->window = window;
  return 0;
}
void App_destroy(App *app) {
  LveWindow_destroy(app->window);
  free(app);
}
void App_run(App *app) {
  while (1 != LveWindow_shouldClose(app->window)) {
    glfwPollEvents();
  }
}
