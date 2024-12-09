add_executable(tex5 WIN32
    tex5.cpp
    rmmain.cpp
    resource.h

    rmmain.rc
    tex5.def
    d3d.ico
)
target_link_libraries(tex5 PRIVATE d3drm ddraw)
