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
    libtranslate
)
