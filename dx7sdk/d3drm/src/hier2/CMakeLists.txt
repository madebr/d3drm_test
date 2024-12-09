add_executable(hier2 WIN32
    hier2.cpp
    rmmain.cpp
    resource.h

    rmmain.rc
    hier2.def
    d3d.ico
)
target_link_libraries(hier2 PRIVATE d3drm ddraw)
