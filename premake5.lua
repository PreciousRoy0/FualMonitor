-- premake5.lua
workspace "FualMonitor"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "FualMonitor"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
include "Walnut/WalnutExternal.lua"

include "FualMonitor"