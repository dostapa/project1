#include <GL/glut.h>
#include "shapes.h"

// Function to handle window resizing
void handleResize(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)width / (double)height, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

// Function to handle window drawing
void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -5.0f);

    // Rotate the cube
    static float angle = 0.0f;
    glRotatef(angle, 1.0f, 1.0f, 1.0f);
    angle += 0.035f;
    drawSphere();

    glutSwapBuffers();
}

// Idle function to continuously update the scene
void updateScene() {
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    // Initialize GLUT and create the window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Cube");

    // Enable depth testing
    glEnable(GL_DEPTH_TEST);

    // Set the callback functions
    glutReshapeFunc(handleResize);
    glutDisplayFunc(renderScene);
    glutIdleFunc(updateScene); // Register the idle function

    // Enter the GLUT event processing loop
    glutMainLoop();

    return 0;
}
