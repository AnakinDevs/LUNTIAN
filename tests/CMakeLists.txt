cmake_minimum_required(VERSION 3.16)
project(luntian_protocol_contract_test LANGUAGES CXX)

enable_testing()

add_executable(luntian_protocol_contract_test protocol_contract_test.cpp)
target_compile_features(luntian_protocol_contract_test PRIVATE cxx_std_17)

add_test(NAME luntian_protocol_contract_test COMMAND luntian_protocol_contract_test)
set_tests_properties(luntian_protocol_contract_test PROPERTIES
    WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/.."
)
