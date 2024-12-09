add_executable(simpleconnect WIN32
    dpconnect.cpp
    winmain.cpp

    winmain.rc
    resource.h
    directx.ico
)
target_link_libraries(simpleconnect PRIVATE dxguid)
