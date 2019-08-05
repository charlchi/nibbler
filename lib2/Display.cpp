
#include <iostream>
#include "GLFW/glfw3.h"
#include "IDisplay.hpp"
#include "SnakeGame.hpp"
#include "Display.hpp"

int Display::inputKey;

static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

void Display::handleInput(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS) {
        if (key == GLFW_KEY_ESCAPE) Display::inputKey = (0);
        if (key == GLFW_KEY_UP) Display::inputKey = (4);
        if (key == GLFW_KEY_DOWN) Display::inputKey = (5);
        if (key == GLFW_KEY_LEFT) Display::inputKey = (6);
        if (key == GLFW_KEY_RIGHT) Display::inputKey = (7);
        if (key == GLFW_KEY_1) Display::inputKey = (1);
        if (key == GLFW_KEY_2) Display::inputKey = (2);
        if (key == GLFW_KEY_3) Display::inputKey = (3);
    }
}

Display::Display(SnakeGame& s) : snakeref(s) {
    if (!glfwInit()) {}
    window = glfwCreateWindow(
        (snakeref.width+5)*10,
        (snakeref.height+5)*10,
        "SNAKE", NULL, NULL);
    if (!window) {}
    glfwSetErrorCallback(error_callback);
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, &Display::handleInput);
    glfwSwapInterval(1);
}

Display::~Display(void) {

}

void drawBox(int x, int y, int width, int height) {
    glBegin(GL_POINTS);//start drawing a line loop
    float x1 = (((float)x / (float)width/1.0f) * 2.0f) - 1.0f;
    float y1 = (((float)y / (float)height/1.0f) * 2.0f) - 1.0f;
    float hw = ((2.0f / (float)width/1.0f));
    float hh = ((2.0f / (float)height/1.0f));
    
    glVertex2f( x1+(hw/2.0f), y1+(hh/2.0f) );//left of window
    //glVertex2f( x1, y1 );//left of window
    //glVertex2f( x1+hw, y1 );//bottom of window
    //glVertex2f( x1+hw, y1+hh );//right of window
    //glVertex2f( x1, y1+hh );//top of window
    glEnd();//end drawing of line loop
}

void Display::tick(void) {

    glfwPollEvents();
    snakeref.key = Display::inputKey;

    int width = (snakeref.width+5) * 10;
    int height = (snakeref.height+5) * 10;
    glfwGetFramebufferSize(window, &width, &height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(25.0f);
    glColor3f( 1.0f, 1.0f, 1.0f );
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    
    for (int i=0; i < snakeref.width+2; i++) {
        drawBox(i, 0,
            snakeref.width+2, snakeref.height+2);
        drawBox(i, snakeref.height+1,
            snakeref.width, snakeref.height+2);
    }
    for (int i=0; i < snakeref.height+2; i++) {
        drawBox(0,i,
            snakeref.width+2, snakeref.height+2);
        drawBox(snakeref.width+1,i,
            snakeref.width+2, snakeref.height+2);
    }

    for (int i=0; i < snakeref.trail; i++){
        drawBox((snakeref.trailx[i]+1), snakeref.traily[i]+1,
            snakeref.width+2, snakeref.height+2);
    }

    drawBox((snakeref.ax+1), snakeref.ay+1,
            snakeref.width+2, snakeref.height+2);

    glfwSwapBuffers(window);
}

IDisplay* createLink(SnakeGame& s) {
    return new Display(s);
}

void destroyLink(IDisplay * g) {
    Display* ctx = (Display*)g;
    glfwSetWindowShouldClose(ctx->window, GLFW_TRUE);
    glfwDestroyWindow(ctx->window);
    glfwTerminate();
    delete g;
    //(void)g;
}
