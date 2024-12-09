add_executable(uvis WIN32
    uvis.cpp
    d3dmacs.h
    rmmain.cpp
    resource.h

    rmmain.rc
    uvis.def
    d3d.ico
)
target_link_libraries(uvis PRIVATE d3drm ddraw)
