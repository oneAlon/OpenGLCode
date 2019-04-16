//
//  main.cpp
//  OpenGLESDemo
//
//  Created by xygj on 2019/4/2.
//  Copyright © 2019 OneAlon. All rights reserved.
//

#include <stdio.h>

#include "GLShaderManager.h"
#include "GLTools.h"
#include <glut/glut.h>
#include <GLUT/GLUT.h>

// 着色管理器
GLShaderManager shaderManager;

//简单的批次容器，是GLTools的一个简单的容器类。
GLBatch triangleBatch;

void changeSize(int w,int h) {
    glViewport(0, 0, w, h);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    // 颜色
    GLfloat vRed[] = {
      1.0f, 0.0f, 0.0f, 1.0f
    };
    shaderManager.UseStockShader(GLT_SHADER_IDENTITY, vRed);
    
    triangleBatch.Draw();
    
    glutSwapBuffers();
}

// 进行初始化的设置, CPU
void setupRC() {
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    // 初始化着色管理器
    shaderManager.InitializeStockShaders();
    
    // 设置三角形批次容器的值.
    GLfloat vTriangleVert[] = {
        -0.5f, 0.0f, 0.0f,
        0.0f, 0.5f, 0.0f,
        0.5f, 0.0f, 0.0f,
    };
    triangleBatch.Begin(GL_TRIANGLE_FAN, 3);
    triangleBatch.CopyVertexData3f(vTriangleVert);
    triangleBatch.End();
}

int main(int argc,char* argv[]) {
    gltSetWorkingDirectory(argv[0]);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH|GLUT_STENCIL);
    
    // 2. 创建一个窗口
    glutInitWindowSize(800, 600);
    glutCreateWindow("这是我自定义的窗口");
    
    // 3. 注册函数
    glutReshapeFunc(changeSize);
    glutDisplayFunc(display);
    
    setupRC();
    
    // 4. loop
    glutMainLoop();

    return 0;
}
