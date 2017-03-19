project(tests)


set(tests reflection_basic_test)
find_package(GTest REQUIRED)
link_libraries(${GTEST_BOTH_LIBRARIES} pthread)
message(${GTEST_BOTH_LIBRARIES})

foreach(test ${tests})
    add_executable(${test} ${test}.cc)
    add_test(NAME ${test} COMMAND ${test})
endforeach()



