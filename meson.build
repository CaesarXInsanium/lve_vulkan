
project('VulkanEngine', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

build_args = [
  '-Wall',
  '-Werror',
  '-g3',
  '-pedantic'
  ]
SOURCES = [
  'src/main.c',
  'src/lve_window.c',
  'src/app.c',
  'src/lve_pipeline.c'
  ]

CGLM = dependency('cglm')
GLFW = dependency('glfw3')

INCLUDE = include_directories('include')

build_args = [
  '-Wall',
  '-Werror',
  '-g3',
  '-pedantic'
  ]

executable('result',
          SOURCES,
           install : true,
           include_directories: INCLUDE,
           dependencies : [
             GLFW,
             CGLM
             ],
           c_args: build_args,
           )
