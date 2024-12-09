add_executable(tex1 WIN32
    tex1.cpp
    rmmain.cpp
    resource.h

    rmmain.rc
    tex1.def
    d3d.ico
)
target_link_libraries(tex1 PRIVATE d3drm ddraw)
