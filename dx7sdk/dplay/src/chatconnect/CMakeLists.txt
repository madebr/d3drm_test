add_executable(chatconnect WIN32
    dpconnect.cpp
    winmain.cpp
    resource.h

    winmain.rc
    directx.ico
)
target_link_libraries(chatconnect PRIVATE dxguid)
