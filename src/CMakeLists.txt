# Modify the location of executable outputs
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

# Target: main
add_executable(a2bf
    main.cc
)
target_compile_features(a2bf PUBLIC cxx_std_23)
