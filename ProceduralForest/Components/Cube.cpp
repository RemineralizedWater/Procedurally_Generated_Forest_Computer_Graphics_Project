//
// Created by Steven Smith on 2020-03-08.
// Created for Comp 371 Concordia W 2020
/*
 * Basic Cube model extendeding the Component class. Used extensively in the construction
 * of all our more complex models. Contains functions for translations, rotations, etc....
 */
#include "Cube.h"
#include "Component.h"
#include <GL/glew.h>    // Include GLEW - OpenGL Extension Wrangler
#include <World.h>
// initializing OpenGL and binding inputs
#include "glm/glm.hpp"  // GLM is an optimized math library with syntax to similar to OpenGL Shading Language


Cube::Cube(Material material, vec3 size): Component{material, size}{
    vao = createVertexArrayObject();
}
GLuint Cube::createVertexArrayObject(){
    // Cube model
    // Cube model stolen from lab 3
    const TexturedColoredVertex texturedCubeVertexArray[] = {  // position,
            TexturedColoredVertex(transform.size * vec3(-0.5f,-0.5f,-0.5f),vec3(-1.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f)), //left - red
            TexturedColoredVertex(transform.size *vec3(-0.5f,-0.5f, 0.5f),vec3(-1.0f, 0.0f, 0.0f),vec2(0.0f, 1.0f)),
            TexturedColoredVertex(transform.size *vec3(-0.5f, 0.5f, 0.5f), vec3(-1.0f, 0.0f, 0.0f),vec2(1.0f, 1.0f)),

            TexturedColoredVertex(transform.size *vec3(-0.5f,-0.5f,-0.5f), vec3(-1.0f, 0.0f, 0.0f),vec2(0.0f, 0.0f)),
            TexturedColoredVertex(transform.size *vec3(-0.5f, 0.5f, 0.5f), vec3(-1.0f, 0.0f, 0.0f),vec2(1.0f, 1.0f)),
            TexturedColoredVertex(transform.size *vec3(-0.5f, 0.5f,-0.5f), vec3(-1.0f, 0.0f, 0.0f),vec2(1.0f, 0.0f)),

            TexturedColoredVertex(transform.size *vec3( 0.5f, 0.5f,-0.5f), vec3( 0.0f, 0.0f,-1.0f),vec2(1.0f, 1.0f)), // far - blue
            TexturedColoredVertex(transform.size *vec3(-0.5f,-0.5f,-0.5f), vec3( 0.0f, 0.0f,-1.0f),vec2(0.0f, 0.0f)),
            TexturedColoredVertex(transform.size *vec3(-0.5f, 0.5f,-0.5f), vec3( 0.0f, 0.0f,-1.0f),vec2(0.0f, 1.0f)),

            TexturedColoredVertex(transform.size *vec3( 0.5f, 0.5f,-0.5f), vec3( 0.0f, 0.0f,-1.0f),vec2(1.0f, 1.0f)),
            TexturedColoredVertex(transform.size *vec3( 0.5f,-0.5f,-0.5f), vec3( 0.0f, 0.0f,-1.0f),vec2(1.0f, 0.0f)),
            TexturedColoredVertex(transform.size *vec3(-0.5f,-0.5f,-0.5f), vec3( 0.0f, 0.0f,-1.0f),vec2(0.0f, 0.0f)),

            TexturedColoredVertex(transform.size *vec3( 0.5f,-0.5f, 0.5f), vec3( 0.0f,-1.0f, 0.0f),vec2(1.0f, 1.0f)), // bottom - turquoise
            TexturedColoredVertex(transform.size *vec3(-0.5f,-0.5f,-0.5f), vec3( 0.0f,-1.0f, 0.0f),vec2(0.0f, 0.0f)),
            TexturedColoredVertex(transform.size *vec3( 0.5f,-0.5f,-0.5f), vec3( 0.0f,-1.0f, 0.0f),vec2(1.0f, 0.0f)),

            TexturedColoredVertex(transform.size *vec3( 0.5f,-0.5f, 0.5f),vec3( 0.0f,-1.0f, 0.0f), vec2(1.0f, 1.0f)),
            TexturedColoredVertex(transform.size *vec3(-0.5f,-0.5f, 0.5f), vec3( 0.0f,-1.0f, 0.0f),vec2(0.0f, 1.0f)),
            TexturedColoredVertex(transform.size *vec3(-0.5f,-0.5f,-0.5f), vec3( 0.0f,-1.0f, 0.0f),vec2(0.0f, 0.0f)),

            TexturedColoredVertex(transform.size *vec3(-0.5f, 0.5f, 0.5f),vec3( 0.0f, 0.0f, 1.0f), vec2(0.0f, 1.0f)), // near - green
            TexturedColoredVertex(transform.size *vec3(-0.5f,-0.5f, 0.5f),vec3( 0.0f, 0.0f, 1.0f), vec2(0.0f, 0.0f)),
            TexturedColoredVertex(transform.size *vec3( 0.5f,-0.5f, 0.5f), vec3( 0.0f, 0.0f, 1.0f),vec2(1.0f, 0.0f)),

            TexturedColoredVertex(transform.size *vec3( 0.5f, 0.5f, 0.5f), vec3( 0.0f, 0.0f, 1.0f),vec2(1.0f, 1.0f)),
            TexturedColoredVertex(transform.size *vec3(-0.5f, 0.5f, 0.5f), vec3( 0.0f, 0.0f, 1.0f),vec2(0.0f, 1.0f)),
            TexturedColoredVertex(transform.size *vec3( 0.5f,-0.5f, 0.5f), vec3( 0.0f, 0.0f, 1.0f),vec2(1.0f, 0.0f)),

            TexturedColoredVertex(transform.size *vec3( 0.5f, 0.5f, 0.5f), vec3( 1.0f, 0.0f, 0.0f),vec2(1.0f, 1.0f)), // right - purple
            TexturedColoredVertex(transform.size *vec3( 0.5f,-0.5f,-0.5f), vec3( 1.0f, 0.0f, 0.0f),vec2(0.0f, 0.0f)),
            TexturedColoredVertex(transform.size *vec3( 0.5f, 0.5f,-0.5f), vec3( 1.0f, 0.0f, 0.0f),vec2(1.0f, 0.0f)),

            TexturedColoredVertex(transform.size *vec3( 0.5f,-0.5f,-0.5f), vec3( 1.0f, 0.0f, 0.0f),vec2(0.0f, 0.0f)),
            TexturedColoredVertex(transform.size *vec3( 0.5f, 0.5f, 0.5f),vec3( 1.0f, 0.0f, 0.0f), vec2(1.0f, 1.0f)),
            TexturedColoredVertex(transform.size *vec3( 0.5f,-0.5f, 0.5f),vec3( 1.0f, 0.0f, 0.0f), vec2(0.0f, 1.0f)),

            TexturedColoredVertex(transform.size *vec3( 0.5f, 0.5f, 0.5f),vec3( 0.0f, 1.0f, 0.0f), vec2(1.0f, 1.0f)), // top - yellow
            TexturedColoredVertex(transform.size *vec3( 0.5f, 0.5f,-0.5f), vec3( 0.0f, 1.0f, 0.0f),vec2(1.0f, 0.0f)),
            TexturedColoredVertex(transform.size *vec3(-0.5f, 0.5f,-0.5f), vec3( 0.0f, 1.0f, 0.0f),vec2(0.0f, 0.0f)),

            TexturedColoredVertex(transform.size *vec3( 0.5f, 0.5f, 0.5f), vec3( 0.0f, 1.0f, 0.0f),vec2(1.0f, 1.0f)),
            TexturedColoredVertex(transform.size *vec3(-0.5f, 0.5f,-0.5f),vec3( 0.0f, 1.0f, 0.0f), vec2(0.0f, 0.0f)),
            TexturedColoredVertex(transform.size *vec3(-0.5f, 0.5f, 0.5f),vec3( 0.0f, 1.0f, 0.0f), vec2(0.0f, 1.0f))
    };
    // Create a vertex array
    GLuint vertexArrayObject;
    glGenVertexArrays(1, &vertexArrayObject);
    glBindVertexArray(vertexArrayObject);
    // Upload Vertex Buffer to the GPU, keep a reference to it (vertexBufferObject)
    GLuint vertexBufferObject;
    glGenBuffers(1, &vertexBufferObject);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
    glBufferData(GL_ARRAY_BUFFER, sizeof(texturedCubeVertexArray), texturedCubeVertexArray, GL_STATIC_DRAW);

    glVertexAttribPointer(0,                   // attribute 0 matches aPos in Vertex Shader
                          3,                   // size
                          GL_FLOAT,            // type
                          GL_FALSE,            // normalized?
                          sizeof(TexturedColoredVertex), // stride - each vertex contain 2 vec3 (position, color)
                          (void*)0             // array buffer offset
    );
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1,                            // attribute 2 matches aUV in Vertex Shader
                          3,
                          GL_FLOAT,
                          GL_FALSE,
                          sizeof(TexturedColoredVertex),
                          (void*)(1*sizeof(vec3))      // uv is offseted by 2 vec3 (comes after position and color)
    );
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2,                            // attribute 2 matches aUV in Vertex Shader
                          2,
                          GL_FLOAT,
                          GL_FALSE,
                          sizeof(TexturedColoredVertex),
                          (void*)(2*sizeof(vec3))      // uv is offseted by 2 vec3 (comes after position and color)
    );
    glEnableVertexAttribArray(2);

    return vertexArrayObject;
}

void Cube::Draw(){
    // set transform to mat4(1.0)
    glm::mat4 modelWorldMatrix = mat4(1.0f);
    transform.transformation = mat4(1.0);
    // load textures
    if(material.isTextured) {
       //shaderProgram.setInt("textureSampler", 0);
       glActiveTexture(GL_TEXTURE0);
       glBindTexture(GL_TEXTURE_2D, material.diffuseMapId);
       Renderer::getCurrentShader()->setBool("material.isTextured", true);
       Renderer::getCurrentShader()->setInt("material.diffuseMap[0]", 0);
        // Set our Texture sampler to user Texture Unit 0
    }
    // load the proper vao
    glBindVertexArray(vao);
    //glBindBuffer(GL_ARRAY_BUFFER, vbo);
    // set the color
    Renderer::getCurrentShader()->setVec3("material.color", material.vertexColor.x, material.vertexColor.y, material.vertexColor.z);
    // setup transform
    transform.transformation = translate(transform.transformation, transform.position);
    transform.transformation = transform.transformation * glm::mat4_cast(transform.rotation);
    transform.transformation = glm::scale(transform.transformation, transform.scaling);
    // matrix on the right applies first so we want to do the following
    modelWorldMatrix = World::getCurrent().getTransform().transformation* parent->transformation * transform.transformation;
    Renderer::getCurrentShader()->setMat4("worldMatrix", modelWorldMatrix);
    // draw a cube
    glDrawArrays(Renderer::getRenderMode(), 0, 36);
    Renderer::getCurrentShader()->setBool("material.isTextured", false);

}