project('Hollow Pulse', 'c')

src = [
    'src/main.c',
]

incdir = include_directories('include')

raylib_dep = dependency('raylib', required: true)

executable(
    'hollow-pulse',
    sources: src,
    include_directories: incdir,
    dependencies: raylib_dep
)
