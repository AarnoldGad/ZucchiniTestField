workspace "ZucchiniTest"
   architecture "x86_64"
   configurations { "Debug", "Release" }
   startproject "TestField"

   sysincludedirs {
      "ZucchiniEngine/ZEngine/include"
   }

   syslibdirs {
      "ZucchiniEngine/lib"
   }

   filter {"system:macosx or linux"}
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

include "ZucchiniEngine/ZEngine"
include "ZGraphics2D/ZGraphics2D/deps"
include "ZGraphics2D/ZGraphics2D"
include "TestField"
