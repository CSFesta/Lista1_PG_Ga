#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

// Fun��o de callback para redimensionamento da janela
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int main()
{
    // Inicializa��o do GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Cria��o da janela GLFW
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Point", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Falha ao criar a janela GLFW" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Inicializa��o do GLAD para gerenciar ponteiros de fun��es OpenGL
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Falha ao inicializar o GLAD" << std::endl;
        return -1;
    }

    // Defini��o da viewport e registro de callback de redimensionamento
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Loop de renderiza��o
    while (!glfwWindowShouldClose(window))
    {
        // Limpa o buffer de cor
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Desenha o ponto
        float vertices[] = {
            0.0f, 0.0f // Define as coordenadas do ponto (x, y)
        };

        // Cria e configura o VAO e VBO
        GLuint VAO, VBO;
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // Desenha o ponto
        glDrawArrays(GL_POINTS, 0, 1);

        // Limpa o VAO e VBO
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);

        // Troca os buffers da janela
        glfwSwapBuffers(window);
        // Checa e processa eventos
        glfwPollEvents();
    }

    // Encerra GLFW e libera recursos
    glfwTerminate();
    return 0;
}

class main
{
};
