### This file is automatically generated by Qt Design Studio.
### Do not change

qt_add_library(content STATIC)

# Glob all ttf files
file(GLOB_RECURSE fonts_ttf RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} fonts/*.ttf)

qt6_add_qml_module(content
    URI "content"
    VERSION 1.0
    QML_FILES


    RESOURCES
        fonts/fonts.txt
        RESOURCES
            ${fonts_ttf}
)