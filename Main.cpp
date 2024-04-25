#include <iostream>
#include <GLFW/glfw3.h>
#include <cmath> 


void exercicio5();
void exercicio6();

void exercicio5() {
    static int size = 3;
    float triangulo1[3][2]{ {-0.5,0.5}, {-0.5,-0.5} ,{0.5,0.5} };
    float triangulo2[3][2]{ {-0.5,-0.5}, {0.5,-0.5} ,{0.5,0.5} };

    glBegin(GL_TRIANGLES);
    for (const auto& i  : triangulo1) {
        glColor3f(1, 0, 0);
        glVertex2f(i[0],i[1]);

    }
    for (const auto& i : triangulo2) {
        glColor3f(0, 0, 1);
        glVertex2f(i[0], i[1]);

    }
    glEnd();
    glPointSize(10.0f);
    glBegin(GL_POINTS);
    for (const auto& i : triangulo1) {
        glColor3f(0, 1, 0);
        glVertex2f(i[0], i[1]);
    }
    for (const auto& i : triangulo2) {
        glColor3f(0, 1, 0);
        glVertex2f(i[0], i[1]);
    }
    glEnd();
    glBegin(GL_LINE_STRIP);

    for (int i = 0; i < size; i++) {
        glColor3f(1, 1, 1);
        glVertex2f(triangulo1[i % size][0], triangulo1[i % size][1]);
        glVertex2f(triangulo1[(i + 1) % size][0], triangulo1[(i + 1) % size][1]);

        glColor3f(1, 1, 1);
        glVertex2f(triangulo2[i % size][0], triangulo2[i % size][1]);
        glVertex2f(triangulo2[(i + 1) % size][0], triangulo2[(i + 1) % size][1]);
    }
    glEnd();
}

void exercicio6() {
    float posX = 1.0f, posY = 0.f; //0 - 1 
    float radius = 1.0f;
    const unsigned int qntPoints = 80; // qntPoints >= 3 
    const float angle = 3.14159 * 2.f / qntPoints;

    //criando circulo amarelo
    for (int i = 0; i <= qntPoints; i++) {      

            float newX = radius * std::sin(angle * i);
            float newY = -radius * std::cos(angle * i);

            glBegin(GL_TRIANGLES);

            glColor3f(1, 1, 0);

            glVertex2f(0, 0); // ponto inicial (centro)
            glVertex2f(posX, posY);
            glVertex2f(newX, newY);

            glEnd();
            posX = newX;
            posY = newY;
        
        
    }
    //contornando o circulo com preto
    for (int i = 0; i <= qntPoints-1; i++) {
       
        
        
        glBegin(GL_LINE_STRIP);

        glColor3f(0, 0, 0);

        glVertex2f(posX, posY);
        posX = radius * std::sin(angle * i);
        posY = -radius * std::cos(angle * i);
        glVertex2f(posX, posY);
        glEnd();
        
    }

    //criar a boca
    const float mouth_angle = 0.7;
    glColor3f(1.0f, 1.0f, 1.0f); // branco
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.0f); 
    glVertex2f(radius * cos(mouth_angle)*2, radius * sin(-mouth_angle)*2); // ponto inicial da boca
    glVertex2f(radius * cos(-mouth_angle)*2, radius * sin(mouth_angle)*2); // ponto final da boca
    glEnd();
    //contorno da boca
    glColor3f(0,0,0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(radius * cos(-mouth_angle), radius * sin(mouth_angle));
    glVertex2f(0,0);
    glVertex2f(radius * cos(mouth_angle), radius * sin(-mouth_angle));
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

        glClearColor(1,1,1,1); // R G B opacidade

        //exercicio5();
        exercicio6();


        // Trocar os buffers da janela
        glfwSwapBuffers(window);

        // Capturar eventos de entrada
        glfwPollEvents();
    }

    // Encerrar GLFW
    glfwTerminate();
    return 0;
}