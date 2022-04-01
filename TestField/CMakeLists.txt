ADD_EXECUTABLE(testfield)

SET_TARGET_PROPERTIES(testfield PROPERTIES
                      OUTPUT_NAME TestField
                      CXX_STANDARD 17
                      CXX_STANDARD_REQUIRED ON
                      CXX_EXTENSIONS OFF
                      FOLDER "TestField"
                      )

TARGET_SOURCES(testfield PRIVATE
               include/TestField.hpp
               include/TestLayer.hpp
               )

TARGET_SOURCES(testfield PRIVATE
               src/main.cpp
               src/TestField.cpp
               src/TestLayer.cpp
               )

TARGET_COMPILE_DEFINITIONS(testfield PRIVATE
                           $<$<CONFIG:Debug>:_DEBUG>
                           $<$<CONFIG:Release>:NDEBUG>
                           )

TARGET_INCLUDE_DIRECTORIES(testfield PUBLIC
                           "${PROJECT_SOURCE_DIR}/TestField/include"
                           "${PROJECT_BINARY_DIR}"
                           )

TARGET_INCLUDE_DIRECTORIES(testfield SYSTEM PRIVATE
                           "${PROJECT_SOURCE_DIR}/ZGraphics2D/ZGraphics2D/deps/glad/include"
                           $<$<PLATFORM_ID:Linux,Darwin>:/usr/include>
                           $<$<PLATFORM_ID:Linux,Darwin>:/usr/local/include>
                           )

TARGET_LINK_DIRECTORIES(testfield PRIVATE
                        $<$<PLATFORM_ID:Linux,Darwin>:/usr/lib>
                        $<$<PLATFORM_ID:Linux,Darwin>:/usr/local/lib>
                        )

TARGET_LINK_LIBRARIES(testfield PRIVATE
                      zengine
                      zgraphics
                      Threads::Threads
                      ${CMAKE_DL_LIBS}
                      )

