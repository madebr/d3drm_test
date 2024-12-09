add_executable(bellhop WIN32
    bellhop.cpp
    bellhop.h
    cgrptree.cpp
    cgrptree.h
    connset.cpp
    dialog.cpp
    resource.h

    bellhop.ico
    bellhop.rc
    bitmap1.bmp
    dpldplay.reg
)
target_link_libraries(bellhop PRIVATE comctl32 dplayx)
