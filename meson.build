
project('VulkanEngine', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

GLSLC= find_program('glslc')

vertex = custom_target('vertex.spv',
  output: 'vertex.spv',
  input: 'shaders/simple_shader.vert',
  command: [GLSLC, '@input', '@output@'],
  install: false
  )
frag= custom_target('fragment.spv',
  output: 'fragment.spv',
  input: 'shaders/simple_frag.frag',
  command: [GLSLC, '@input', '@output@'],
  install: false
  )

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
