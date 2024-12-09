add_executable(joystimm WIN32
    joystimm.cpp
    winmain.cpp
    resource.h

    joystimm.rc
    directx.ico
)
target_link_libraries(joystimm PRIVATE dinput)
