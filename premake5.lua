-- premake5.lua
workspace "FuelMonitor"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "FuelMonitor"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
include "Walnut/WalnutExternal.lua"

include "FuelMonitorExternal.lua"
include "FuelMonitor"