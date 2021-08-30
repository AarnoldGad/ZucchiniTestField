workspace "ZucchiniTest"
   architecture "x86_64"
   configurations { "Debug", "Release" }

   sysincludedirs {
      "ZucchiniEngine/ZEngine/include",
      "ZGraphics2D/ZGraphics2D/include"
   }

   syslibdirs {
      "ZucchiniEngine/ZEngine/lib",
      "ZGraphics2D/ZGraphics2D/lib"
   }

include "TestField"
include "ZucchiniEngine/ZEngine"
include "ZGraphics2D/ZGraphics2D/deps/glfw"
include "ZGraphics2D/ZGraphics2D"
