add_executable(ddex1 WIN32
    ddex1.cpp
    resource.h

    ddex1.def
    ddex1.rc
    directx.ico
)
target_link_libraries(ddex1 PRIVATE ddraw dxguid)
