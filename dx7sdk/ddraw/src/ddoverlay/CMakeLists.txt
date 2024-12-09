add_executable(ddoverlay WIN32
    ddoverlay.cpp
    ddutil.cpp
    resource.h

    ddoverlay.rc
    ddoverlay.ico
    dx5.bmp
)
target_link_libraries(ddoverlay PRIVATE ddraw dxguid)
