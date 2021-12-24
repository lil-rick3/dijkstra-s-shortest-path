compiler_args = []
linker_args = []

sources = files(
    'main.cpp', 
    'filestuff.cpp',
    'makemap.cpp',
    'node.cpp')

includes = [include_directories('.')]

exe = executable(
        'dijkstra',
        include_directories: [includes],
        sources: [sources],
        cpp_args: [compiler_args],
        c_args: [compiler_args],
        link_args: [linker_args],
    )
