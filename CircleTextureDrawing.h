#pragma once
#include <string>

#include "raylib.h"

//pos - top left corner of texture; circleCenter - coordinates relative to pos; shaderPath - path to CircleTexture.frag
void DrawTextureCircle(Texture2D texture, Vector2 pos, Vector2 circleCenter, float radius, Color color, std::string shaderPath, int glsl_VERSION);

//shaderPath - path to CircleTexture.frag
void DrawCollisionTextureCircle(Texture2D texture, Vector2 pos, Vector2 circleCenter, float radius, Color color, std::string shaderPath, int glsl_VERSION);
