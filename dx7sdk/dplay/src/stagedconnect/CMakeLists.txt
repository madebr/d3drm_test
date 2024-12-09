add_executable(stagedconnect WIN32
    dpconnect.cpp
    dpstage.cpp
    winmain.cpp
    resource.h

    winmain.rc
    directx.ico
)
target_link_libraries(stagedconnect PRIVATE dxguid)
