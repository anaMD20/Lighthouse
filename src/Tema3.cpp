#include "lab_m1/lab9/lab9.h"

#include <vector>
#include <string>
#include <iostream>

using namespace std;
using namespace m1;


/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */


Lab9::Lab9()
{
    std::vector<Boat> boats;
}


Lab9::~Lab9()
{
}


void Lab9::Init()
{
    const string sourceTextureDir = PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "lab9", "textures");
    Boat boat1;
    boat1.position = glm::vec3(-2, 0.1f, -2);
    boat1.radius = 2.0f;
    boat1.angularSpeed = 1.0f;
    boat1.direction = 1;
    boat1.plutaTexture = mapTextures["lemn"];
    boat1.catargTexture = mapTextures["grey"];
    boat1.panzaTexture = mapTextures["blue"];
    boat1.steagTexture = mapTextures["black30"];
    boats.push_back(boat1);

    Boat boat2;
    boat2.position = glm::vec3(2, 0.1f, -2);
    boat2.radius = 2.0f;
    boat2.angularSpeed = 1.0f;
    boat2.direction = -1;
    boat2.plutaTexture = mapTextures["lemn"];
    boat2.catargTexture = mapTextures["grey"];
    boat2.panzaTexture = mapTextures["blue"];
    boat2.steagTexture = mapTextures["black30"];
    boats.push_back(boat2);

    Boat boat3;
    boat3.position = glm::vec3(0, 0.1f, -2);
    boat3.radius = 2.0f;
    boat3.angularSpeed = 1.0f;
    boat3.direction = 1;
    boat3.plutaTexture = mapTextures["lemn"];
    boat3.catargTexture = mapTextures["grey"];
    boat3.panzaTexture = mapTextures["blue"];
    boat3.steagTexture = mapTextures["black30"];
    boats.push_back(boat3);

    Boat boat4;
    boat4.position = glm::vec3(0, 0.1f, -2);
    boat4.radius = 2.0f;
    boat4.angularSpeed = 1.0f;
    boat4.direction = 1;
    boat4.plutaTexture = mapTextures["lemn"];
    boat4.catargTexture = mapTextures["grey"];
    boat4.panzaTexture = mapTextures["panza"];
    boat4.steagTexture = mapTextures["steag"];
    boats.push_back(boat4);


    // Load textures
    

    {
        Texture2D* texture = new Texture2D();
        texture->Load2D(PATH_JOIN(sourceTextureDir, "crate.jpg").c_str(), GL_REPEAT);
        mapTextures["crate"] = texture;
    }

    {
        Texture2D* texture = new Texture2D();
        texture->Load2D(PATH_JOIN(sourceTextureDir, "moon.jpg").c_str(), GL_REPEAT);
        mapTextures["moon"] = texture;
    }

    {
        Texture2D* texture = new Texture2D();
		texture->Load2D(PATH_JOIN(sourceTextureDir, "mooon.jpg").c_str(), GL_REPEAT);
		mapTextures["mooon"] = texture;
    }

    {
		Texture2D* texture = new Texture2D();
		texture->Load2D(PATH_JOIN(sourceTextureDir, "lemn.jpg").c_str(), GL_REPEAT);
		mapTextures["lemn"] = texture;
	}

    {
        Texture2D* texture = new Texture2D();
        texture->Load2D(PATH_JOIN(sourceTextureDir, "apa.jpg").c_str(), GL_REPEAT);
        mapTextures["apa"] = texture;
    }

    {
        		Texture2D* texture = new Texture2D();
		texture->Load2D(PATH_JOIN(sourceTextureDir, "luna.png").c_str(), GL_REPEAT);
		mapTextures["luna"] = texture;
    }

    {
        Texture2D* texture = new Texture2D();
		texture->Load2D(PATH_JOIN(sourceTextureDir, "ocean.jpg").c_str(), GL_REPEAT);
		mapTextures["ocean"] = texture;
	}

    {
        Texture2D* texture = new Texture2D();
        texture->Load2D(PATH_JOIN(sourceTextureDir, "earth.jpg").c_str(), GL_REPEAT);
        mapTextures["earth"] = texture;

    }
    {
        Texture2D* texture = new Texture2D();
		texture->Load2D(PATH_JOIN(sourceTextureDir, "grass.jpg").c_str(), GL_REPEAT);
		mapTextures["grass"] = texture;
    }

    {
        Texture2D* texture = new Texture2D();
        texture->Load2D(PATH_JOIN(sourceTextureDir, "iarba.jpeg").c_str(), GL_REPEAT);
        mapTextures["iarba"] = texture;
    }

    {
        Texture2D* texture = new Texture2D();
		texture->Load2D(PATH_JOIN(sourceTextureDir, "grey.jpg").c_str(), GL_REPEAT);
		mapTextures["grey"] = texture;
	}

    {
		Texture2D* texture = new Texture2D();
		texture->Load2D(PATH_JOIN(sourceTextureDir, "random.jpg").c_str(), GL_REPEAT);
		mapTextures["random"] = texture;
	}

    {
		Texture2D* texture = new Texture2D();
		texture->Load2D(PATH_JOIN(sourceTextureDir, "bamboo.png").c_str(), GL_REPEAT);
		mapTextures["bamboo"] = texture;
    }

    {
        Texture2D* texture = new Texture2D();
        texture->Load2D(PATH_JOIN(sourceTextureDir, "blue.jpg").c_str(), GL_REPEAT);
        mapTextures["blue"] = texture;
    }

    {
        Texture2D* texture = new Texture2D();
        texture->Load2D(PATH_JOIN(sourceTextureDir, "black30.jpg").c_str(), GL_REPEAT);
        mapTextures["black30"] = texture;
    }

    {
        Texture2D* texture = new Texture2D();
        texture->Load2D(PATH_JOIN(sourceTextureDir, "white.png").c_str(), GL_REPEAT);
        mapTextures["white"] = texture;
    }

    {
        Texture2D* texture = new Texture2D();
        texture->Load2D(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "vegetation", "bamboo", "bamboo.png").c_str(), GL_REPEAT);
        mapTextures["bamboo"] = texture;
    }

    {
        mapTextures["random"] = CreateRandomTexture(25, 25);
    }

    // Load meshes
    {
        Mesh* mesh = new Mesh("box");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "box.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }

    {
        Mesh* mesh = new Mesh("quad");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "quad.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }

    {
        Mesh* mesh = new Mesh("sphere");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "sphere.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }

    {
        Mesh* mesh = new Mesh("bamboo");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "vegetation", "bamboo"), "bamboo.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }

    {
        Mesh* mesh = new Mesh("pluta");
		mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "pluta.obj");
		meshes[mesh->GetMeshID()] = mesh;
    }

    {
        Mesh* mesh = new Mesh("panza");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "panza.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }

    {
        Mesh* mesh = new Mesh("steag");
		mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "steag.obj");
		meshes[mesh->GetMeshID()] = mesh;
    }

    {
        Mesh* mesh = new Mesh("catarg");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "catarg.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }

    {
        Mesh* mesh = new Mesh("cylinder");
		mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "cylinder.obj");
		meshes[mesh->GetMeshID()] = mesh;
    }

    // Create a simple quad
    {
        vector<glm::vec3> vertices
        {
            glm::vec3(0.5f,   0.5f, 0.0f),    // top right
            glm::vec3(0.5f,  -0.5f, 0.0f),    // bottom right
            glm::vec3(-0.5f, -0.5f, 0.0f),    // bottom left
            glm::vec3(-0.5f,  0.5f, 0.0f),    // top left
        };

        vector<glm::vec3> normals
        {
            glm::vec3(0, 1, 1),
            glm::vec3(1, 0, 1),
            glm::vec3(1, 0, 0),
            glm::vec3(0, 1, 0)
        };

        vector<glm::vec2> textureCoords
        {
            // TODO(student): Complete texture coordinates for the square
            glm::vec2(1.0f, 0.0f),
            glm::vec2(1.0f, 1.0f),
            glm::vec2(0.0f, 1.0f),
            glm::vec2(0.0f, 0.0f)

        };

        vector<unsigned int> indices =
        {
            0, 1, 3,
            1, 2, 3
        };

        Mesh* mesh = new Mesh("square");
        mesh->InitFromData(vertices, normals, textureCoords, indices);
        meshes[mesh->GetMeshID()] = mesh;
    }

    // Create a shader program for drawing face polygon with the color of the normal
    {
        Shader *shader = new Shader("LabShader");
        shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "lab9", "shaders", "VertexShader.glsl"), GL_VERTEX_SHADER);
        shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "lab9", "shaders", "FragmentShader.glsl"), GL_FRAGMENT_SHADER);
        shader->CreateAndLink();
        shaders[shader->GetName()] = shader;
    }
}


void Lab9::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
}

float angle1 = 0.0f; // Unghiul inițial
float angle2 = 0.0f; // Unghiul inițial
float angle3 = 0.0f; // Unghiul inițial
float angle4 = 0.0f; // Unghiul inițial
float speed = 1.0f; // Viteza de rotație (radiani pe secundă)
float radius1 = 2.5f; // Raza cercului
float radius2 = 2; // Raza cercului
float radius3 = 1.5f; // Raza cercului
float radius4 = 3; // Raza cercului
glm::vec3 center(0, -0.5, -2); // Centrul cercului

glm::vec3 calculatePosition1(float angle) {
    // Calculul noii poziții pe cerc
    float x = center.x + radius1 * cos(angle);
    float z = center.z + radius1 * sin(angle);
    return glm::vec3(x, 0, z);
}
glm::vec3 calculatePosition2(float angle) {
    // Calculul noii poziții pe cerc
    float x = center.x + radius2 * cos(angle);
    float z = center.z + radius2 * sin(angle);
    return glm::vec3(x, 0, z);
}
glm::vec3 calculatePosition3(float angle) {
    // Calculul noii poziții pe cerc
    float x = center.x + radius3 * cos(angle);
    float z = center.z + radius3 * sin(angle);
    return glm::vec3(x, 0, z);
}
glm::vec3 calculatePosition4(float angle) {
    // Calculul noii poziții pe cerc
    float x = center.x + radius4 * cos(angle);
    float z = center.z + radius4 * sin(angle);
    return glm::vec3(x, 0, z);
}






void Lab9::Update(float deltaTimeSeconds)
{
    // TODO(student): Choose an object and add a second texture to it.
    // For example, for the sphere, you can have the "earth" texture
    // and the "random" texture, and you will use the `mix` function
    // in the fragment shader to mix these two textures.
    //
    // However, you may have the unpleasant surprise that the "random"
    // texture now appears onto all objects in the scene, even though
    // you are only passing the second texture for a single object!
    // Why does this happen? How can you solve it?

    angle1 += deltaTimeSeconds * speed;
    if (angle1 > 2 * M_PI) angle1 -= 2 * M_PI;

    // Calculul poziției curente
    glm::vec3 currentPosition = calculatePosition1(angle1);

    // Calculul poziției următoare pentru a determina direcția de orientare
    glm::vec3 nextPosition = calculatePosition1(angle1 + 0.1f);

    // Crearea matricei de model folosind funcția look-at
    glm::vec3 up = glm::vec3(0, 1, 0); // Vectorul "sus"
    glm::mat4 modelMatrix = glm::lookAt(currentPosition, nextPosition, up);

    // Inversăm matricea pentru a obține orientarea corectă
    modelMatrix = glm::inverse(modelMatrix);
    modelMatrix = glm::scale(modelMatrix, glm::vec3(0.05f));

    // Rotim barca cu 90 de grade în jurul axei Y
    modelMatrix = glm::rotate(modelMatrix, glm::radians(90.0f), glm::vec3(0, 1, 0));

    // Aplicăm translația pentru a muta barca la poziția curentă
    modelMatrix = glm::translate(glm::mat4(1.0f), currentPosition) * modelMatrix;

    // Redăm barca
    RenderSimpleMesh(meshes["pluta"], shaders["LabShader"], modelMatrix, mapTextures["lemn"]);
    RenderSimpleMesh(meshes["catarg"], shaders["LabShader"], modelMatrix, mapTextures["grey"]);
    RenderSimpleMesh(meshes["panza"], shaders["LabShader"], modelMatrix, mapTextures["blue"]);
    RenderSimpleMesh(meshes["steag"], shaders["LabShader"], modelMatrix, mapTextures["black30"]);

    angle2 -= deltaTimeSeconds * speed;
    if (angle2 > 2 * M_PI) angle2 -= 2 * M_PI;

    // Calculul poziției curente
    glm::vec3 currentPosition2 = calculatePosition2(angle2);

    // Calculul poziției următoare pentru a determina direcția de orientare
    glm::vec3 nextPosition2 = calculatePosition2(angle1 + 0.1f);

    // Crearea matricei de model folosind funcția look-at
    glm::vec3 up2 = glm::vec3(0, 1, 0); // Vectorul "sus"
    glm::mat4 modelMatrix2 = glm::lookAt(currentPosition2, nextPosition2, up2);

    // Inversăm matricea pentru a obține orientarea corectă
    modelMatrix2 = glm::inverse(modelMatrix2);
    modelMatrix2 = glm::scale(modelMatrix2, glm::vec3(0.05f));

    // Rotim barca cu 90 de grade în jurul axei Y
    modelMatrix2 = glm::rotate(modelMatrix2, glm::radians(90.0f), glm::vec3(0, 1, 0));

    // Aplicăm translația pentru a muta barca la poziția curentă
    modelMatrix2 = glm::translate(glm::mat4(1.0f), currentPosition2) * modelMatrix2;

    // Redăm barca
    RenderSimpleMesh(meshes["pluta"], shaders["LabShader"], modelMatrix2, mapTextures["lemn"]);
    RenderSimpleMesh(meshes["catarg"], shaders["LabShader"], modelMatrix2, mapTextures["grey"]);
    RenderSimpleMesh(meshes["panza"], shaders["LabShader"], modelMatrix2, mapTextures["blue"]);
    RenderSimpleMesh(meshes["steag"], shaders["LabShader"], modelMatrix2, mapTextures["black30"]);

    angle3 += deltaTimeSeconds * speed;
    if (angle3 > 2 * M_PI) angle3 -= 2 * M_PI;

    // Calculul poziției curente
    glm::vec3 currentPosition3 = calculatePosition3(angle3);

    // Calculul poziției următoare pentru a determina direcția de orientare
    glm::vec3 nextPosition3 = calculatePosition3(angle3 + 0.1f);

    // Crearea matricei de model folosind funcția look-at
    glm::vec3 up3 = glm::vec3(0, 1, 0); // Vectorul "sus"
    glm::mat4 modelMatrix3 = glm::lookAt(currentPosition3, nextPosition3, up3);

    // Inversăm matricea pentru a obține orientarea corectă
    modelMatrix3 = glm::inverse(modelMatrix3);
    modelMatrix3 = glm::scale(modelMatrix3, glm::vec3(0.05f));

    // Rotim barca cu 90 de grade în jurul axei Y
    modelMatrix3 = glm::rotate(modelMatrix3, glm::radians(90.0f), glm::vec3(0, 1, 0));

    // Aplicăm translația pentru a muta barca la poziția curentă
    modelMatrix3 = glm::translate(glm::mat4(1.0f), currentPosition3) * modelMatrix3;

    // Redăm barca
    RenderSimpleMesh(meshes["pluta"], shaders["LabShader"], modelMatrix3, mapTextures["lemn"]);
    RenderSimpleMesh(meshes["catarg"], shaders["LabShader"], modelMatrix3, mapTextures["grey"]);
    RenderSimpleMesh(meshes["panza"], shaders["LabShader"], modelMatrix3, mapTextures["blue"]);
    RenderSimpleMesh(meshes["steag"], shaders["LabShader"], modelMatrix3, mapTextures["black30"]);

    angle4 -= deltaTimeSeconds * speed;
    if (angle4 > 2 * M_PI) angle4 -= 2 * M_PI;

    // Calculul poziției curente
    glm::vec3 currentPosition4 = calculatePosition4(angle4);

    // Calculul poziției următoare pentru a determina direcția de orientare
    glm::vec3 nextPosition4 = calculatePosition4(angle4 + 0.1f);

    // Crearea matricei de model folosind funcția look-at
    glm::vec3 up4 = glm::vec3(0, 1, 0); // Vectorul "sus"
    glm::mat4 modelMatrix4 = glm::lookAt(currentPosition4, nextPosition4, up4);

    // Inversăm matricea pentru a obține orientarea corectă
    modelMatrix4 = glm::inverse(modelMatrix4);
    modelMatrix4 = glm::scale(modelMatrix4, glm::vec3(0.05f));

    // Rotim barca cu 90 de grade în jurul axei Y
    modelMatrix4 = glm::rotate(modelMatrix4, glm::radians(90.0f), glm::vec3(0, 1, 0));

    // Aplicăm translația pentru a muta barca la poziția curentă
    modelMatrix4 = glm::translate(glm::mat4(1.0f), currentPosition4) * modelMatrix4;

    // Redăm barca
    RenderSimpleMesh(meshes["pluta"], shaders["LabShader"], modelMatrix4, mapTextures["lemn"]);
    RenderSimpleMesh(meshes["catarg"], shaders["LabShader"], modelMatrix4, mapTextures["grey"]);
    RenderSimpleMesh(meshes["panza"], shaders["LabShader"], modelMatrix4, mapTextures["blue"]);
    RenderSimpleMesh(meshes["steag"], shaders["LabShader"], modelMatrix4, mapTextures["black30"]);

    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(-2, 2, 0));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(0.5f));
        RenderSimpleMesh(meshes["sphere"], shaders["LabShader"], modelMatrix, mapTextures["mooon"]);
    }

    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 0, 0));
        modelMatrix = glm::rotate(modelMatrix, RADIANS(90.0f), glm::vec3(1, 0, 0));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(30));
        RenderSimpleMesh(meshes["quad"], shaders["LabShader"], modelMatrix, mapTextures["apa"]);
    }

    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(0, -0.5f, -2));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(2));
        RenderSimpleMesh(meshes["sphere"], shaders["LabShader"], modelMatrix, mapTextures["grass"]);
    }

    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 0.5, -2));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(0.4));
        RenderSimpleMesh(meshes["cylinder"], shaders["LabShader"], modelMatrix, mapTextures["grey"]);

    }
    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 0.9, -2));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(0.4));
        RenderSimpleMesh(meshes["cylinder"], shaders["LabShader"], modelMatrix, mapTextures["grey"]);

    }
    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 1.3, -2));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(0.4));
        RenderSimpleMesh(meshes["cylinder"], shaders["LabShader"], modelMatrix, mapTextures["white"]);
    }
    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 1.7, -2));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(0.4));
        RenderSimpleMesh(meshes["cylinder"], shaders["LabShader"], modelMatrix, mapTextures["grey"]);
    }


    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(1, 0.1, -2));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(0.05));
        RenderSimpleMesh(meshes["pluta"], shaders["LabShader"], modelMatrix, mapTextures["lemn"]);
    }

    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(1, 0.1, -2));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(0.05));
        RenderSimpleMesh(meshes["catarg"], shaders["LabShader"], modelMatrix, mapTextures["grey"]);
    }

    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(1, 0.1, -2));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(0.05));
        RenderSimpleMesh(meshes["steag"], shaders["LabShader"], modelMatrix, mapTextures["black30"]);
    }

    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(1, 0.1, -2));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(0.05));
        RenderSimpleMesh(meshes["panza"], shaders["LabShader"], modelMatrix, mapTextures["blue"]);
    }

   


    
}


void Lab9::FrameEnd()
{
    // DrawCoordinateSystem();
}


void Lab9::RenderSimpleMesh(Mesh *mesh, Shader *shader, const glm::mat4 & modelMatrix, Texture2D* texture1, Texture2D* texture2)
{
    if (!mesh || !shader || !shader->GetProgramID())
        return;

    // Render an object using the specified shader and the specified position
    glUseProgram(shader->program);

    // Bind model matrix
    GLint loc_model_matrix = glGetUniformLocation(shader->program, "Model");
    glUniformMatrix4fv(loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));

    // Bind view matrix
    glm::mat4 viewMatrix = GetSceneCamera()->GetViewMatrix();
    int loc_view_matrix = glGetUniformLocation(shader->program, "View");
    glUniformMatrix4fv(loc_view_matrix, 1, GL_FALSE, glm::value_ptr(viewMatrix));

    // Bind projection matrix
    glm::mat4 projectionMatrix = GetSceneCamera()->GetProjectionMatrix();
    int loc_projection_matrix = glGetUniformLocation(shader->program, "Projection");
    glUniformMatrix4fv(loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

    // TODO(student): Set any other shader uniforms that you need
    int loc_time = glGetUniformLocation(shader->program, "time");
    int loc_mix_value = glGetUniformLocation(shader->program, "mix_value");
    glUniform1i(loc_mix_value, 0);
    if (texture1)
    {
        // TODO(student): Do these:
        // - activate texture location 0
        // - bind the texture1 ID
        // - send theuniform value
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture1->GetTextureID());
        glUniform1i(glGetUniformLocation(shader->program, "texture_1"), 0);

    }

    if (texture2)
    {
        // TODO(student): Do these:
        // - activate texture location 1
        // - bind the texture2 ID
        // - send the uniform value
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture2->GetTextureID());
        glUniform1i(glGetUniformLocation(shader->program, "texture_2"), 1);

    }

    // Draw the object
    glBindVertexArray(mesh->GetBuffers()->m_VAO);
    glDrawElements(mesh->GetDrawMode(), static_cast<int>(mesh->indices.size()), GL_UNSIGNED_INT, 0);
}


Texture2D* Lab9::CreateRandomTexture(unsigned int width, unsigned int height)
{
    GLuint textureID = 0;
    unsigned int channels = 3;
    unsigned int size = width * height * channels;
    unsigned char* data = new unsigned char[size];

    // TODO(student): Generate random texture data
    for (int i = 0; i < size; i++) {
		data[i] = rand() % 256;
	}
    // TODO(student): Generate and bind the new texture ID
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    if (GLEW_EXT_texture_filter_anisotropic) {
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 4);
    }
    // TODO(student): Set the texture parameters (MIN_FILTER, MAG_FILTER and WRAPPING MODE) using glTexParameteri
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 4);

    glPixelStorei(GL_PACK_ALIGNMENT, 1);
    CheckOpenGLError();

    // Use glTexImage2D to set the texture data
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

    // TODO(student): Generate texture mip-maps
    glGenerateMipmap(GL_TEXTURE_2D);

    CheckOpenGLError();

    // Save the texture into a wrapper Texture2D class for using easier later during rendering phase
    Texture2D* texture = new Texture2D();
    texture->Init(textureID, width, height, channels);

    SAFE_FREE_ARRAY(data);
    return texture;
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void Lab9::OnInputUpdate(float deltaTime, int mods)
{
    if (!window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT))
    {
        glm::vec3 up = glm::vec3(0, 1, 0);
        glm::vec3 right = GetSceneCamera()->m_transform->GetLocalOXVector();
        glm::vec3 forward = GetSceneCamera()->m_transform->GetLocalOZVector();
        forward = glm::normalize(glm::vec3(forward.x, 0, forward.z));
    }
}


void Lab9::OnKeyPress(int key, int mods)
{
    // Add key press event
}


void Lab9::OnKeyRelease(int key, int mods)
{
    // Add key release event
}


void Lab9::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    // Add mouse move event
}


void Lab9::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button press event
}


void Lab9::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
}


void Lab9::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Lab9::OnWindowResize(int width, int height)
{
}
