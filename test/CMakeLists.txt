cmake_minimum_required(VERSION 3.10.0)

include(CTest)
enable_testing()

set(ldap-escape_TEST_SOURCES
  ldap/escape_test.cpp
)

add_executable(ldap-escape-test
  test_runner.cpp
  ${ldap-escape_TEST_SOURCES}
)

target_link_libraries(ldap-escape-test
  PUBLIC
    ldap-escape
    CONAN_PKG::gtest
)

include(GoogleTest)

gtest_discover_tests(ldap-escape-test
  TEST_PREFIX "ldap-escape-test."
  WORKING_DIRECTORY "$<TARGET_FILE_DIR:ldap-escape-test>"
)
