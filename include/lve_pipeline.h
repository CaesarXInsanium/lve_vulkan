#pragma once

typedef struct Buffer{
  char *buffer;
  int size;
} Buffer;

typedef struct LvePipeline{
  int n;

} LvePipeline;

int LvePipeline_init(LvePipeline *pipeline, char *vertFilePath, char *fragFilePath);

void LvePipeline_destroy(LvePipeline *pipeline);

Buffer LvePipeline_readFile(char *filepath);

int LvePipeline_createGraphicsPipeline(char *vertfilepath, char *fragfilepath);
