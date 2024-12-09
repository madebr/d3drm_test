add_executable(mousenon WIN32
    mousenon.cpp
    mousenon.h
    winmain.cpp
    resource.h

    mousenon.rc
    directx.ico
)
target_link_libraries(mousenon PRIVATE dinput)
