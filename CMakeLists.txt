cmake_minimum_required(VERSION 3.16)

project(Winicon)

add_executable(
    ${PROJECT_NAME}
    WIN32
    main_win.cpp
    appicon.rc
)

#if (MSVC)
#    # Tell MSVC to use main instead of WinMain for Windows subsystem executables
#    set_target_properties(${PROJECT_NAME} PROPERTIES
#                          LINK_FLAGS "/ENTRY:mainCRTStartup")
#endif()
