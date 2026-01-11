project(
  'philosophers',
  'c',
  meson_version : '>= 1.3.0',
  version : '0.1',
  license: 'MIT',
  default_options : ['warning_level=3'],
)

inc = [include_directories('includes')]
sources = [
  'src/main.c',
]

philosophers = executable(
  'philo',
  sources,
  include_directories : inc,
  install : true,
)
