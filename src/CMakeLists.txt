# Modify the location of executable outputs
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

# Target: main
add_executable(a2bf
    main.cc

    models/alphabeta.cc
    models/board.cc
    models/cell.cc
    models/game.cc
    models/minimax.cc
)
target_compile_features(a2bf PUBLIC cxx_std_23)
target_include_directories(a2bf
    PUBLIC
        ${PROJECT_SOURCE_DIR}/src
)
