/*
 * NBody.h
 *
 *  Created on: Aug 10, 2012
 *      Author: Antoine Grondin
 */

#ifndef NBODY_H_
#define NBODY_H_

#include <iostream>
#include <string>
#include <GL/glew.h>
#include <GL/freeglut.h>

// Project libs
#include <GLTools.h>
#include <GLFrustum.h>
#include <GLMatrixStack.h>
#include <GLGeometryTransform.h>
#include <GLShaderManager.h>
#include <StopWatch.h>
#include <math3d.h>
// Local
#include "Constants.h"
#include "VectorMath.h"

const static bool D = DEBUG;

// Variables
// - Matrices and shaders
static GLShaderManager sShaderManager;
static GLFrustum sViewFrustrum;
static GLMatrixStack sProjectionMatrixStack;
static GLMatrixStack sModelViewMatrixStack;
static GLGeometryTransform sTransformPipeline;

////////////////////////////////////////////////////////////////////////
// MODELS
////////////////////////////////////////////////////////////////////////
static GLFrame sCameraFrame;

const static GLclampf sBackgroundColor[] = { 0.0f, 0.0f, 0.0f, 1.0f };
const static M3DVector4f sMainLightPos = { 0.0f, 10.0f, 5.0f, 1.0f };

static GLTriangleBatch sBodyBatch;
static GLFrame sBodyFrames[BODY_COUNT];
const static GLfloat sBodyRadius = 15.0f;

const static GLclampf sBodyColors[BODY_COUNT][4] = {
         {1.0f, 0.1f, 0.1f, 1.0f},  // Red
         {0.5f, 0.5f, 1.0f, 1.0f}   // Blue
};

static Position3D sBodyPosition[BODY_COUNT] = {
         { 0.0f, 0.0f, -1000.0f },
         { 0.0f, 200.0f, -1000.0f }
};
static Velocity3D sBodyVelocity[BODY_COUNT] = {
         { 0.0f, 0.0f, 0.0f },
         { -30.0f, 0.0f, 0.0f }
};
static Acceleration3D sBodyAcceleration[BODY_COUNT] = {
         { 0.0f, 0.0f, 0.0f },
         { 0.0f, 0.0f, 0.0f }
};
static GLfloat sBodyMass[BODY_COUNT] = {
         1e16f,
         1e1f
};


///////////////////////////////////////////////////////////////////////
// Methods
///////////////////////////////////////////////////////////////////////

// Setup
void setupWindow(int argc, char **argv);
void registerCallbacks();
void setupRenderContext();
void setupBodies();

// Callbacks
static void onChangeSize(int aNewWidth, int aNewHeight);
static void onRenderScene();
static void onMouseEvent(int key, int x, int y, int something);

// Drawing
static void drawBodies( CStopWatch *timeKeeper,
         M3DVector4f *lightPosition );

// Physics
static void updatePhysics(float deltaT);
static void updateAcceleration(int bodyIndex);
static void updateVelocity(int bodyIndex, float deltaT);
static void updatePosition(int bodyIndex, float deltaT);

// Misc
inline void printGreetings(){
   std::cout << APP_NAME << std::endl << APP_VERSION << std::endl;
}

#endif
