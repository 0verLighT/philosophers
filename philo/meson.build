project(
  'philosophers',
  'c',
  meson_version : '>= 1.3.0',
  version : '0.1',
  license: 'MIT',
  default_options : [
    'warning_level=3',
    'optimization=0'
  ]
)

host_os = host_machine.system()
cc = meson.get_compiler('c')

if host_os != 'windows'
  thread_dep = dependency('threads')
  if (thread_dep.found())
    if cc.has_header(
      'pthread.h',
      dependencies : thread_dep,
    )
    else
      error('pthread header not found')
    endif
  else
    error('thread dependency not found')
  endif
else
  error('This project depends on pthread.h and he cannot be compiled on Windows')
endif

inc = include_directories('includes')

sources = [
  'src/main.c',
  'src/utils.c',
  'src/parser.c',
  'src/ft_philo.c'
]

philosophers = executable(
  'philo',
  sources,
  dependencies : thread_dep,
  include_directories : inc,
  install : true,
)
