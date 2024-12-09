add_executable(mfctex WIN32
    mfcform.cpp
    mfctex.cpp
    mfctex.h
    mtexture.cpp
    stdafx.cpp
    stdafx.h
    texargs.h
    resource.h

    winmain.rc
    directx.ico
)
target_link_libraries(mfctex PRIVATE d3dframe)
