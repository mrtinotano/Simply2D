## Simply 2D

Seguimiento de desarrollo del motor Simply 2D. Un motor para crear videojuegos 2D sin necesidad de usar código.

# Application

Application is the base. 
Application life loop:
-Initialize
-Start
-Update Lopp:
  -Pre Update
  -Update
  -PostUpdate
Finish

## Add dependencies
- glm
- vulkan (vulkan headers)
- vulkan memmory allocation
- glsl
- dear imgui
- stb:
  -Leak Check

## Debug

-Assert
-Log
-Memory

## Event System


# Modules


## Window Module

-Windows:
-Register
-Create
-Events

fixes:
to fix const char* to lpcwstr error go to Advanced and set Character Set to Use multi-Byte character set 

## Render Module

White screen, now render to see anything.

### Vulkan 

vulkan headers repository
-Debug Extension
-Create Instance
-Create device
-Create windows surface
-Create Command Pool
-CreateSwapchain
-RenderPass
-Shaders
