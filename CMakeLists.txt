cmake_minimum_required(VERSION 3.5.1)
project(rnnoise)

add_library(rnnoise-obj OBJECT
    src/denoise.c
    src/rnn.c
    src/rnn_data.c
    src/models/cb.c
    src/models/mp.c
    src/models/bd.c
    src/models/lq.c
    src/models/sh.c
    src/rnn_reader.c
    src/models.c
    src/pitch.c
    src/kiss_fft.c
    src/celt_lpc.c
)
set_property(TARGET rnnoise-obj PROPERTY POSITION_INDEPENDENT_CODE 1)
target_include_directories(
  rnnoise-obj
  PRIVATE
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_SOURCE_DIR}/src
)
if (MSVC)
    add_definitions(/D_USE_MATH_DEFINES)
endif()

add_library(rnnoise-nu        SHARED $<TARGET_OBJECTS:rnnoise-obj>)
add_library(rnnoise-nu-static STATIC $<TARGET_OBJECTS:rnnoise-obj>)
set_target_properties(rnnoise-nu-static PROPERTIES OUTPUT_NAME rnnoise-nu)

install(TARGETS rnnoise-nu rnnoise-nu-static DESTINATION lib)
install(FILES include/rnnoise-nu.h DESTINATION include)
