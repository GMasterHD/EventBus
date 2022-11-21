project "EventBus"
	kind "StaticLib"
	systemversion "latest"
	language "C++"
	cppdialect "C++20"
	location "%{wks.location}/EventBus"

	debugdir "%{wks.location}/bin/%{cfg.system}/%{cfg.longname}/%{prj.name}"
	targetdir "%{wks.location}/bin/%{cfg.system}/%{cfg.longname}/%{prj.name}"
	objdir "%{wks.location}/bin-int/%{cfg.system}/%{cfg.longname}/%{prj.name}"

	files {
		"%{prj.location}/**.c",
		"%{prj.location}/**.h",
		"%{prj.location}/**.cpp",
		"%{prj.location}/**.hpp"
	}

	defines {
	}

	includedirs {
		"%{wks.location}/include/"
	}

	filter "configurations:Debug*"
		symbols "On"
		optimize "Off"
		defines { "EB_DEBUG" }
	filter "configurations:Release*"
		symbols "Off"
		optimize "Speed"
		defines { "EB_RELEASE", "EB_NDEBUG" }
	
	filter "system:windows"
		defines { "EB_WINDOWS" }
	filter "system:linux"
		defines { "EB_UNIX", "EB_LINUX" }
	filter "system:macosx"
		defines { "EB_MACOSX" }
