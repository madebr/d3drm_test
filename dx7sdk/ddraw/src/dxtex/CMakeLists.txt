add_executable(dxtex WIN32
    childfrm.cpp
    childfrm.h
    dxtex.cpp
    dxtex.h
    dxtexdoc.cpp
    dxtexdoc.h
    dxtexview.cpp
    dxtexview.h
    mainfrm.cpp
    mainfrm.h
    resource.h
    stdafx.cpp
    stdafx.h

    dxtex.rc
    dxtex.ico
    dxtexdoc.ico
    toolbar.bmp
)
target_link_libraries(dxtex PRIVATE ddraw dxguid)
