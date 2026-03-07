add_library(shelflib STATIC shelf.cpp)
target_include_directories(shelflib PRIVATE ${CMAKE_SOURCE_DIR}/lab2)
target_link_libraries(shelflib booklib)

add_executable(lab3 main.cpp)
target_include_directories(lab3 PRIVATE ${CMAKE_SOURCE_DIR}/lab2 ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(lab3 shelflib booklib)
