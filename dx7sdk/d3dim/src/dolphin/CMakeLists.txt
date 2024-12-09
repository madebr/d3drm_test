add_executable(dolphin WIN32
    dolphin.cpp
    resource.h

    winmain.rc
    resource.h
)
target_link_libraries(dolphin PRIVATE d3dframe)
