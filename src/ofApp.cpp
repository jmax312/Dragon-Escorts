#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

/*The model used in this example was also made by the coder, Joni. 
It is based on the character Toothless, from the Dreamworks movie franchise, How to Train Your Dragon*/

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true); //this is so our picture refreshes with the monitor so parts don't lag behind
	ofSetFrameRate(120);
	finder.setup("haarcascade_frontalface_alt2.xml"); //this is a code that tells the program how to find a face 
	finder.setPreset(ObjectFinder::Fast); //this is how specific it will be in finding those faces
	finder.getTracker().setSmoothingRate(.3);
	cam.initGrabber(640, 480);

	ofDisableArbTex();
	ofEnableDepthTest(); //so that the back doesn't show through the front

	
	model.loadModel("toothless/Toothless.stl"); //now we load our models
	model2.loadModel("toothless/Toothless.stl");
	model3.loadModel("toothless/Toothless.stl");

	ofEnableAlphaBlending();
	//light.enable;
}

//--------------------------------------------------------------
void ofApp::update(){
	cam.update();
	if(cam.isFrameNew()) { //if the image from the camera has changed (like when the face moves), update it
		finder.update(cam);
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	cam.draw(0, 0);

	//try making float for flight
	
	for(int i = 0; i < finder.size(); i++) {
		//ofSetColor(200, 100, 255, 255);
		ofRectangle object = finder.getObjectSmoothed(i);
		float scaleAmount = .85;
		ofPushMatrix();
		model.setPosition(object.x + object.width / 1.5, object.y + object.height * .02, 10); //this sets the dragon on the top of your head
		model.setScale(scaleAmount, scaleAmount, scaleAmount);
		model.setRotation(0, 90, 0, 90, 0); //this makes sure he's facing the front
		model.drawFaces();
		model2.setPosition(object.x + object.width - 300, object.y + object.height * 1.2, 25); //this sets the dragon near your shoulder
		model2.setScale(scaleAmount, scaleAmount, scaleAmount);
		model2.setRotation(0, 180, 0, 90, 0); //this makes sure he's facing the side
		model2.drawFaces();
		model3.setPosition(object.x + object.width + 150, object.y + object.height * 1.2, 10); //this sets the dragon near your shoulder
		model3.setScale(scaleAmount, scaleAmount, scaleAmount);
		model3.setRotation(0, 10, 0, 10, 0); //this makes sure he's facing the side
		model3.drawFaces();
		ofPopMatrix();
		ofPushMatrix();
		ofTranslate(object.getPosition());
		ofDrawBitmapStringHighlight(ofToString(finder.getLabel(i)), 0, 0); //this is counting and showing the number of faces the camera has seen
		ofLine(ofVec2f(), toOf(finder.getVelocity(i)) * 10);
		ofPopMatrix();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
