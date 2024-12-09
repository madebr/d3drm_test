add_library(d3dframe STATIC
    d3dapp.cpp
    d3denum.cpp
    d3dfile.cpp
    d3dframe.cpp
    d3dmath.cpp
    d3dtextr.cpp
    d3dutil.cpp
)
target_link_libraries(d3dframe PRIVATE d3dxof ddraw dxguid winmm)
