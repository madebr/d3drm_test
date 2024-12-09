add_executable(ddex3 WIN32
    ddex3.cpp
    ddutil.cpp
    resource.h

    ddex3.def
    ddex3.rc
    directx.ico
    frntback.bmp
)
target_link_libraries(ddex3 PRIVATE ddraw dxguid)
