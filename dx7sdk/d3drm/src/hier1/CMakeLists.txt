add_executable(hier1 WIN32
    hier1.cpp
    rmmain.cpp
    resource.h

    rmmain.rc
    hier1.def
    d3d.ico
)
target_link_libraries(hier1 PRIVATE d3drm ddraw)
