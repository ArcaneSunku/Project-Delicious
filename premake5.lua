workspace "project_delicious"
	filename "project_delicious"
	architecture "x64"
	configurations { "Debug", "Release" }
	
	OUTPUT_DIR = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	
	startproject "delicious"

project "delicious"
	location "delicious"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	staticruntime "on"
	
	buildoptions{"/utf-8"}
	
	targetdir("bin/" .. OUTPUT_DIR .. "/%{prj.name}")
	objdir("bin-int/" .. OUTPUT_DIR .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.c",
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.h"
	}
	
	includedirs {
		"delicious/vendors/raylib/include",
		"delicious/vendors/raygui/src"
	}
	
	links {
		"delicious/vendors/raylib/lib/raylibdll.lib"
	}

	--postbuildcommands {
	--  "{COPYDIR} \"../%{prj.name}/assets\" %[%{!cfg.targetdir}/assets]"
	--}
	
	filter "system:windows"
		systemversion "latest"
		
		defines {
			"_CRT_SECURE_NO_WARNINGS"
		}
		
	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"
		
	filter "configurations:Release"
		runtime "Release"
		optimize "on"