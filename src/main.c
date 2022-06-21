#include "app.h"
#include <string.h>
#include <stdlib.h>

int main(void){
  App *app = (App *)malloc(sizeof(App));
  App_init(app, 800, 600, "Window");
  App_run(app);
  App_destroy(app);
  return 0;
}
