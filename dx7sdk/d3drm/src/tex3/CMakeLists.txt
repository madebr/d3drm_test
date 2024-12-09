add_executable(tex3 WIN32
    tex3.cpp
    rmmain.cpp
    resource.h

    rmmain.rc
    tex3.def
    d3d.ico
)
target_link_libraries(tex3 PRIVATE d3drm ddraw)
