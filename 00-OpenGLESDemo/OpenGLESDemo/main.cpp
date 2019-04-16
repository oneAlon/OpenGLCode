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
    
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    // 设置绘制的属性
    glColor3f(1.0f, 0.0f, 0.0f);
    glLineWidth(5.0f);
    
    glBegin(GL_LINE_LOOP);
    // 设置顶点
    glVertex3f(-0.5f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.5f, 0.0f);
    glVertex3f(0.5f, 0.0f, 0.0f);
    glEnd();
    
    glFlush();
    
}

int main(int argc,char* argv[]) {
    
    // 1. 初始化glut库
    glutInit(&argc, (char **)argv);
    
    // 2. 创建一个窗口
//    glutInitWindowSize(800, 600);
    glutCreateWindow("这是我自定义的窗口");
    
    // 3. 注册函数
    glutDisplayFunc(display);
    
    // 4. loop
    glutMainLoop();

    return 0;
}
