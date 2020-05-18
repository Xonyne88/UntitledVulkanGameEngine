#pragma once
#include <iostream>
#if _DEBUG
#define LOG(x) std::cout<<x<<std::endl
#else 
#define LOG(x)
#endif
//#if RUN32BIT
//#endif
//#if OpenGL
//#define 
//#elif Vulkan
//#elif D3D11
//#endif