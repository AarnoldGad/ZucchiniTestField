workspace "ZucchiniTest"
   architecture "x86_64"
   configurations { "Debug", "Release" }
   
   includedirs {
      "ZucchiniEngine/ZEngine/include",
      "ZGraphics2D/ZGraphics2D/include"
   }
   
   libdirs {
      "ZucchiniEngine/ZEngine/lib",
      "ZGraphics2D/ZGraphics2D/lib"
   }

include "TestField"
include "ZucchiniEngine/ZEngine"
include "ZGraphics2D/ZGraphics2D"
