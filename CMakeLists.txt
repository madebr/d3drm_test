cmake_minimum_required(VERSION 3.27)
project(d3drm_test C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin" CACHE PATH "Where to build binaries")

option(ENABLE_ALL_WARNINGS "Enable all warnings" OFF)
if(ENABLE_ALL_WARNINGS)
    if(MSVC)
        add_comile_options(-w3)
    else()
        add_compile_options(-Wall -Wextra)
    endif()
endif()

option(USE_DX7SDK "Use DirectX7 SDK" ON)
if(USE_DX7SDK)
    include_directories(3rdparty/dx7sdk/include)
    add_subdirectory(3rdparty/dx7sdk)
endif()

if(MSVC)
    add_subdirectory(implibs)
endif()

#add_subdirectory(scorpioncity)
add_subdirectory(dx7sdk)
