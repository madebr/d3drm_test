add_executable(mouseexc WIN32
    mouseexc.cpp
    mouseexc.h
    winmain.cpp
    resource.h

    mouseexc.rc
    directx.ico
)
target_link_libraries(mouseexc PRIVATE dinput)
