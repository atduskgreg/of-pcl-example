#include "testApp.h"

using namespace ofxPCL;

//--------------------------------------------------------------
void testApp::setup()
{

    PointCloud bunny = loadPointCloud<PointCloud>("bunny.pcd");    
    convert(bunny, mesh);
    
    /*PointNormalPointCloud normalBunny = create<PointNormalPointCloud>();
    
    normalEstimation(bunny, normalBunny);
    triangulatedMesh = triangulate(normalBunny,30); // default search radius of 30
    */
    
    currentMode = POINTS;
}

//--------------------------------------------------------------
void testApp::update()
{

}

//--------------------------------------------------------------
void testApp::draw()
{
    ofBackground(0);
    
    cam.begin();
    ofScale(1000, 1000, 1000);
    ofSetColor(125);
    
    if(currentMode == POINTS){
        mesh.drawVertices();
    }
    
    if(currentMode == TRIANGULATED){
        triangulatedMesh.drawWireframe();
    }
    if(currentMode == MARCHING_CUBES){
        marchingSquaresMesh.drawWireframe();   
    }
        
    cam.end();
    
    ofSetColor(255);
    stringstream c;
    c << "FPS: " << ofGetFrameRate() << endl;
    
    string modeNames[3] = {"POINTS", "TRIANGULATED", "MARCHING_CUBES"};
    
    c << "Current Mode: " << modeNames[currentMode] << endl;
    ofDrawBitmapString(c.str(), 15, 15);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
    currentMode++;
    
    if(currentMode > MARCHING_CUBES){
        currentMode = POINTS;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y)
{

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo)
{

}