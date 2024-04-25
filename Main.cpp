#include <GLFW/glfw3.h>

void drawTriangle() {

    static int size = 3;
    float triangulo1[3][2]{ {-0.5,0.5}, {-0.5,-0.5} ,{0.5,0.5} };
    float triangulo2[3][2]{ {-0.5,-0.5}, {0.5,-0.5} ,{0.5,0.5} };
    glPointSize(10.0f);

    glBegin(GL_POINTS);
    for (int i = 0; i < size; i++) {

        glColor3f(1, 1, 0);
        glVertex2f(triangulo1[i][0], triangulo1[i][1]);

        glColor3f(0, 1, 0);
        glVertex2f(triangulo2[i][0], triangulo2[i][1]);
    }
    glEnd();


}

int main() {
    // Inicializar GLFW
    if (!glfwInit())
        return -1;

    // Criar uma janela GLFW
    GLFWwindow* window = glfwCreateWindow(800, 600, "Triangulo", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // Definir o contexto OpenGL na janela atual
    glfwMakeContextCurrent(window);

    // Loop principal
    while (!glfwWindowShouldClose(window)) {
        // Limpar o buffer de cor
        glClear(GL_COLOR_BUFFER_BIT);

        // Desenhar o triângulo
        drawTriangle();

        // Trocar os buffers da janela
        glfwSwapBuffers(window);

        // Capturar eventos de entrada
        glfwPollEvents();
    }

    // Encerrar GLFW
    glfwTerminate();
    return 0;
}