file(GLOB_RECURSE FILE_SRC      ${CMAKE_CURRENT_SOURCE_DIR}/aes/*.c ${CMAKE_CURRENT_SOURCE_DIR}/*.c)
add_definitions(
    -DRAND_PLATFORM_INDEPENDENT
)
# if(BOAT_PROTOCOL_USE_ETHEREUM OR BOAT_PROTOCOL_USE_PLATONE OR BOAT_PROTOCOL_USE_PLATON OR BOAT_PROTOCOL_USE_FISCOBCOS OR BOAT_PROTOCOL_USE_VENACHAIN OR BOAT_PROTOCOL_USE_QUORUM)
add_definitions(
    -DUSE_KECCAK=1
)
# endif()

if(BOAT_PROTOCOL_USE_HLFABRIC OR BOAT_PROTOCOL_USE_HWBCS OR BOAT_PROTOCOL_USE_CHAINMAKER)
add_definitions(
    -DUSE_SHA2=1
)
endif()
add_library(crypto_default_obj  OBJECT  ${FILE_SRC})
# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ed25519-donna)
target_include_directories(crypto_default_obj
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
)