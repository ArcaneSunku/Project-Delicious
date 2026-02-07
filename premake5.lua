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
		"%{prj.name}/src",
		"delicious/vendors/raylib/include",
		"delicious/vendors/raygui/src"
	}
	
	links {
		"delicious/vendors/raylib/lib/raylibdll.lib"
	}
	
	filter "system:windows"
		systemversion "latest"
		
		defines {
			"_CRT_SECURE_NO_WARNINGS"
		}

		buildoutputs {
			"%{cfg.targetdir}/raylib.dll",
			"%{cfg.targetdir}/assets"
		}

		prebuildcommands {
			'if exist "%{cfg.targetdir}\\raylib.dll" del /Q "%{cfg.targetdir}\\raylib.dll"',
			'if exist "%{cfg.targetdir}\\assets" rmdir /S /Q "%{cfg.targetdir}\\assets"'
		}

		postbuildcommands {
			"{COPYFILE} %{wks.location}/delicious/vendors/raylib/lib/raylib.dll %{cfg.targetdir}",
			"{COPYDIR} %{wks.location}/delicious/assets %{cfg.targetdir}/assets"
		}

	filter "system:linux"
		systemversion "latest"
		
	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"
		
	filter "configurations:Release"
		runtime "Release"
		optimize "on"