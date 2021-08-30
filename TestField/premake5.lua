project "TestField"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++17"

   targetdir("%{prj.location}/bin/%{cfg.buildcfg}")
   objdir("%{prj.location}/bin/%{cfg.buildcfg}/out")

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
      "glfw3"
   }

   filter "system:windows"
      staticruntime "on"
      systemversion "latest"

   filter "system:linux"
      sysincludedirs {
         "/usr/include",
         "/usr/local/include"
      }
      syslibdirs {
         "/usr/lib",
         "/usr/local/lib"
      }
      links {
         "dl",
         "pthread"
      }

   filter "system:macosx"
     buildoptions {
         "-Wall", "-Wextra", "-Wold-style-cast", "-Woverloaded-virtual", "-Wfloat-equal", "-Wwrite-strings",
         "-Wpointer-arith", "-Wcast-qual", "-Wcast-align", "-Wconversion", "-Wshadow", "-Wredundant-decls",
         "-Wdouble-promotion", "-Winit-self", "-Wswitch-default", "-Wswitch-enum", "-Wundef", "-Winline",
         "-m64", "-fexceptions", "-pedantic"
      }
      linkoptions {
         "-m64"
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

   filter "configurations:Debug"
      links {
         "zengine-d",
         "zgraphics2D-d"
      }
      defines "_DEBUG"
      runtime "Debug"
      symbols "On"

   filter "configurations:Release"
      links {
         "zengine",
         "zgraphics2D"
      }
      defines "NDEBUG"
      runtime "Release"
      optimize "On"
