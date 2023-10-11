cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ---- Project ----

project(
  TowerDefence
  VERSION 0.1.0
  LANGUAGES CXX
)

# ---- Options ----

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(
    FATAL_ERROR
      "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there."
  )
endif()

# ---- Dependencies ----

include(cmake/CPM.cmake)
CPMAddPackage("gh:nlohmann/json@3.11.2")
CPMAddPackage("gh:adsgames/asw@0.4.1")
CPMAddPackage("gh:skypjack/entt@3.12.2")

# ---- Source code ----

file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h)

# ---- Executable ----

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)

# ---- Libs ----

if(NOT EMSCRIPTEN)
  find_library(SDL_LIBRARY NAMES SDL2 REQUIRED)
  find_library(SDL_MIXER_LIBRARY NAMES SDL2_mixer REQUIRED)
  find_library(SDL_IMAGE_LIBRARY NAMES SDL2_image REQUIRED)
  find_library(SDL_TTF_LIBRARY NAMES SDL2_ttf REQUIRED)
  find_library(SDL_GFX_LIBRARY NAMES SDL2_gfx REQUIRED)
  find_library(SDL_MAIN_LIBRARY NAMES SDL2main REQUIRED)
endif(NOT EMSCRIPTEN)


# ---- Emscripten support ----

if(EMSCRIPTEN)
  set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "index")
  set(CMAKE_EXECUTABLE_SUFFIX ".html")
  target_compile_options(
    ${PROJECT_NAME}
    PRIVATE  
    -sUSE_SDL=2 
    -sUSE_SDL_IMAGE=2 
    -sUSE_SDL_TTF=2 
    -sUSE_SDL_MIXER=2 
    -sUSE_SDL_GFX=2 
    -sSDL2_IMAGE_FORMATS=["png"]
    -sSTACK_SIZE=128MB
  )
  target_link_libraries(
    ${PROJECT_NAME} 
    -sWASM=1 
    -sUSE_SDL=2 
    -sUSE_SDL_IMAGE=2 
    -sUSE_SDL_TTF=2 
    -sUSE_SDL_MIXER=2 
    -sUSE_SDL_GFX=2 
    -sSDL2_IMAGE_FORMATS=["png"] 
    -sDEMANGLE_SUPPORT=1
    -sTOTAL_MEMORY=512MB
    -sSTACK_SIZE=128MB
    nlohmann_json::nlohmann_json
    asw
    EnTT::EnTT
  )
  set_target_properties(
    ${PROJECT_NAME} 
    PROPERTIES 
    LINK_FLAGS
    "--preload-file ${CMAKE_CURRENT_LIST_DIR}/assets@/assets --use-preload-plugins --shell-file ${CMAKE_CURRENT_LIST_DIR}/index.html"
  )

# ---- Other ----

else(EMSCRIPTEN)
  if(MINGW)
    target_link_libraries(${PROJECT_NAME} -lmingw32)
  endif(MINGW)

  target_link_libraries(
    ${PROJECT_NAME}
    -lm 
    ${SDL_MAIN_LIBRARY}
    ${SDL_LIBRARY}
    ${SDL_MIXER_LIBRARY}
    ${SDL_IMAGE_LIBRARY}
    ${SDL_TTF_LIBRARY}
    ${SDL_GFX_LIBRARY}
    nlohmann_json::nlohmann_json
    asw
    EnTT::EnTT
  )
endif(EMSCRIPTEN)


# ---- Copy assets ----

file(COPY ${CMAKE_CURRENT_LIST_DIR}/assets/ DESTINATION ${CMAKE_BINARY_DIR}/assets/)

