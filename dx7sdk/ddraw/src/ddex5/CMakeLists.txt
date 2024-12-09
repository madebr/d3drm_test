add_executable(ddex5 WIN32
    ddex5.cpp
    ddutil.cpp
    resource.h

    ddex5.def
    ddex5.rc
    directx.ico
    all.bmp
)
target_link_libraries(ddex5 PRIVATE ddraw dxguid)
