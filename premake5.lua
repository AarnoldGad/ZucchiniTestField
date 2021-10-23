workspace "ZucchiniTest"
   architecture "x86_64"
   configurations { "Debug", "Release" }
   startproject "ZEngine"

   sysincludedirs {
      "ZucchiniEngine/ZEngineAPI/include",
      "ZGraphics2D/ZGraphics2D/include"
   }

   syslibdirs {
      "ZucchiniEngine/lib",
      "ZGraphics2D/lib"
   }

   filter {"system:linux or macosx"}
      sysincludedirs {
         "/usr/include",
         "/usr/local/include"
      }
      syslibdirs {
         "/usr/lib",
         "/usr/local/lib"
      }

   filter "configurations:Debug"
      defines "_DEBUG"
      runtime "Debug"
      symbols "on"

   filter "configurations:Release"
      defines "NDEBUG"
      runtime "Release"
      optimize "on"

include "ZucchiniEngine/ZEngineAPI"
include "ZucchiniEngine/ZEngine"
include "ZGraphics2D/ZGraphics2D/deps/glfw"
include "ZGraphics2D/ZGraphics2D"
include "TestField"
