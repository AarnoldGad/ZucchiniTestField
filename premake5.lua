workspace "ZucchiniTest"
   architecture "x86_64"
   configurations { "Debug", "Release" }

project "TestField"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++17"

   targetdir("%{prj.location}/bin/%{cfg.buildcfg}/%{prj.name}")
   objdir("%{prj.location}/bin/%{cfg.buildcfg}")

   files {
      "src/**.cpp",
      "include/**.hpp",
      "include/**.inl"
   }

   includedirs {
      "include",
      "%{wks.location}/deps/ZucchiniEngine/include",
      "%{wks.location}/deps/ZGraphics2D/include"
   }

   libdirs {
      "%{wks.location}/deps/ZucchiniEngine/lib",
      "%{wks.location}/deps/ZGraphics2D/lib"
   }

   filter "system:windows"
      systemversion "latest"

   filter "system:linux"
      includedirs {
         "/usr/include",
         "/usr/local/include"
      }
      libdirs {
         "/usr/lib",
         "/usr/local/lib"
      }
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

   filter "configurations:Debug"
      links {
         "zengine-d",
         "zgraphics2D-d"
      }
      runtime "Debug"
      symbols "On"

   filter "configurations:Release"
      links {
         "zengine",
         "zgraphics2D"
      }
      runtime "Release"
      optimize "On"
