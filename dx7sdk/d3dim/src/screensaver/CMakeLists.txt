# Older MinGW has a non-functional scrnsave implementation
include(CheckSymbolExists)
include(CMakePushCheckState)
cmake_push_check_state()
list(APPEND CMAKE_REQUIRED_LIBRARIES "scrnsave")
check_symbol_exists(DefScreenSaverProc@16 "scrnsave.h" WORKING_SCRNSAVE)
cmake_pop_check_state()

if(WORKING_SCRNSAVE)
    add_library(screensaver SHARED
        screensaver.cpp
        screensaver.h
        render.cpp
        resource.h

        screensaver.rc
        directx.ico
    )
    target_link_libraries(screensaver PRIVATE d3dframe dxguid scrnsave)
    set_property(TARGET screensaver PROPERTY SUFFIX ".scr")
    set_property(TARGET screensaver PROPERTY PREFIX "")
endif()
