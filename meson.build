
project('VulkanEngine', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

SOURCES = [
  'src/main.c',
  'src/lve_window.c',
  'src/app.c',
  'src/lve_pipeline.c',
  'src/lve_device.c',
  'src/lve_vulkan.c'
  ]

DEPS = [
             dependency('cglm'),
             dependency('glfw3'),
             dependency('vulkan'),
             ]
INCLUDE = include_directories('include')

build_args = [
  '-Wall',
  '-Werror',
  '-g3',
  '-pedantic',
  ]

executable('result',
          SOURCES,
           install : true,
           include_directories: INCLUDE,
           dependencies :DEPS ,
           c_args: build_args,
           )
