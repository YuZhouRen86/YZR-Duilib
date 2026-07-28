# YZR Duilib

YZR Duilib 是一个界面库，包含了一整套 Windows 桌面软件的开发部件，使用 C++ 语言开发。直接基于 [nim_duilib](https://github.com/rhett-lee/nim_duilib) 库继续开发。您可以直接使用 YZR Duilib 界面库来开发常用的桌面应用，以简化应用程序的UI开发工作。

![GitHub](https://img.shields.io/badge/license-MIT-green.svg)

## 重要说明

本项目的主要开发者在明年8月前因故无法抽出时间发布更新，欢迎大家在议题区、讨论区踊跃提出意见！

## 特色

 - 核心特性包括：
    - 通用样式：支持以 XML 格式描述应用程序的窗口属性、布局属性、控件属性等，方便调整界面元素的位置和大小，较为灵活
    - 控件丰富：包含各种常见的窗口和控件，如图片控件、动画控件、按钮、文本框、列表控件、虚表控件、树控件、颜色选择控件、菜单等
    - 事件驱动：基于消息机制的事件处理，使得 UI 交互逻辑清晰
    - 皮肤支持：通过 XML 文件定义皮肤结构，可以轻松改变界面风格
 - 多种图片格式，支持的图片文件格式有：SVG/PNG/GIF/JPG/BMP/APNG/WEBP/ICO
 - 动画图片，支持 GIF 动画文件、APNG 动画文件、WebP 动画文件
 - 支持 DPI 感知（Unaware、SystemAware、PerMonitorAware、PerMonitorAware_V2 四种模式），支持独立设置 DPI，支持高清 DPI 的适配
 - 触控设备支持（Surface、Wacom）
 - 多国语言支持，支持动态多种语言切换，易于实现国际化
 - CEF 控件支持

## 目录
| 目录          | 说明 |
| :---          | :--- |
| duilib        | 项目的核心代码|
| docs          | 项目的说明文档|
| libs          | 静态库编译后的输出目录，包含预设的一些 CEF 组件静态库|
| bin           | 各个示例程序输出目录，包含预设的皮肤和语言文件以及 CEF 依赖|
| manifest      | Windows 平台的应用程序清单文件|
| licenses      | 引用的其他开源代码对应的 licenses 文件|
| examples      | 项目的示例程序源代码|
| duilib/third_party| 项目代码依赖的第三方库，详细内容见后续文档|
| ui_components | 基于 YZR Duilib 封装的常用组件库如 msgbox、toast、cef_control 等|

## 开始

1. 编译 YZR Duilib：进入 `YZR-Duilib/examples` 目录，使用 Visual Studio 2015 以上版本的 IDE 打开 `examples.sln`，选择编译选项，按下 F7 即可编译所有示例程序（编译完成的示例程序位于 bin 目录中）。

2. 编译附件说明：    
（1）项目中工程的编译环境为 Visual Studio 2015 版本，如果使用其他版本的 Visual Studio 编译器，需要手动更新编译工程的属性。
（2）YZR Duilib 的代码兼容性默认是支持 Windows 7 以上系统，未支持 Windows XP；Windows SDK 的兼容性配置可在[duilib\duilib_config.h](duilib/duilib_config.h)文件中修改。
（3）渲染引擎的支持：YZR Duilib 内部使用 Gdiplus 绘制引擎。

## 基于 nim_duilib 源码做的主要修改
1. 修改代码以兼容 Visual Studio 2015。
2. 移除所有外部依赖项，直接打开项目文件即可一次性编译。

## 使用的第三方库说明
| 名称     |代码子目录| 用途 | license 文件|
| :---     | :---     |:---  |:---        |
|apng      |third_party/libpng| 支持 APNG 图片格式|zlib/libpng License|
|libpng    |third_party/libpng| 支持 PNG 图片格式|[libpng.LICENSE.txt](licenses/libpng.LICENSE.txt)|
|zlib      |third_party/zlib| 支持 PNG/APNG 图片格式、Zip 文件解压|[zlib.LICENSE.txt](licenses/zlib.LICENSE.txt)|
|cximage   |third_party/cximage| 支持 GIF/ICO 图片格式|[cximage.LICENSE.txt](licenses/cximage.LICENSE.txt)|
|libwebp   |third_party/libwebp| 支持 WebP 图片格式|[libWebP.LICENSE.txt](licenses/libwebp.LICENSE.txt)|
|stb_image |third_party/stb_image| 支持 JPEG/BMP 图片格式，调整图片大小|[stb_image.LICENSE.txt](licenses/stb_image.LICENSE.txt)|
|nanosvg   |third_party/svg| 支持 SVG 图片格式|[nanosvg.LICENSE.txt](licenses/nanosvg.LICENSE.txt)|
|pugixml   |third_party/xml| 支持资源描述 XML 的解析|[pugixml.LICENSE.txt](licenses/pugixml.LICENSE.txt)|
|ConvertUTF|third_party/convert_utf| 用于 UTF-8/UTF-16 编码的相互转换|[llvm.LICENSE.txt](licenses/llvm.LICENSE.txt)|
|directui  |                       | 借鉴界面库框架|[directui.LICENSE.txt](licenses/directui.LICENSE.txt)|
|duilib    |                       | NIM_Duilib_Framework 基于 duilib 开发|[duilib.LICENSE.txt](licenses/duilib.LICENSE.txt)|
|NIM_Duilib_Framework|             | nim_duilib 基于 NIM_Duilib_Framework 开发|[NIM_Duilib_Framework.LICENSE.txt](licenses/NIM_Duilib_Framework.LICENSE.txt)|
|nim_duilib|             | 本项目基于 nim_duilib 开发|[nim_duilib.LICENSE.txt](licenses/nim_duilib.LICENSE.txt)|

## 开发计划
 - 窗口的封装优化：尝试在保证项目高度精简的同时支持其他操作系统
 - 对屏幕触控的更好支持
 - 动画功能的加强
 - 不断测试发现缺陷并修复，不断完善代码
 - 其他待补充

## 参考文档

 - [快速上手](docs/Getting-Started.md)
 - [参考文档](docs/Summary.md)
 - [示例程序](docs/Examples.md)