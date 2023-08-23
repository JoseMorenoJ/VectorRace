cmake_minimum_required(VERSION 3.0)

project(vector_race CXX)

add_executable(vector_race
    ${PROJECT_SOURCE_DIR}/vector_race/code/circuit.cpp
    ${PROJECT_SOURCE_DIR}/vector_race/code/graphics.cpp
    ${PROJECT_SOURCE_DIR}/vector_race/code/main.cpp
    ${PROJECT_SOURCE_DIR}/vector_race/code/player.cpp
    ${PROJECT_SOURCE_DIR}/vector_race/code/vector_race.cpp
    ${PROJECT_SOURCE_DIR}/vector_race/code/vector.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}/vector_race/resources
)

# Link PSP SDK libararies
target_link_libraries(${PROJECT_NAME} PRIVATE
    pspdebug
    pspdisplay
    pspge
    pspctrl
)

# Create an EBOOT.PBP file
create_pbp_file(
    TARGET ${PROJECT_NAME}
    ICON_PATH NULL
    BACKGROUND_PATH NULL
    PREVIEW_PATH NULL
    TITLE "Vector Race"
)
