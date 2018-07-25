
file(GLOB INCLUDE_SORTER "*.h" "*.cpp")

add_executable(include-sorter ${INCLUDE_SORTER})
target_include_directories(include-sorter PUBLIC ${OBJECT_BINARY_DIR})
target_link_libraries(include-sorter LLVM clangTooling clangFrontend clangLex clangBasic)
