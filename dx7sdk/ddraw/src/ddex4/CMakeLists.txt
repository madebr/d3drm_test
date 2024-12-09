add_executable(ddex4 WIN32
    ddex4.cpp
    ddutil.cpp
    resource.h

    ddex4.def
    ddex4.rc
    directx.ico
    all.bmp
)
target_link_libraries(ddex4 PRIVATE ddraw dxguid)
