project "TestField"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++20"
   staticruntime "off"

   targetdir("%{prj.location}/bin")
   objdir("%{prj.location}/obj/%{cfg.buildcfg}")

   files {
      "src/**.cpp",
      "include/**.hpp",
      "include/**.inl"
   }

   includedirs {
      "include"
   }

   sysincludedirs {
      "../ZGraphics2D/ZGraphics2D/deps/glad/include",
      "../ZGraphics2D/ZGraphics2D/deps/glfw/glfw/include",
      "../ZGraphics2D/ZGraphics2D/deps/glm",
      "../ZGraphics2D/ZGraphics2D/deps/stb/include"
   }

   links {
      "ZEngine",
      "glfw3",
      "ZGraphics2D"
   }

   filter "system:windows"
      systemversion "latest"

   filter {"system:linux"}
      links {
         "dl",
         "pthread"
      }

   filter { "action:gmake*", "toolset:gcc" }
      buildoptions {
         "-Wall", "-Wextra", "-Wold-style-cast", "-Woverloaded-virtual", "-Wfloat-equal", "-Wwrite-strings",
         "-Wpointer-arith", "-Wcast-qual", "-Wcast-align", "-Wconversion", "-Wshadow", "-Wredundant-decls",
         "-Wdouble-promotion", "-Winit-self", "-Wswitch-default", "-Wswitch-enum", "-Wundef", "-Wlogical-op", "-Winline",
         "-m64", "-fexceptions", "-pedantic"
      }
      linkoptions {
         "-m64"
      }
