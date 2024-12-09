add_executable(ddenum WIN32
    ddenum.cpp
    resource.h

    ddenum.rc
    directx.ico
)
target_link_libraries(ddenum PRIVATE ddraw dxguid)
