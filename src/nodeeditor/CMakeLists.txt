qt_add_library(nodeeditor STATIC
    nodeeditor.h nodeeditor.cpp
    nodeeditor_scene.h nodeeditor_scene.cpp
    node_graphicsitem.h node_graphicsitem.cpp
)

target_link_libraries(nodeeditor PRIVATE Qt6::Widgets)
target_include_directories(nodeeditor INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})