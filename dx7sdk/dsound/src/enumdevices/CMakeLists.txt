add_executable(enumdevices WIN32
    winmain.cpp
    resource.h

    winmain.rc
    winmain.ico
)
target_link_libraries(enumdevices PRIVATE dsound)
