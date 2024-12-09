add_executable(fffileread WIN32
    ffeedfileread.cpp
    winmain.cpp
    resource.h

    winmain.rc
    directx.ico
)
target_link_libraries(fffileread PRIVATE dinput)
