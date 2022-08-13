project "SerialPort"
	kind "StaticLib"
	language "C++"
    staticruntime "off"

	targetdir ("SerialPort/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("SerialPort/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"SerialPort/include/SerialPort.hpp",
		"SerialPort/src/SerialPort.cpp" 
	}

	includedirs
	{
		"SerialPort/include/"
	}

	links
	{
		
	}

	filter "system:windows"
		systemversion "latest"
		cppdialect "C++17"

	filter "system:linux"
		pic "On"
		systemversion "latest"
		cppdialect "C++17"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"

    filter "configurations:Dist"
		runtime "Release"
		optimize "on"
        symbols "off"
