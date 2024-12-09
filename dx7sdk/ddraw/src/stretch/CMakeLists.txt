add_executable(stretch WIN32
    stretch.cpp
    ddutil.cpp
    resource.h

    stretch.def
    stretch.rc
    directx.ico
    donut.bmp
)
target_link_libraries(stretch PRIVATE ddraw dxguid)
