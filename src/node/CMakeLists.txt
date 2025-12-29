qt_add_library(node STATIC
    node.h
    interface.h interface.cpp
)

target_link_libraries(node PRIVATE Qt6::Widgets)
target_include_directories(node INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})