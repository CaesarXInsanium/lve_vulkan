#include "lve_pipeline.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

int LvePipeline_init(LvePipeline *pipeline, char *vertFilePath,
                     char *fragFilePath) {
  LvePipeline_createGraphicsPipeline(vertFilePath, fragFilePath);
  printf("Pipeline pointer: %p\n", (void *)pipeline);
  pipeline->n=0;
  return 0;
}
void LvePipeline_destroy(LvePipeline *pipeline) { free(pipeline); }

Buffer LvePipeline_readFile(char *filepath) {
  FILE *file = fopen(filepath, "r");

  if (file == NULL) {
    printf("Could not open file: %s\n", filepath);
    printf("Errno: %d\n", errno);
    exit(1);
  }
  struct stat st;
  stat(filepath, &st);
  int filesize = st.st_size;

  char *buffer = (char *)malloc(filesize);

  fread(buffer, filesize, 1, file);
  fclose(file);

  Buffer buf;
  buf.buffer = buffer;
  buf.size = filesize;
  return buf;
}

int LvePipeline_createGraphicsPipeline(char *vertfilepath, char *fragfilepath) {

  Buffer vertcode = LvePipeline_readFile(vertfilepath);
  Buffer fragcode = LvePipeline_readFile(fragfilepath);

  printf("Vertex Shader size: %d\n", vertcode.size);
  printf("Frag Shader size: %d\n", fragcode.size);

  return 0;
}
