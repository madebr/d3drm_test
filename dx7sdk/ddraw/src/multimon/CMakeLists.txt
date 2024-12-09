add_executable(multimon WIN32
    multimon.cpp
    resource.h

    multimon.rc
    directx.ico
    image1.bmp
    image2.bmp
)
target_link_libraries(multimon PRIVATE ddraw dxguid)
