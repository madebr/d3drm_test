add_executable(rmshadow WIN32
    rmshadow.cpp
    rmmain.cpp
    resource.h

    rmmain.rc
    d3d.ico
)
target_link_libraries(rmshadow PRIVATE d3drm ddraw)
