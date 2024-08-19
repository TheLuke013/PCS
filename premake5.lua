workspace "PCS"
    architecture "x64"
    startproject "PCS"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- PCS
project "PCS"
    location "PCS"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS",
		"_SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS",
		"_SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING"
    }

    includedirs
    {
        "ThirdParty/raylib/include",
        "Motherboard/src"
    }

    links
    {
        "Motherboard"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        runtime "Release"
        optimize "On"

-- Motherboard
project "Motherboard"
    location "Motherboard"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS",
        "_SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS",
        "_SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING",
        "MOTHERBOARD_EXPORTS"
    }

    includedirs
    {
        
    }

    links
    {
        "CPU",
        "GPU",
        "RAM",
        "Storage"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

        postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/PCS")
		}

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        runtime "Release"
        optimize "On"

-- CPU
project "CPU"
    location "CPU"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS",
        "_SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS",
        "_SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING",
        "CPU_EXPORTS"
    }

    includedirs
    {
        
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

        postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/PCS")
		}

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        runtime "Release"
        optimize "On"

-- GPU
project "GPU"
    location "GPU"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS",
		"_SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS",
		"_SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING",
        "GPU_EXPORTS"
    }

    includedirs
    {
        "ThirdParty/raylib/include"
    }

    links
    {
        "ThirdParty/raylib/lib/raylib.lib",
        "winmm.lib",
        "kernel32.lib",
        "gdi32.lib",
        "user32.lib",
        "shell32.lib",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

        postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/PCS")
		}

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"
        linkoptions { "/NODEFAULTLIB:MSVCRT" }

    filter "configurations:Release"
        runtime "Release"
        optimize "On"
        linkoptions { "/NODEFAULTLIB:MSVCRT" }

    filter "configurations:Dist"
        runtime "Release"
        optimize "On"
        linkoptions { "/NODEFAULTLIB:MSVCRT" }

-- RAM
project "RAM"
    location "RAM"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS",
        "_SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS",
        "_SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING",
        "RAM_EXPORTS"
    }

    includedirs
    {
        
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

        postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/PCS")
		}

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        runtime "Release"
        optimize "On"

-- Storage
project "Storage"
    location "Storage"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS",
        "_SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS",
        "_SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING",
        "STORAGE_EXPORTS"
    }

    includedirs
    {
        
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

        postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/PCS")
		}

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        runtime "Release"
        optimize "On"
