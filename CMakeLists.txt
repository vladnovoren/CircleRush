cmake_minimum_required(VERSION 3.0)
project(game)
find_package(X11 REQUIRED)
set(CMAKE_CONFIGURATION_TYPES "Debug" "Release")


set(FRAMEWORK_SRC
  src/Framework/Engine.cpp
  src/Framework/Game.cpp
)

set(GRAPHICS_SYSTEM_SRC
  src/GraphicsSystem/GraphicsSystem.cpp
  src/GraphicsSystem/Color.cpp
  src/MathUtils/CoordSystem.cpp
)

set(ECS_SRC
  src/Components/BaseComponent.cpp

  src/Components/GraphicsComponents/BaseGraphicsComponent.cpp
  src/Components/GraphicsComponents/CircleGraphicsComponent.cpp

  src/Entities/Entity.cpp

  src/Systems/PhysicalSystem.cpp
  src/Systems/World.cpp
  src/Systems/EntityManager.cpp
)

MACRO(HEADER_DIRECTORIES return_list)
    FILE(GLOB_RECURSE new_list *.hpp *.h)
    SET(dir_list "")
    FOREACH(file_path ${new_list})
        GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
        SET(dir_list ${dir_list} ${dir_path})
    ENDFOREACH()
    LIST(REMOVE_DUPLICATES dir_list)
    SET(${return_list} ${dir_list})
ENDMACRO()


HEADER_DIRECTORIES(header_dir_list)
list(LENGTH header_dir_list header_dir_list_count)
include_directories(${header_dir_list})

add_library(GraphicsSystem STATIC ${GRAPHICS_SYSTEM_SRC})
add_library(ECS STATIC ${ECS_SRC})

add_executable(game ${FRAMEWORK_SRC})


target_link_libraries(GraphicsSystem X11)
target_link_libraries(ECS GraphicsSystem)
target_link_libraries(game ECS)