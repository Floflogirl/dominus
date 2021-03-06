# BUILD STATIC LIB FOR ARDUINO
libarduino_fix_flags()
include_directories (${COMMON_SRC_DIR})

set(
  LIB_ARDUINO_TCHAT_SRC
  ${TCHAT_SRC_DIR}/TchatMsg.cpp
  ${TCHAT_SRC_DIR}/TchatBuffer.cpp
  ${TCHAT_SRC_DIR}/TchatMsgLed.cpp
  ${LIBCORE_SRC_FILES}
)
add_library (
  arduino_tchat 
  ${LIB_ARDUINO_TCHAT_SRC}
)

# BUILD BINARY
set(SRC tchat)
binarduino_build_cmd_cpp(
  ${SRC} 
  CMD_BUILD_D 
  CMD_BUILD_O 
  CMD_BUILD_ELF 
  CMD_BUILD_HEX
)

add_custom_target(
    ${SRC}
    ALL
    COMMAND ${CMD_BUILD_D}
    COMMAND ${CMD_BUILD_O} -I${COMMON_SRC_DIR} -I.
    COMMAND ${CMD_BUILD_ELF} ${CMAKE_CURRENT_BINARY_DIR}/libarduino_tchat.a
    COMMAND ${CMD_BUILD_HEX}
)