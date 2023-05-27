#include <GL/glut.h>
#include <cmath>
void drawPlane(){
    const float size = 2.0f;

    glBegin(GL_QUADS);
    glNormal3f(0.0f, 1.0f, 0.0f);

    glVertex3f(-size, 0.0f, -size);
    glVertex3f(-size, 0.0f, size);
    glVertex3f(size, 0.0f, size);
    glVertex3f(size, 0.0f, -size);

    glEnd();
}
void drawCube(){
    glBegin(GL_QUADS);

    // Front face
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);

    // Back face
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);

    // Left face
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);

    // Right face
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);

    // Top face
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);

    // Bottom face
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    glEnd();
}
void drawSphere(){
    const float radius = 1.0f;
    const int stacks = 20;
    const int slices = 20;

    for (int i = 0; i < stacks; ++i) {
        float latitude1 = static_cast<float>(M_PI * (static_cast<float>(i) / stacks));
        float latitude2 = static_cast<float>(M_PI * (static_cast<float>(i + 1) / stacks));
        float sinLat1 = sin(latitude1);
        float cosLat1 = cos(latitude1);
        float sinLat2 = sin(latitude2);
        float cosLat2 = cos(latitude2);

        glBegin(GL_QUAD_STRIP);
        for (int j = 0; j <= slices; ++j) {
            float longitude = static_cast<float>(2 * M_PI * (static_cast<float>(j) / slices));
            float sinLong = sin(longitude);
            float cosLong = cos(longitude);

            float x1 = cosLong * sinLat1;
            float y1 = cosLat1;
            float z1 = sinLong * sinLat1;
            float x2 = cosLong * sinLat2;
            float y2 = cosLat2;
            float z2 = sinLong * sinLat2;

            glNormal3f(x2, y2, z2);
            glColor3f(sinLat1,cosLat1, tan(latitude1));
            glVertex3f(radius * x2, radius * y2, radius * z2);

            glNormal3f(x1, y1, z1);
            glColor3f(sinLat2,cosLat2, tan(latitude2));
            glVertex3f(radius * x1, radius * y1, radius * z1);
        }
        glEnd();
    }
}
void drawPyramid(){
    glBegin(GL_TRIANGLES);

    // Front face
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);

    // Left face
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);

    // Right face
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    // Back face
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    glEnd();
}