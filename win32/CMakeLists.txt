function(add_win32_implib TARGET DEF)
    if(MSVC)
        set(imp "${CMAKE_CURRENT_BINARY_DIR}/${TARGET}.lib")
        set(exp "${CMAKE_CURRENT_BINARY_DIR}/${TARGET}.exp")
        add_custom_command(OUTPUT "${imp}" "${exp}"
            COMMAND "${CMAKE_AR}" "${CMAKE_STATIC_LINKER_FLAGS}" "/NOLOGO" "/DEF:${DEF}" "/OUT:${IMP}"
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
            DEPENDS "${DEF}"
        )
    elseif(MINGW)
        set(imp "${CMAKE_CURRENT_BINARY_DIR}/libsmackw32.dll.a")
        add_custom_command(
            OUTPUT "${imp}"
            COMMAND "${CMAKE_DLLTOOL}" ${CMAKE_STATIC_LINKER_FLAGS} --input-def "${DEF}" --output-lib "${imp}"
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
            DEPENDS "${DEF}"
        )
    else()
        message(FATAL_ERROR "Unsupported toolchain")
    endif()
    add_custom_target(${TARGET}-implib DEPENDS "${IMP}")
    target_sources(${TARGET}-implib PRIVATE "${DEF}")
    add_library(${TARGET} INTERFACE)
    target_link_libraries(${TARGET} INTERFACE "${IMP}")
    target_include_directories(${TARGET} SYSTEM INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")
    add_dependencies(${TARGET} "${TARGET}-implib")
endfunction()

add_win32_implib(d3drm "${CMAKE_CURRENT_SOURCE_DIR}/d3drm.def")
add_win32_implib(d3dxof "${CMAKE_CURRENT_SOURCE_DIR}/d3dxof.def")
