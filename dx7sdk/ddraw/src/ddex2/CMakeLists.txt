add_executable(ddex2 WIN32
    ddex2.cpp
    ddutil.cpp
    resource.h

    ddex2.def
    ddex2.rc
    directx.ico
    back.bmp
)
target_link_libraries(ddex2 PRIVATE ddraw dxguid)
