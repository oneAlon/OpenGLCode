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

void display() {
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);
    GLfloat vRed[] = {
        1.0f, 0.0f, 0.0f, 1.0f
    };
    
    shaderManager.UseStockShader(GLT_SHADER_IDENTITY, vRed);
    
    triangleBatch.Draw();
    
    glutSwapBuffers();
}

void setupRC() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    shaderManager.InitializeStockShaders();
    GLfloat vVerts[] = {
        -0.5f,0.0f,0.0f,
        0.5f,0.0f,0.0f,
        0.0f,0.5f,0.0f
    };
    triangleBatch.Begin(GL_TRIANGLES, 3);
    triangleBatch.CopyVertexData3f(vVerts);
    triangleBatch.End();
}

int main(int argc,char* argv[]) {
    gltSetWorkingDirectory(argv[0]);
    
    // 1. 初始化glut库
    glutInit(&argc, (char **)argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH|GLUT_STENCIL);
    
    // 2. 创建一个窗口
    glutInitWindowSize(800, 600);
    glutCreateWindow("这是我自定义的窗口");
    
    // 3. 注册函数
    glutDisplayFunc(display);
    
    // 设置渲染环境, 设置顶点
    setupRC();
    
    // 4. loop
    glutMainLoop();

    return 0;
}
