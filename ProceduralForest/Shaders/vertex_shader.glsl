#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aUV;
layout (location = 3) in vec3 aOffset;
layout (location = 4) in int textureID;

uniform mat4 worldMatrix;
uniform mat4 viewMatrix = mat4(1.0);
uniform mat4 projectionMatrix = mat4(1.0);

out vec2 vertexUV;
out vec3 FragPos;
out vec3 Normal;
flat out int TextID;
void main()
{
   mat4 modelViewProjection = projectionMatrix * viewMatrix * worldMatrix;
   gl_Position = modelViewProjection * vec4(aPos + aOffset, 1.0);
   vertexUV = aUV;
   FragPos = vec3(worldMatrix* vec4(aPos, 1.0));
   Normal = mat3(worldMatrix) * aNormal;
   TextID = textureID;
}