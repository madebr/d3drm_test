add_executable(scrawl WIN32
    scrawl.cpp
    scrawl.h
    winmain.cpp
    resource.h

    scrawl.rc
    directx.ico
)
target_link_libraries(scrawl PRIVATE dinput)
