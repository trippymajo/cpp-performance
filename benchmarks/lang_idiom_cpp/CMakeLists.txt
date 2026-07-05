add_executable(lang_idiom_cpp
    prefix_op.cpp
)

target_link_libraries(lang_idiom_cpp
    PRIVATE
        benchmark::benchmark_main
)
