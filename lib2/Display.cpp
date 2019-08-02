
#include <iostream>
#include "GLFW/glfw3.h"
#include "IDisplay.hpp"
#include "SnakeGame.hpp"
#include "Display.hpp"

static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

Display::Display(SnakeGame& s) : snakeref(s) {
    if (!glfwInit()) {}
    window = glfwCreateWindow(
        snakeref.width*10,
        snakeref.height*10,
        "SNAKE", NULL, NULL);
    if (!window) {}
    glfwSetErrorCallback(error_callback);
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
    glfwSwapInterval(1);
}

Display::~Display(void) {

}

void drawBox(int x, int y, int width, int height) {
    glBegin(GL_POLYGON);//start drawing a line loop
    float x1 = (((float)x / (float)width/2.0f) * 2.0f) - 1.0f;
    float y1 = (((float)y / (float)height/2.0f) * 2.0f) - 1.0f;
    float hw = ((2.0f / (float)width/2.0f));
    float hh = ((2.0f / (float)height/2.0f));
    glVertex2f( x1, y1 );//left of window
    glVertex2f( x1+hw, y1 );//bottom of window
    glVertex2f( x1+hw, y1+hh );//right of window
    glVertex2f( x1, y1+hh );//top of window
    glEnd();//end drawing of line loop
}

void Display::tick(void) {

    int width = (snakeref.width) * 10;
    int height = (snakeref.height) * 10;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f( 1.0f, 1.0f, 1.0f );
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    
    for (int i=0; i < snakeref.width+2; i++) {
        drawBox(i, 0, snakeref.width+2, snakeref.height+2);
        drawBox(i, snakeref.height+2, snakeref.width, snakeref.height+2);
    }
    for (int i=0; i < snakeref.height+2; i++) {
        drawBox(0,i, snakeref.width+2, snakeref.height+2);
        drawBox(snakeref.width+2,i, snakeref.width+2, snakeref.height+2);
    }

    glfwSwapBuffers(window);
    glfwPollEvents();

}

IDisplay* createLink(SnakeGame& s) {
    return new Display(s);
}

void destroyLink(IDisplay * g) {
    Display* ctx = (Display*)g;
    glfwDestroyWindow(ctx->window);
    glfwTerminate();
    (void)g;
}
