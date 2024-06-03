#include "CircleTextureDrawing.h"

void DrawTextureCircle(Texture2D texture, Vector2 pos, Vector2 circleCenter, float radius, Color color, std::string shaderPath, int glsl_VERSION)
{
    //Load shader
    Shader shader = LoadShader(0, TextFormat(shaderPath.c_str(), glsl_VERSION));

    //Load radius
    int radiusLoc = GetShaderLocation(shader, "radius");
    SetShaderValue(shader, radiusLoc, &radius, SHADER_UNIFORM_FLOAT);

    //Loading circle pos on texture
    float ciCe[2] = { circleCenter.x,circleCenter.y };
    int centerLoc = GetShaderLocation(shader, "center");
    SetShaderValue(shader, centerLoc, &ciCe, SHADER_UNIFORM_VEC2);

    //Load resolution
    float resolution[2] = { texture.width,texture.height };
    int resolutionLoc = GetShaderLocation(shader, "renderSize");
    SetShaderValue(shader, resolutionLoc, &resolution, SHADER_UNIFORM_VEC2);

    BeginShaderMode(shader);    // Enable our custom shader for next shapes/textures drawings

    DrawTextureV(texture, pos, color);

    EndShaderMode();

    UnloadShader(shader);
}

void DrawCollisionTextureCircle(Texture2D texture, Vector2 pos, Vector2 circleCenter, float radius, Color color, std::string shaderPath, int glsl_VERSION)
{
    //Load shader
    Shader shader = LoadShader(0, TextFormat(shaderPath.c_str(), glsl_VERSION));

    //Load radius
    int radiusLoc = GetShaderLocation(shader, "radius");
    SetShaderValue(shader, radiusLoc, &radius, SHADER_UNIFORM_FLOAT);

    //Loading circle pos on texture
    float ciCe[2] = { circleCenter.x - pos.x,circleCenter.y - pos.y };
    int centerLoc = GetShaderLocation(shader, "center");
    SetShaderValue(shader, centerLoc, &ciCe, SHADER_UNIFORM_VEC2);

    //Load resolution
    float resolution[2] = { texture.width,texture.height };
    int resolutionLoc = GetShaderLocation(shader, "renderSize");
    SetShaderValue(shader, resolutionLoc, &resolution, SHADER_UNIFORM_VEC2);

    BeginShaderMode(shader);    // Enable our custom shader for next shapes/textures drawings

    DrawTextureV(texture, pos, color);

    EndShaderMode();

    UnloadShader(shader);
}
