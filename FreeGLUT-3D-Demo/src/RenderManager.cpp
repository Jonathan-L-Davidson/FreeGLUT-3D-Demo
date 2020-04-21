#include "GLUT.h"
#include "RenderManager.h"
#include "ObjectManager.h"
#include "MasterManager.h"
#include <iostream>

RenderManager::RenderManager(MasterManager* mstMgr, ObjectManager* objMgr) {
    m_masterManager = mstMgr;
    m_objectManager = objMgr;

    m_camera = mstMgr->GetCamera();
}

void RenderManager::Display()
{
    // Clear Color and Depth Buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    glLoadIdentity();

    // Set the camera
    gluLookAt(m_camera->x, 1.0f, m_camera->z,
        m_camera->x + m_camera->lx, 1.0f, m_camera->z + m_camera->lz,
        0.0f, 1.0f, 0.0f);

    glRotatef(m_camera->angle, 0.0f, 1.0f, 0.0f);

    glColor3f(0.5f, 0.5f, 0.5f);
    m_objectManager->DrawObjects();

    // Draw ground
    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_QUADS);
        glVertex3f(-100.0f, 0.0f, -100.0f);
        glVertex3f(-100.0f, 0.0f, 100.0f);
        glVertex3f(100.0f, 0.0f, 100.0f);
        glVertex3f(100.0f, 0.0f, -100.0f);
    glEnd();

    /*
    // Draw 36 SnowMen
    for (int i = -3; i < 3; i++)
        for (int j = -3; j < 3; j++) {
            glPushMatrix();
            glTranslatef(i * 10.0, 0, j * 10.0);
            drawSnowMan();
            glPopMatrix();
        }*/

    glutSwapBuffers();
}
