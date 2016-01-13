INCLUDE_DIRECTORIES(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
INCLUDE_DIRECTORIES(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

INCLUDE_DIRECTORIES(../src)

MACRO(TESTCASE casename)
  ADD_EXECUTABLE( ${casename} ${ARGN} )
  # Link test executable against gtest & gtest_main
  TARGET_LINK_LIBRARIES(${casename} gtest gtest_main gmock)
  ADD_TEST( ${casename} ${casename} )
ENDMACRO(TESTCASE)

TESTCASE(
  cell
  cellTest
  ../src/Cell.cpp
  )
