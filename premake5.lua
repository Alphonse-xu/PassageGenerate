workspace "PassageGenerate" -- 解决方案
    startproject "PassageGenerate" -- 开始项目

    configurations
    {
        "Debug",
        "Release"
    }

    platforms
    {
        "Win32",
        "Win64"
    }

    filter "platforms:Win32"
        system "Windows"
        architecture "x32"

    filter "platforms:Win64"
        system "Windows"
        architecture "x86_64"

outputdir = "%{cfg.platform}%{cfg.buildcfg}/%{prj.name}"

project "PassageGenerate" -- 项目
    kind "ConsoleApp" -- 控制台应用
    language "C++"

    targetdir ("../bin/" .. outputdir)
    objdir ("../bin_obj/" .. outputdir)
    

    files
    {
        "./**.cpp", -- 当前文件夹所有.cpp文件
        "./**.h"
    }
