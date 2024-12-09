add_executable(font WIN32
    font.cpp
    resource.h

    font.def
    font.rc
    directx.ico
)
target_link_libraries(font PRIVATE ddraw dxguid)
