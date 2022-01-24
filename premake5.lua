workspace "Storm"
	configurations { "Debug", "Release", "Dist" }
	architecture "x64"
	startproject "Sandbox"

outputdir = "%{cfg.buildcfg}_%{cfg.system}_%{cfg.architecture}"

include "Storm/externals/GLFW"

project "Storm"
	location "Storm"
	kind "SharedLib"
	language "C++"
	cppdialect "C++17"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("build/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/externals/spdlog/include",
		"%{prj.name}/externals/GLFW/include"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	pchheader "Pch.h"
	pchsource "Storm/src/Pch.cpp"

	filter "system:windows"
		staticruntime "On"
		systemversion "latest"

		defines { "STORM_PLATFORM_WINDOWS", "STORM_BUILD_DLL" }

		postbuildcommands
		{
			"{COPYDIR} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"
		}

	filter "configurations:Debug"
		defines "STORM_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "STORM_RELEASE"
		runtime "Release"
		symbols "On"
		optimize "On"
	
	filter "configurations:Dist"
		defines "STORM_DIST"
		runtime "Release"
		optimize "Full"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("build/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Storm/externals/spdlog/include",
		"Storm/src"
	}

	links
	{
		"Storm"
	}

	filter "system:windows"
		staticruntime "On"
		systemversion "latest"

		defines { "STORM_PLATFORM_WINDOWS" }

	filter "configurations:Debug"
		defines "STORM_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "STORM_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "STORM_DIST"
		runtime "Release"
		symbols "Full"