project('Hollow Pulse', 'c', version: '0.0.1')

src = [
    'src/main.c',
]

incdir = include_directories('include')

cc = meson.get_compiler('c')

raylib_dep = dependency('raylib', required: true)
math_dep   = cc.find_library('m', required: true)

executable(
    'hollow-pulse',
    sources: src,
    include_directories: incdir,
    dependencies: [raylib_dep, math_dep]
)
