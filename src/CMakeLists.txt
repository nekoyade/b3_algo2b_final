# Modify the location of executable outputs
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

# Target: gomoku
add_executable(gomoku
    gomoku.cc

    models/alphabeta.cc
    models/board.cc
    models/cell.cc
    models/game.cc
)
target_compile_features(gomoku PUBLIC cxx_std_23)
target_include_directories(gomoku
    PUBLIC
        ${PROJECT_SOURCE_DIR}/src
)

# Target: perf_ab
add_executable(perf_ab
    perf_ab.cc

    interfaces/perf.cc

    models/alphabeta.cc
    models/board.cc
    models/cell.cc
    models/game.cc
    models/minimax.cc
)
target_compile_features(perf_ab PUBLIC cxx_std_23)
target_include_directories(perf_ab
    PUBLIC
        ${PROJECT_SOURCE_DIR}/src
)

# Target: perf
add_executable(perf
    perf.cc

    interfaces/perf.cc

    models/alphabeta.cc
    models/board.cc
    models/cell.cc
    models/game.cc
    models/minimax.cc
)
target_compile_features(perf PUBLIC cxx_std_23)
target_include_directories(perf
    PUBLIC
        ${PROJECT_SOURCE_DIR}/src
)

# Target: sanmoku
add_executable(sanmoku
    sanmoku.cc

    models/alphabeta.cc
    models/board.cc
    models/cell.cc
    models/game.cc
    models/minimax.cc
)
target_compile_features(sanmoku PUBLIC cxx_std_23)
target_include_directories(sanmoku
    PUBLIC
        ${PROJECT_SOURCE_DIR}/src
)
target_compile_options(sanmoku
    PUBLIC
        -DSANMOKU
)
