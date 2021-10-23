project "TestField"
   kind "SharedLib"
   language "C++"
   cppdialect "C++20"
   staticruntime "off"

   targetname("testfield")

   filter "configurations:Debug"
      targetsuffix "-d"
   filter {}

   targetdir("%{prj.location}/bin")
   objdir("%{prj.location}/bin/obj/%{cfg.buildcfg}")

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
      "ZEngineAPI"
      "glfw3"
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
