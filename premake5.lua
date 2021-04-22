workspace "ZucchiniTest"
   architecture "x86_64"
   configurations { "Debug", "Release" }

include "TestField"
include "ZucchiniEngine/ZEngine"
include "ZGraphics2D/ZGraphics2D"
