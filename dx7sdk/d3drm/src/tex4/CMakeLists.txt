add_executable(tex4 WIN32
    tex4.cpp
    rmmain.cpp
    resource.h

    rmmain.rc
    tex4.def
    d3d.ico
)
target_link_libraries(tex4 PRIVATE d3drm ddraw)
