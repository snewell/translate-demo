cmake_minimum_required(VERSION 3.9)
cmake_policy(VERSION 3.9)

project("translate-demo"
    LANGUAGES
        CXX
    VERSION
        0.1.0
)

include(GNUInstallDirs)

add_library(libtranslate INTERFACE)
target_compile_features(libtranslate INTERFACE
    cxx_std_17
)
target_include_directories(libtranslate INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

add_executable(translate
    translate.cpp
)
target_link_libraries(translate
    PRIVATE libtranslate
)
target_compile_definitions(translate
    PRIVATE "-DUSE_SPLIT=0"
)

add_executable(translate_split
    translate.cpp
)
target_link_libraries(translate_split
    PRIVATE libtranslate
)
target_compile_definitions(translate_split
    PRIVATE "-DUSE_SPLIT=1"
)

add_executable(translate_interfaces
    translate_interfaces.cpp
)
target_link_libraries(translate_interfaces
    PRIVATE libtranslate
)

add_executable(translate_algo
    translate_algo.cpp
)
target_link_libraries(translate_algo
    PRIVATE libtranslate
)

add_executable(translate_algo_reuse
    translate_algo_reuse.cpp
)
target_link_libraries(translate_algo_reuse
    PRIVATE libtranslate
)
