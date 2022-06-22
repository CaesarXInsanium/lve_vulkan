#include "app.h"
#include "lve_pipeline.h"
#include "lve_vulkan.h"
#include "lve_window.h"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

int App_init(App *app, int w, int h, char *name) {

  LveWindow *window = (LveWindow *)malloc(sizeof(LveWindow));
  if (LveWindow_init(window, w, h, name) == -1) {
    return -1;
  }

  LveVulkan vulkan = LveVulkan_new("Vulkan Instance");

  LvePipeline *pipeline = (LvePipeline *)malloc(sizeof(LvePipeline));

  if (LvePipeline_init(
          pipeline,
          "/EXTRA/RootProjects/C/lve_vulkan/shaders/simple_shader.vert.spv",
          "/EXTRA/RootProjects/C/lve_vulkan/shaders/simple_frag.frag.spv") ==
      -1) {
    return -1;
  }

  app->window = window;
  app->vulkan = vulkan;
  app->pipeline = pipeline;
  return 0;
}
void App_destroy(App *app) {
  LveWindow_destroy(app->window);
  LvePipeline_destroy(app->pipeline);
  LveVulkan_destroy(app->vulkan);
  free(app);
}
void App_run(App *app) {
  while (1 != LveWindow_shouldClose(app->window)) {
    glfwPollEvents();
  }
}
