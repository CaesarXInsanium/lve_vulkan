#ifndef APP_H
#define APP_H
#include "lve_window.h"
#include "lve_pipeline.h"
#include "lve_vulkan.h"

typedef struct App{
  LveWindow *window;
  LvePipeline *pipeline;
  LveVulkan vulkan;
} App;

int App_init(App *app,int w, int h, char *name);
void App_destroy(App *app);
void App_run(App *app);

#endif
