add_library(booklib STATIC book.cpp)
target_include_directories(booklib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
