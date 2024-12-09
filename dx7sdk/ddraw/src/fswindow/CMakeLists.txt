add_executable(fswindow WIN32
    fswindow.cpp
    fswindow.h
    winmain.cpp
    resource.h

    fswindow.rc
    directx.ico
)
target_link_libraries(fswindow PRIVATE ddraw dxguid winmm)
